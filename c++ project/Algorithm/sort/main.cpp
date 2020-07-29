#include <bits/stdc++.h>
using namespace std;

class Heapsort{
public:
    void sort(vector<int> &nums){
        int n = nums.size();
        for (int k = n / 2; k >= 0; --k){
            sink(nums, k ,n);
        }
        for (int j = n - 1; j > 0; --j){
            swap(nums[0], nums[j]);
            sink(nums, 0, j);
        }
    }

private:
    void sink(vector<int> &nums, const int root, const int length){
        int child = root * 2 + 1;
        if (child < length){
            if (child + 1 < length && nums[child + 1] > nums[child]){
                ++child;
            }
            if(nums[root] < nums[child]){
                swap(nums[root], nums[child]);
                sink(nums, child, length);
            }
        }
    }
};

class Quicksort{
public:
    void sort(vector<int> &nums){
        int n = nums.size() - 1;
        partition(nums, 0, n);
    }

private:
    void partition(vector<int> &nums, int l, int r){
        int i = l, j = r;
        if ( i >= j ){
            return;
        }
        int k = nums[l];
        while ( i < j ){
            while ( i < j && k <= nums[j]){
                --j;
            }
            nums[i] = nums[j];
            while ( i < j && k >= nums[i]){
                ++i;
            }
            nums[j] = nums[i];
        }
        nums[i] = k;
        partition(nums, l, i - 1);
        partition(nums, i + 1, r);
    }
};

class Mergesort{
public:
    void sort(vector<int> &nums){
        vector<int> tmp(nums.size(), 0);
        merge(nums, tmp, 0, nums.size() - 1);
    }

private:
    void merge(vector<int> &nums, vector<int> &tmp, int start, int end){
        if (start >= end){
            return;
        }
        int len = end - start, mid = start + len / 2;
        int start1 = start, end1 = mid;
        int start2 = mid + 1, end2 = end;
        merge(nums, tmp, start1, end1);
        merge(nums, tmp, start2, end2);
        int k = start;
        while (start1 <= end1 && start2 <= end2){
            if (nums[start1] < nums[start2]){
                tmp[k++] = nums[start1++];
            }else{
                tmp[k++] = nums[start2++];
            }
        }
        while (start1 <= end1){
            tmp[k++] = nums[start1++];
        }
        while (start2 <= end2){
            tmp[k++] = nums[start2++];
        }
        for (k = start; k <= end; ++k){
            nums[k] = tmp[k];
        }
    }
};

int main() {
    vector<int> nums = {12,45,748,56,3,89,12,45,4,48,2};
    Mergesort s;
    s.sort(nums);
    for (auto i : nums){
        cout << i << endl;
    }
    return 0;
}
