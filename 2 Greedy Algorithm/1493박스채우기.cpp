#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int binary[20] = { 1,2,4,8,16,32, 64, 128, 256, 512,1024,
2048, 4096, 8192, 16384,32768, 65536, 131072, 262144, 524288 };
long long n_size[20];// cube size {n_size[0] -> 1*1*1 cube}
long long  total_cube;// mean current cube number
long long  use_cube_number;
int flag;

inline int min_int(int a, int b) { return a < b ? a : b; }

int split_size(int, int, int);
int min(int, int, int);


int main() {

	int o_length, o_width, o_height;
	long long  l, w, h;
	long long need_cube_size[20];
	long long need;
	int n, cube_size;// cube number	
	int i;
	long long able_cube;

	scanf("%d %d %d %d", &o_length, &o_width, &o_height, &n);
	use_cube_number = 0;
	total_cube = 0;
	for (i = split_size(o_length, o_width, o_height); i >= 0; i--) {
		l = o_length / binary[i];
		w = o_width / binary[i];
		h = o_height / binary[i];
		need_cube_size[i] = l * w * h;
		n_size[i] = 0;
	}
	for (i = 0; i < n; i++) {			
		scanf("%d", &cube_size);
		scanf("%d", &n_size[cube_size]);
	}

	for (i = split_size(o_length, o_width, o_height); i >= 0; i--) {
		total_cube = total_cube << 3;
		able_cube = 0;
		if (total_cube < need_cube_size[i]) {
			need = need_cube_size[i] - total_cube;
			if (n_size[i] > need)	able_cube = need;
			else able_cube = n_size[i];

			use_cube_number += able_cube;
			total_cube += able_cube;
		}
	}
	if (total_cube == need_cube_size[0]) printf("%lld",use_cube_number);
	else printf("-1");

	return 0;
}


int split_size(int length, int width, int height) {
	
	int origin_size, i;
	
	origin_size = min(length, width, height);

	for (i = 19; i >= 0; i--) {
		if (origin_size >= binary[i])
			break;
	}
	return i;
}

int min(int length, int width, int height){
	return min_int(min_int(length, width), height);
}






/*
	origin size에서 넣을 수 있는 가장 큰 블럭을 넣은 후에 origin cube를 8부분으로 분할 후에
	split된 8부분을 재귀적으로 분할 정복하려고 하였으나 시간초과 발생

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int binary[20] = { 1,2,4,8,16,32, 64, 128, 256, 512,1024,
2048, 4096, 8192, 16384,32768, 65536, 131072, 262144, 524288 };
int n_size[20];// cube size {n_size[0] -> 1*1*1 cube}
int total_cube;
int use_cube_number;
int flag;

inline int min_int(int a, int b) { return a < b ? a : b; }

void split(int, int, int);
int split_size(int, int, int);
int min(int, int, int);
void stack_cube(int);


int main() {

	int o_length, o_width, o_height;
	int n, cube_size;// cube number	
	int i;
	int u = 1;

	scanf("%d %d %d %d", &o_length, &o_width, &o_height, &n);
	total_cube = 0;
	use_cube_number = 0;
	flag = 1;

	for (i = 0; i < n; i++) {
		scanf("%d", &cube_size);
		scanf("%d", &n_size[cube_size]);
		total_cube += n_size[cube_size];
	}

	split(o_length, o_width, o_height);
	if(flag == 1)
		printf("%d\n", use_cube_number);
	else
		printf("-1\n");

	return 0;
}

void split(int length, int width, int height) {
	
	int split_number;
	
	if(length != 0 && width != 0 && height != 0) split_number = split_size(length, width, height);
	else return;

	stack_cube(split_number);
	
	split(length - binary[split_number], binary[split_number], binary[split_number]);
	split(binary[split_number], width - binary[split_number], binary[split_number]);
	split(length - binary[split_number], width - binary[split_number], binary[split_number]);
	split(binary[split_number], binary[split_number], height - binary[split_number]);
	split(binary[split_number], width - binary[split_number], height - binary[split_number]);
	split(length - binary[split_number], binary[split_number], height - binary[split_number]);
	split(length - binary[split_number], width - binary[split_number], height - binary[split_number]);
}
void stack_cube(int split_number) {
	
	int i, use;

	if (flag == 0)
		return;
	
	use = 1;
	for (i = split_number; i >= 0; i--) {
		if (n_size[i] >= use) {
			n_size[i] -= use;			
			use_cube_number += use;
			use = 0;
			break;
		}
		else {
			use -= n_size[i];
			use_cube_number += n_size[i];
			n_size[i] = 0;
		}
		use = use << 3;
	}

	if (use > 0)
		flag = 0;
}

int split_size(int length, int width, int height) {
	
	int origin_size, i;
	
	origin_size = min_int(min_int(length, width), height);

	for (i = 19; i >= 0; i--) {
		if (origin_size >= binary[i])
			break;
	}
	return i;
}

int min(int length, int width, int height){
	return min_int(min_int(length, width), height);
}*/