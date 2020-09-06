#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;
    vector<int> nums(N + 1, 0);
    for (int i = 0; i < N; ++i){
        cin >> nums[i + 1];
    }
    vector<long long> L(N + 1, 0);
    vector<long long> R(N + 1, 0);
    stack<int> q;
    q.push(1);
    for (int i = 2; i <= N; ++i){
        while (q.size() > 0 && nums[i] > nums[q.top()]){
            R[q.top()] = i;
            q.pop();
        }
        q.push(i);
    }
    q = stack<int>();
    q.push(N);
    for (int i = N - 1; i >= 1; --i){
        while (q.size() && nums[i] > nums[q.top()]){
            L[q.top()] = i;
            q.pop();
        }
        q.push(i);
    }
    long long res = 0;
    for (int i = 1; i <= N; ++i){
        res = max(res, L[i] * R[i]);
    }
    cout << res << endl;
    return 0;
}
