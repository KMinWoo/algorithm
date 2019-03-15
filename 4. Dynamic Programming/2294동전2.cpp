#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
vector<int> item;
int dp[10001];
int n, k, i, w;

int main() {
	int c, j;
	cin >> n >> k;
	for (i = 0; i <= k; i++) dp[i] = 100000;
	dp[0] = 0;
	for (i = 0; i < n; i++) {
		cin >> w;
		item.push_back(w);
		if(w < 10000)
			dp[w] = 1;
	}
	for (i = 1; i <= k; i++) {
		for ( j = i, c = 0; j >= (i/2); j--, c++) {
			dp[i] = min(dp[i], dp[j] + dp[c]);
		}
	}
	printf("%d", dp[k] == 100000 ? -1 : dp[k]);
	return 0;
}