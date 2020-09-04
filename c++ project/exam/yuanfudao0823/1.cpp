#include <bits/stdc++.h>
using namespace std;

int flag = 1;
int n;
int main(){
    int sum = 0;
    cin >> n;
    vector<vector<int>> input;
    vector<int> tmp;
    while (n--){
        int i;
        cin >> i;
        tmp.push_back(i);
        if (tmp.size() == flag){
            input.push_back(tmp);
            flag *= 2;
            tmp.clear();
        }
    }
    vector<int> res;
    for (int i = 0; i < input.size(); i++){
        res.push_back(input[i][0]);
    }
    for (int i = 1; i < input.back().size(); i++){
        res.push_back(input.back()[i]);
    }
    for (int i = input.size()-2; i > 0; i--){
        res.push_back(input[i].back());
    }
    for (int i = 0; i < res.size(); i++){
        cout << res[i];
        if (i != res.size()-1) cout << " ";
    }
    return 0;
}