#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;



int main() {
	int n, i, j, ans;
	long long s, e;
	vector<pair<long long, long long>> time;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s >> e;
		time.push_back(make_pair(e, s));
		//("%lld\n", s);
	}
	sort(time.begin(), time.end());

	ans = 1;
	for (i = 0; i < n; i) {
		for (j = i+1; j < n; j++) {
			if (time[i].first <= time[j].second) {
				i = j;
				ans++;
				break;
			}
		}
		if (j == n) break;
	}
	printf("%d",ans);
	return 0;
}