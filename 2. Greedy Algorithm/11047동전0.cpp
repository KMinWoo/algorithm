#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int main() {
	int n, k,i, ans, we;
	vector<int> w;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> we;
		w.push_back(we);
	}
	ans = 0;
	for (i = n - 1; i >= 0; i--) {
		ans += k / w[i];
		k = k % w[i];
	}
	printf("%d",ans);
	return 0;
}