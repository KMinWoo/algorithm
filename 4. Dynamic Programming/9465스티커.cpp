#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> item[2];
vector<int> dp[2];
inline int max(int a, int b) { return a > b ? a : b; }

void sol(int ,int);

int main() {

	int T, n, i , j, w;

	cin >> T;

	while (T--) {
		cin >> n;
		
		dp[0].push_back(0);
		dp[1].push_back(0);
		for (j = 0; j < 2; j++) {
			for (i = 0; i < n; i++) {
				cin >> w;
				item[j].push_back(w);
			}
		}
		
		dp[0].push_back(item[0][0]);
		dp[1].push_back(item[1][0]);
		if (n >= 2) {
			dp[0].push_back(item[1][0] + item[0][1]);
			dp[1].push_back(item[0][0] + item[1][1]);
		}
		sol(3, n);

		printf("%d\n",max(dp[0][n],dp[1][n]));

		dp[0].clear();
		dp[1].clear();
		item[0].clear();
		item[1].clear();
	}



	return 0;
}

void sol(int n, int last) {

	int f, s;

	if (n > last) return;

	f = max(item[0][n - 1] + dp[1][n - 1], item[0][n - 1] + dp[1][n - 2]);
	s = max(item[1][n - 1] + dp[0][n - 1], item[1][n - 1] + dp[0][n - 2]);

	dp[0].push_back(f);
	dp[1].push_back(s);

	sol(n + 1, last);
	return;
}