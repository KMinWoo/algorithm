#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
long long dp[101][10];
int main() {

	int n;
	int i, j;
	long long sum = 0;
	cin >> n;
	for (i = 1; i <= 9; i++) dp[1][i] = 1;

	for (i = 2; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			if(j == 0)	dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % 1000000000;
		}
	}
	for (i = 0; i <= 9; i++) sum = (sum + dp[n][i]) % 1000000000;
	
	printf("%d", sum);
	return 0;
}

