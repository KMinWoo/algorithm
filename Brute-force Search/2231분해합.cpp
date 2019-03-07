#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int main() {

	int n;
	int i;
	int m;
	int total;
	int ans = 0;

	scanf("%d", &n);

	for (i = n - 1; i > 0; i--) {
		m = total = i;
		
		while (m > 0) {
			total += (m % 10);
			m /= 10;
		}
		if (total == n) ans = i;

	}

	printf("%d\n", ans);

	return 0;
}