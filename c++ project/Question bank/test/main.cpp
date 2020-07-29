#include <bits/stdc++.h>
#include "my_unordered_mp.h"
using namespace std;

class test{
public:
    vector<int> findMax(vector<int> nums){
        stack<int> s;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i){
            while (!s.empty() && nums[i] > nums[s.top()]){
                res.push_back(i);
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

int main(){
    int a = 1;
    char* ret = (char *)&a;

    if (*ret == 1)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
};