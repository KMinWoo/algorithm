#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;



int main() {
	
	int n, k;
	int i, j;
	int m;
	int type[26];
	int ans[52][4] = { 0, };
	int sum;
	char str[52];
	char ans_str[52];

	cin >> n >> k;
	
	type[0] = 0;
	type['C' - 'A'] = 1;
	type['G' - 'A'] = 2;
	type['T' - 'A'] = 3;
	// A 0 C 1 G 2 T 3 

	for (i = 0; i < n; i++) {
		scanf("%s",str);
		for (j = 0; j < k; j++) ans[j][type[str[j] - 'A']]++;
	}
	sum = 0;
	for(i = 0; i < k; i++){
		m = 0;
		for (j = 1; j < 4; j++)
			m = ans[i][m] >= ans[i][j] ? m : j;
		sum += (n - ans[i][m]);
		ans_str[i] = m == 0 ? 'A' : m == 1 ? 'C' : m == 2 ? 'G' : 'T';
	}
	ans_str[i] = '\0';
	printf("%s\n%d", ans_str, sum);

	return 0;
}