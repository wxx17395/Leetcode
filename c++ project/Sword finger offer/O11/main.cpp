#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while (i < j){
            int mid = i + (j - i) / 2;
            if (numbers[mid] < numbers[j]){
                j = mid;
            } else if (numbers[mid] > numbers[j]) {
                i = mid + 1;
            }  else{
                --j;
            }
        }
        return numbers[i];
    }
};

int main() {
    vector<int> nums{3,4,5,1,2,2,2,2,2,2};
    cout << Solution().minArray(nums) << endl;
    return 0;
}
