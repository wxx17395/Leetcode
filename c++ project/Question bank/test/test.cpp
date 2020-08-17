#include <bits/stdc++.h>
using namespace std;

int main()
{
   int nums[7] = {0,1,2,3,4,5,6};
   int *num = nums + 2;
   cout << num[0] << endl;
   cout << num[-1] << endl;
   cout << num[-2] << endl;
   cout << num[-3] << endl;
   return 0;
}