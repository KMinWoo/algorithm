#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long sol(long long remainder, long long indice, long long division, long long redundancy);

int main() {

	long long a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n",sol(a, b, c, 0));
	return 0;
}

long long sol(long long remainder, long long indice, long long division, long long redundancy) {

	long long ans;
	long long next;

	if (indice == 0) return remainder;

	next = remainder % division;
	if (indice % 2 == 0) {
		if (redundancy != 0)
			ans = sol(next*next, indice / 2, division, redundancy);
		else
			ans = sol(next*next, indice / 2, division, 0);
	}
	else {
		if (redundancy != 0) {
			if(indice != 1)	ans = sol(next*next, indice / 2, division, (next * redundancy) % division);
			else ans = sol((next * redundancy) % division, indice / 2, division, 0);
		}
		else
			if (indice != 1) ans = sol(next*next, indice / 2, division, next);
			else ans = sol(next, indice / 2, division, 0);
			
	}

	return ans;
}