#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9+7;

long long ans = 1;

long long helper(long n) {
	int res = 1;
	while (n) {
		res *= n;
		--n;
	}
	return res;
}

long long comm(long all, long choice) {
	if (all == choice) {
		return 1;
	}
	if ((choice << 1) > all) {
		choice = all - choice;
	}
	return helper(all) / helper(choice) / helper(all - choice);
}

int main() {
	int N;
	cin >> N;
    int tmp;
	vector<int> counters(N, 0);
	int depth = 0;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		counters[tmp]++;
		depth = max(tmp, depth);
	}
    bool flag = true;
    if (counters[0] != 1){
        flag = false;
    } else {
        for (int i = 1; i <= depth; ++i) {
            int all = 2 * counters[i-1];
            if (all < counters[i]){
                flag = false;
                break;
            }
            ans = max(comm(all, counters[i]), ans);
	    }
    }
	if (flag){
        cout << ans % MOD << endl;
    } else {
        cout << 0 << endl;
    }
	
	return 0;
}