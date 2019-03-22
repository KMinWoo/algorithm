#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
int main() {
	int map[51][51];
	int n, m, i, j, x, y;
	char ch[52];
	int b, w;
	int ans = 2500;
	cin >> n >> m;

	for (i = 0; i < n; i++) {
		scanf("%s",ch);
		for (j = 0; j < m; j++) {
			if (ch[j] == 'B') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}

	for (i = 0; i <= n - 8; i++) {
		for (j = 0; j <= m - 8; j++) {
			b = w = 0;
			for (y = i; y < i + 8; y++) {
				for (x = j; x < j + 8; x++) {
					if (map[y][x] != ((x + y) % 2)) b++;
					else w++;
				}// 시작점이 검은색으로 할 수도 있고 하얀색으로 시작하는 경우
				// 두가지 중에서 작은 값을 답으로 취한다
			}
			ans = min(min(b, w), ans);
		}
	}


	printf("%d",ans);
	
	return 0;
}