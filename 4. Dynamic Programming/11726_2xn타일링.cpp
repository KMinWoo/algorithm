
#include <iostream>
#include <string.h>

int dp[1001];

int sol(int N) {
	
	if (N < 0)
		return 0;
	else if (N <= 1)
		return 1;


	if(dp[N] == 0)
		dp[N] = (sol(N - 1) + sol(N - 2)) % 10007;
	
	return dp[N];

}



int main()
{
	
	int N;

	scanf("%d",&N);

	memset(dp, 0, sizeof(dp));
	if (N == 0)
		printf("0\n");
	else
		printf("%d\n", sol(N));

	
	return 0;
}