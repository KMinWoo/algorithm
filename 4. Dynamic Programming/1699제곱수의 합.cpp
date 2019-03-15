#include <stdio.h>

int main()
{
	int N;
	int dp[100001];

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 2; j*j <= i; j++) {
			if (dp[i] > (dp[i - j * j] + 1))
				dp[i] = dp[i - j * j] + 1;
		}
	}
	printf("%d", dp[N]);
	return 0;
}