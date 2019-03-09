#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int l, p, v;
	int n;
	bool flag = true;
	int c = 1, ans, s;

	do{
		scanf("%d %d %d", &l, &p, &v);

		if (l == 0 && p == 0 && v == 0)
			break;

		n = v / p;
		s = v - (p * n);
		if (l > s)
			ans = n * l + s;
		else
			ans = (n + 1) * l;
		
		printf("Case %d: %d\n", c++, ans);

	} while (flag);



	return 0;
}