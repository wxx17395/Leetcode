#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool check(vector<int>& postorder, int l, int r){
        if (l >= r) return true;
        int root = postorder[r];
        int i = l, mid;
        while (i < r && postorder[i] < root){
            ++i;
        } 
        mid = i;
        while (i < r){
            if (postorder[i++] <= root){
                return false;
            }
        }
        return check(postorder, l, mid - 1) && check(postorder, mid, r - 1);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true;
        return check(postorder, 0, postorder.size() - 1);        
    }
};

int main()
{
    vector<int> nums{1,2,5,10,6,9,4,};
    cout << Solution().verifyPostorder(nums) << endl;
    return 0;
}
