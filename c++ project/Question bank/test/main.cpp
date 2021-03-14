#include <bits/stdc++.h>
using namespace std;

long long max3(long a, long b, long c){
    if (a > b && a > c){
        return a;
    }
    if (b > a && b > c){
        return b;
    }
    if (c > a && c > b){
        return c;
    }
}

int main(int argc, char const *argv[])
{
    long long a, b, c;
    cin >> a >> b >> c;
    double na = max3(a + b, b, c);
    double nb = max3(a, b + c, c);
    double nc = max3(a, b, b + c);
    double m = na / (nb + nc);
    printf("%.2lf", m);
    return 0;
}

