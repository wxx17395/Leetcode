#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MUL = 1, SUB = 2, DIV = 3;
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> l;
        for (const int &num : nums){
            l.push_back(static_cast<double>(num));
        } 
        return solve(l);
    }
    
    bool solve(vector<double> &l){
        if (l.size() == 0){
            return false;
        }
        if (l.size() == 1){
            return fabs(l[0] - TARGET) < EPSILON;
        }
        int size = l.size();
        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                if (i == j) continue;
                vector<double> l2;
                for (int k = 0; k < size; ++k){
                    if (k != i && k != j){
                        l2.push_back(l[k]);
                    }
                }
                for (int k = 0; k < 4; ++k){
                    if (k < 2 && i > j){
                        continue;
                    }
                    if (k == ADD){
                        l2.push_back(l[i] + l[j]);
                    } else if (k == MUL){
                        l2.push_back(l[i] * l[j]);
                    } else if (k == SUB){
                        l2.push_back(l[i] - l[j]);
                    } else if (k == DIV){
                        if (fabs(l[j]) < EPSILON){
                            continue;
                        }
                        l2.push_back(l[i] / l[j]);
                    }
                    if (solve(l2)){
                        return true;
                    }
                    l2.pop_back();
                }

            }
        }
        return false;
    }
};

int main()
{
    
    return 0;
}
