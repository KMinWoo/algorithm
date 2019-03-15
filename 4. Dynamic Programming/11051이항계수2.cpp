#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int dp[1001][1001] = { 0, };

int sol(int n, int k) {
	int ref = 0;
	
	if (n < 0) return 0;
	if (k > n || k < 0) return 0;

	if (dp[n][k] != 0) return dp[n][k] % 10007;

	dp[n][k] = sol(n - 1, k - 1) + sol(n - 1, k);

	return dp[n][k] % 10007;
}


int main() {
	int n,k;

	cin >> n >> k;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	printf("%d", sol(n, k));

	return 0;
}

