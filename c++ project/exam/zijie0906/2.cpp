#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> nums;
    if (M > 1) nums.resize(N * 2);
    else nums.resize(N);
    for (int i = 0; i < N; ++i){
        cin >> nums[i];
        if (M > 1) nums[N + i] = nums[i];
    }
    int sum = 0, left = 0, result = INT_MIN;
    int maxl = 0, maxr = 0;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        if (sum > result){
            maxl = left;
            maxr = right;
            result = sum;
        }
        while (left <= right && sum <= 0) {
            sum -= nums[left];
            left++;
        }
    }
    if (M <= 2){
        cout << result << endl;
    } else {
        if (result < 0){
            cout << result << endl;
        } else {
            int dif = maxr - maxl + 1;
            if (dif == 2 * N){
                cout << result / 2 * M << endl;
            } else if (dif < N){
                cout << result << endl;
            } else {
                int cur = result;
                for (int i = maxr; i > N; --i){
                    cur -= nums[i];
                }
                result += cur * (M - 2);
                cout << result << endl;
            }
        }
        
    }
    return 0;
}
