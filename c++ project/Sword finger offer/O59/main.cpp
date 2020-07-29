#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int m = nums.size(), maxIndex = -1;
        vector<int> res;
        if (m == 0) return res;
        for (int i = 0; i <= m - k; ++i){
            if (maxIndex < i){
                maxIndex = findMax(nums, k, i);
            }else if (nums[maxIndex] < nums[i + k - 1]){
                maxIndex = i + k - 1;
            }
            res.push_back(nums[maxIndex]);
        }
        return res;
    }

private:
    int findMax(vector<int> &nums, int k, int i){
        int max = i;
        for (int j = i + 1; j < i + k; ++j){
            if (nums[max] < nums[j]){
                max = j;
            }
        }
        return max;
    }
};*/

// 59 - 1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        if (nums.empty()) return res;
        for(int i = 0; i < k; ++i){
            while(!q.empty() && nums[i] > q.back()){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        res.push_back(q.front());
        for(int i = k; i < nums.size(); ++i){
            if (q.front() == nums[i - k]) q.pop_front();
            while (!q.empty() && nums[i] > q.back()){
                q.pop_back();
            }
            q.push_back(nums[i]);
            res.push_back(q.front());
        }
        return res;
    }
};

// 59 - 2
class MaxQueue {
private:
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }

    int max_value() {
        if (d.empty()){
            return -1;
        }
        return d.front();
    }

    void push_back(int value) {
        while (!d.empty() && d.back() < value){
            if (d.front() < value){
                d.clear();
            }else{
                d.pop_back();
            }
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()){
            return -1;
        }
        int res = q.front();
        if (res == d.front()){
            d.pop_front();
        }
        q.pop();
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution().maxSlidingWindow(nums, 3);
    return 0;
}
