#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <limits>

using namespace std;

int arr[21];
int ans;

int sol(int sum, int end, int now) {
	int ref = 0;
	int next;

	for (int i = now; i < end; i++) {
		next = sum + arr[i];
		//printf(".....%d\n",next);
		if (next == ans) ref++;
		
		ref += sol(next, end, i + 1);
	}
	return ref;
}


int main() {
	int n;

	int info;
	int i, j, k;
	int ans_size = 0;

	scanf("%d", &n);
	scanf("%d", &ans);

	for (i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	// �κ� ������ ���� 2^n�̳� �������� �����ϹǷ� 1���� ���ش�
	for (i = 0; i < n; i++) {
		if (ans == arr[i]) ans_size++;
		ans_size += sol(arr[i], n, i + 1);
	}
	
	printf("%d", ans_size);
	return 0;
}
