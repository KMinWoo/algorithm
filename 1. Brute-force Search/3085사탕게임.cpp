#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int main() {
	int next_1, next_2, next_3, next_4;
	int flag1, flag2;
	int flag3, flag4;
	int n, i, j, k, x, y;
	int temp;
	int value;
	int m = 0, cnt_c, cnt_r;
	int nextPos[4][2] = { {0, 1},{1,0},{-1,0},{0,-1} };
	char color[4] = {'C','P','Z','Y'};
	char ch[60];
	int map[51][51];
	

	cin >> n;
	
	for (i = 0; i < n; i++) {
		scanf("%s",ch);
		for (j = 0; j < n; j++) {
			for (k = 0; k < 4; k++) {
				if (color[k] == ch[j])
					map[i][j] = k;
			}
		}
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

			for (k = 0; k < 4; k++) {//상하좌우의 사탕과 교환하는 경우
				x = j + nextPos[k][0];
				y = i + nextPos[k][1];
				if (x >= 0 && x < n && y >= 0 && y < n) {
					temp = map[i][j];
					map[i][j] = map[y][x];
					map[y][x] = temp;

					flag1 = flag2 = true;
					flag3 = flag4 = true;

					value = map[i][j];
					cnt_c = cnt_r = 1;
					next_1 = next_2 = i;
					next_3 = next_4 = j;
					while (flag1 || flag2 || flag3 || flag4) {
						next_1 -= 1;
						next_2 += 1;
						next_3 -= 1;
						next_4 += 1;
						if (next_1 >= 0 && flag1) flag1 = map[next_1][j] == value ? cnt_r++ : 0;
						else flag1 = false;
						if(next_2 < n && flag2) flag2 = map[next_2][j] == value ? cnt_r++ : 0;
						else flag2 = false;
						if(next_3 >= 0 && flag3) flag3 = map[i][next_3] == value ? cnt_c++ : 0;
						else flag3 = false;
						if(next_4 < n && flag4) flag4 = map[i][next_4] == value ? cnt_c++ : 0;
						else flag4 = false;
					}// 위치 교환 후에 현재의 위치에서 상하와 좌우의 현재의 위치와 같은 사탕의 갯수를 센다 
					temp = map[i][j];
					map[i][j] = map[y][x];
					map[y][x] = temp;

					m = max(m, max(cnt_r, cnt_c));
				}
			}
		}
	}
	printf("%d", m);

	return 0;
}