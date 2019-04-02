#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
int main() {
	int T;
	int n;
	vector<int> num;
	int k, j, i;
	num.push_back(1);
	for (i = 2; i <= 44; i++)
		num.push_back(num[i - 2] + i);

	cin >> T;
	while (T--) {
		cin >> n;		
		k = 0;
		for (i = (lower_bound(num.begin(), num.end(), n) - num.begin()); i >= 0 && k == 0; i--) {
			if (i <= 43) {
				for (j = (lower_bound(num.begin(), num.end(), n - num[i]) - num.begin()); j >= 0 && k == 0; j--) {
					if (j <= 43) {
						k = n == (*lower_bound(num.begin(), num.end(), n - num[i] - num[j])) + num[i] + num[j] ? 1 : 0;	
					}
				}
			}
		}
		k == 1 ? printf("1\n") : printf("0\n");
	}
	return 0;
}