#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;



int main() {

	
	int i,j,k;
	vector<int> ans;
	vector<int> height;
	int a;
	int total = 0;
	
	for (i = 0; i < 9; i++) {
		scanf("%d", &a);
		height.push_back(a);
		total += height[i];
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (j != i &&  100 == (total - height[i] - height[j]))
				break;
		}
		if (j < 9) break;
	}
	for (k = 0; k < 9; k++)
		if (k != i && k != j) {
			ans.push_back(height[k]);
		}

	sort(ans.begin(), ans.end());

	for (i = 0; i < 7; i++) {
		printf("%d\n",ans[i]);
	}
	
	return 0;
}