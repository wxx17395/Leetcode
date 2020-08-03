#include <bits/stdc++.h>
using namespace std;

int cmp(int a , int b){
    return a / 10 - b / 10;
}

void test(vector<vector<int>> &array){
    map<string, int> mp;
    for (int i = 0; i <array.size(); ++i){
        vector<int> tmp;
        if (array[i][0] < array[i][1]){
            tmp.push_back(array[i][0] * 10 + array[i][1]);
        }else{
            tmp.push_back(array[i][1] * 10 + array[i][0]);
        }

        if (array[i][2] < array[i][3]){
            tmp.push_back(array[i][2] * 10 + array[i][3]);
        }else{
            tmp.push_back(array[i][3] * 10 + array[i][2]);
        }

        if (array[i][4] < array[i][5]){
            tmp.push_back(array[i][4] * 10 + array[i][5]);
        }else{
            tmp.push_back(array[i][5] * 10 + array[i][4]);
        }

        sort(tmp.begin(), tmp.end(), cmp);
        
        string str = "";
        for (int i = 0; i < 3; ++i){
            str += tmp[i] + ",";
        }

        ++mp[str];

    }
    cout << mp.size() << endl;
    vector<int> vecmp;
    for (auto m : mp){
        vecmp.push_back(m.second);
    }
    sort(vecmp.begin(), vecmp.end());
    for (auto n : vecmp){
        cout << n << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> array(n, vector<int>(6));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 6; ++j){
            cin >> array[i][j];
        }
    }
    test(array);
    return 0;
}
