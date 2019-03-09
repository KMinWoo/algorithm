#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> work;
int score[1001];
inline bool compare_score(pair<int, int> f, pair<int, int>s) {
	return f.second > s.second ? true : false;
}
int main() {
	int n,ans;
	int d, w, i;

	for (i = 0; i <= 1000; i++) score[i] = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &d, &w);
		work.push_back(make_pair(d,w));
	}
	sort(work.begin(), work.end(), compare_score);
	for (vector<pair<int, int>>::iterator iter = work.begin(); iter < work.end(); iter++) {
		for (i = iter->first; i > 0; i--) {
			if (score[i] == 0) {
				score[i] = iter->second;
				break;
			}
		}
	}
	ans = 0;
	for (i = 0; i <= 1000; i++) ans += score[i];
	printf("%d",ans);

	return 0;
}