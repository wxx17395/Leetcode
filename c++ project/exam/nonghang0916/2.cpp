#include <bits/stdc++.h>
using namespace std;

vector<double> func(double P, double N, double R){
    vector<double> res;
    double cur, sum = 0;
    double div = P / N;
    for (int k = 0; k < N; ++k){
        cur = div + (P - div * k) * R;
        cur = int(cur * 100 + 0.5);
        cur /= 100;
        res.push_back(cur);
    }
    return res;
}

int main()
{
    vector<double> a = func(1000000,7,0.003959);
    for (int i = 0; i < a.size(); ++i){
        cout << fixed << setprecision(2) << a[i] << endl;
    }
    return 0;
}
