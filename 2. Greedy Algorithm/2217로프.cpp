#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int main() {
	int n, info;
	int i, m;
	vector<int> rofe;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d",&info);
		rofe.push_back(info);
	}
	sort(rofe.begin(), rofe.end());
	m = 0;
	for (i = 0; i < n; i++) {
		m = max(rofe[i] * (n - i), m);
	}
	printf("%d",m);

	return 0;
}