#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <limits>

using namespace std;

inline int Max(int a, int b) { return a > b ? a : b; }
inline int Min(int a, int b) { return a > b ? b : a; }

int sum[100001];
int dp[100001];



int main() {
	int n;
	int info;
	int i, j, k;
	int max;

	scanf("%d", &n);
	scanf("%d", &info);
	dp[0] = info;
	max = info;
	// 1.
	for (i = 1; i < n; i++) {
		scanf("%d", &info);	
		dp[i] = Max(dp[i-1] + info, info);
		max = Max(max, dp[i]);
	}
	/*
	2.
	scanf("%d", &sum[0]);
	max = sum[0];
	for (i = 2, j = 0; i <= n; i++) {
		scanf("%d", &info);
		max = Max(info, max);
		if (sum[j] >= 0 && info >= 0) sum[j] += info;
		else if (sum[j] <= 0 && info <= 0) sum[j] += info;
		else sum[++j] = info;

	}
	if (j == 0 && sum[0] <= 0)
	{
		printf("%d", max);
		return 0;
	}
	sum[j + 1] = 0;
	dp[0] = sum[0] > 0 ? sum[0] : sum[1];
	max = dp[0];
	k = 1;
	for (i = sum[0] >= 0 ? 2 : 3; i <= j;i+=2) {
		dp[k++] = Max(dp[k - 1] + sum[i - 1] + sum[i], sum[i]);
		max = Max(max, dp[k - 1]);
	}*/
	printf("%d",max);

	return 0;
}
