#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int main() {
	int n, l, i, k;
	int start, ans, index;
	vector<int> pos;
	

	cin >> n >> l;
	for (i = 0; i < n; i++) {
		cin >> k; 
		pos.push_back(k);
	}
	sort(pos.begin(), pos.end());
	start = pos[0];

	l--;
	index = ans = 0;
	while (1) {
		index = upper_bound(pos.begin(), pos.end(), start + l) - pos.begin();
		ans++;
		if (index > n) break;

		start = pos[index];
	}

	printf("%d\n",ans);

	return 0;
}