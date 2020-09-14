#include <bits/stdc++.h>
using namespace std;

struct node{
    int i, j, k;
};



int main()
{
    int n;
    cin >> n;
    vector<node> vec(n);
    for (int i = 0; i < n; ++i){
        vec[i].i = i + 1;
        cin >> vec[i].j >>vec[i].k;
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if (vec[j].k < vec[j + 1].k){
                swap(vec[j], vec[j + 1]);
            }
            if (vec[j].k == vec[j + 1].k && vec[j].j < vec[j + 1].j){
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; ++i){
        cout << vec[i].i;
        if (i < n - 1) cout << ' ';
    }
    return 0;
}