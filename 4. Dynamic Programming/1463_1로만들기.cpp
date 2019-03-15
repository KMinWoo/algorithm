#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[1000001];

int sol(int n) {
	int ref = 1000000 - 1;

	if (dp[n] != 1000000) return dp[n];

	if (n % 3 == 0) ref = sol(n / 3);
	else if (n % 2 == 0) ref = sol(n / 2);
	dp[n] = min(sol(n - 1) + 1, ref + 1);

	return dp[n];
}



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		dp[i] = 1000000;
	}
	dp[1] = 0;
	printf("%d",sol(n));

	return 0;
}