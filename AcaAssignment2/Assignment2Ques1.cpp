#include <bits/stdc++.h>
using namespace std;

long long int countWaysToMakeSum(vector<int> &coins, int N, int sum) {
    vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1, 0));

    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i-1] <= j) {
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][sum];
}

int main() {
    int N, sum;
    cin >> N >> sum;
    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    
    cout << countWaysToMakeSum(coins, N, sum) << endl;

    return 0;
}
