#include <bits/stdc++.h>
#include <stdio.h>
#include <pthread.h>
using namespace std;

#define LL_ADD(item, list) do { \
    item->prev = NULL;          \
    item->next = list;          \
    if(list != NULL) list->prev = item;          \
    list = item;                \
} while (0);

#define LL_REMOVE(item, list) do{   \
    if (item->prev != NULL) item->prev->next = item->next;  \
    if (item->next != NULL) item->next->prev = item->prev;  \
    if (list == item) list = item->next;    \
    item->prev = item->next = NULL; \
} while (0);

struct NMANAGER;

struct NWORKER{
    pthread_t *thread;
    NMANAGER* pool;
    int terminate;

    NWORKER* prev;
    NWORKER* next;
};

struct NJOB{
    void* user_data;
    void (*func)(void* user_data);
    NJOB* prev;
    NJOB* next;
};

struct NMANAGER{
    NWORKER* workers;
    NJOB *jobs;

    pthread_cond_t jobs_cond; // 等待条件
    pthread_mutex_t jobs_mutex; // 查询任务的锁
};

typedef NMANAGER nThreadPool;

static void* nThreadCallback(void* arg){
    NWORKER* worker = (NWORKER*) arg;
    while (1){
        pthread_mutex_lock(&worker->pool->jobs_mutex);
        while (worker->pool->jobs == NULL){
            if (worker->terminate) break;
            pthread_cond_wait(&worker->pool->jobs_cond, &worker->pool->jobs_mutex);
        }
        if (worker->terminate){
            pthread_mutex_unlock(&worker->pool->jobs_mutex);
            break;
        }
        NJOB* job = worker->pool->jobs;
        LL_REMOVE(job, worker->pool->jobs);

        pthread_mutex_unlock(&worker->pool->jobs_mutex);

        job->func(job->user_data);
    }
    free(worker);
    pthread_exit(NULL);
    return 0;
}

int nThreadPoolCreate(nThreadPool* pool, int numWorkers){
    if (numWorkers < 1){
        numWorkers = 1;
    }
    if (pool == NULL){
        return -1;
    }
    memset(pool, 0, sizeof(nThreadPool));

    pthread_cond_t blank_cond = PTHREAD_COND_INITIALIZER;
    memcpy(&pool->jobs_cond, &blank_cond, sizeof(pthread_cond_t));

    pthread_mutex_t blank_mutex = PTHREAD_MUTEX_INITIALIZER;
    memcpy(&pool->jobs_mutex, &blank_mutex, sizeof(pthread_mutex_t));

    int i = 0;
    for (int i = 0; i < numWorkers; ++i){
        NWORKER* worker = (NWORKER*)malloc(sizeof(NWORKER));
        if (worker == NULL){
            perror("malloc");
            return -2;
        }
        memset(worker, 0, sizeof(NWORKER));
        worker->pool = pool;

        int ret = pthread_create(worker->thread, NULL, nThreadCallback, worker);
        if (ret){
            perror("pthread_create");
            free(worker);
            return -3;
        }
        LL_ADD(worker, pool->workers);
    }
    return 0;
}

void nThreadPoolPush(nThreadPool* pool, NJOB* job){
//    cout << "in job: " << *(reinterpret_cast<int*>(job->user_data)) <<endl;
    pthread_mutex_lock(&pool->jobs_mutex);
    LL_ADD(job, pool->jobs);
    pthread_cond_signal(&pool->jobs_cond);
    pthread_mutex_unlock(&pool->jobs_mutex);
}

void nThreadPoolDestroy(nThreadPool* pool){
    NWORKER* worker = NULL;
    for (worker = pool->workers; worker != NULL; worker = worker->next){
        worker->terminate = 1;
    }
    pthread_mutex_lock(&pool->jobs_mutex);
    pthread_cond_broadcast(&pool->jobs_cond);
    pthread_mutex_unlock(&pool->jobs_mutex);
}

#if 1 // debug
void myfunc(void* user_data){
    printf("i = %d\n", *(int *) user_data);
}

int main(){
    nThreadPool* pool = new nThreadPool();
    nThreadPoolCreate(pool, 1000);
    static int a[1000];
    for (int i = 0; i < 1000; ++i){
        a[i] = i;
    }
    for (int i = 0; i < 1000; ++i){
        NJOB* job = new NJOB();
        job->func = myfunc;
        //job->user_data = (int *)malloc(sizeof(int));
        job->user_data = (void *)(a + i);
        nThreadPoolPush(pool, job);
    }
    nThreadPoolDestroy(pool);
    delete pool;
}

#endif