#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main() {
	int n, i, j, k, ans;
	int s, e, d;
	bool flag = true;
	vector<pair<int, int>> time;
	priority_queue<int,vector<int>,greater<int>> pq;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s >> e;
		time.push_back(make_pair(s, e));
	}
	sort(time.begin(), time.end());
	pq.push(time[0].second);
	for (i = 1; i < n; i++) {
		if (time[i].first >= pq.top())
			pq.pop();
		pq.push(time[i].second);
	}

	printf("%d", pq.size());
	return 0;
}