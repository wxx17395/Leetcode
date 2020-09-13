#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param preOrder int整型vector the array1
     * @param inOrder int整型vector the array2
     * @return int整型vector
     */
    int n;
    vector<int> res;
    void partition(vector<int>& preOrder, vector<int>& inOrder, int pstart, int pend, int instart, int inend){
        if (pstart == pend){
            res.push_back(preOrder[pstart]);
            return;
        }
        if (pstart > pend){
            return;
        }
        int root = preOrder[pstart];
        int l = instart;
        for (; l < inend; ++l){
            if (inOrder[l] == root) break;
        }
        partition(preOrder, inOrder, pstart + 1, pstart + l - instart, instart, l - 1);
        partition(preOrder, inOrder, pstart + l - instart + 1, pend, l + 1, inend);
        res.push_back(root);
        return;
    }
    
    vector<int> findOrder(vector<int>& preOrder, vector<int>& inOrder) {
        // write code here
        n = preOrder.size();
        res.resize(n);
        partition(preOrder, inOrder, 0, n - 1, 0, n - 1);
        return res;
    }
};

int main()
{
    
    return 0;
}
