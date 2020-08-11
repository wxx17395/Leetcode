#include <bits/stdc++.h>
using namespace std;




int main()
{
   int n, m;
   cin >> n >> m;
   vector<vector<char>> grid(n, vector<char>(n));
   vector<string> words(m);
   for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
         cin >> grid[i][j];
      }
   }
   for (int i = 0; i < m; ++i){
      cin >> words[i];
   }
   sort(words.begin(), words.end());
   unordered_map<char, int> mp;
   for (int i = 0; i < n; ++i){
      mp[words[i][0]]++;
   }
   
   return 0;
}
