#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
long long dp[100];
int main() {

	int n;

	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]);
	}
	printf("%lld", dp[n]);
	return 0;
}

