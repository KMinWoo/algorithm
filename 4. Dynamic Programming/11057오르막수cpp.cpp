#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
long long dp[1001][10];
int sum(int x, int y) {
	int sum = 0;
	for (int i = y; i < 10; i++) {
		sum += dp[x][i];
	}
	return sum % 10007;
}

int main() {
	int n;
	int i, j;

	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (i = 2; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			dp[i][j] = sum(i - 1, j);
		}
	}
	
	printf("%d", sum(n,0));
	return 0;
}

