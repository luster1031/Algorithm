#include<stdio.h>

int main() {
	int N;//��հ���, ����
	int store[1001][2] = { 0 };//[��ġ][����]
	int max_location = 0, min = 0;
	int max_high = 0;
	

	int left_min = 0;
	int left_max = -1;
	int left_min_location = 501;
	int left_max_high = 0;
	int left_max_location = 0;

	int right_count = 0;
	int right_max_location = 0;
	int right_max_high = 0;
	int right_min = 0;
	int right_max = -1;
	int right_min_location = 0;

	int left_count = 0;
	
	int right[501] = { 0 };
	int left[501] = { 0 };

	//����
	int area = 0;

	//��հ���
	scanf("%d", &N);
	
	//���� �ޱ�
	for (int i = 0; i < N; i++) {
		scanf("%d %d",&store[i][0], &store[i][1]);
		//�ִ밪 ���ϱ�
		if (max_high < store[i][1]) {
			max_location = store[i][0]; //�ִ���ġ
			max_high = store[i][1];//�ִ� ����
		}
	
	}

	for (int i = 0; i < N; i++) {
		if (max_location < store[i][0]) {
			right[right_count++] = i;	//ū ��ġ�� �� ��ȣ �ֱ�
			if (right_min_location < store[i][0]) {
				right_min_location = store[i][0];
			}
		}
		else if (max_location > store[i][0]) {
			left[left_count++] = i;		//���� ��ġ�� �� �ֱ�
			if (left_min_location > store[i][0]) {
				left_min_location = store[i][0];
			}
				
			
		}
	}

	//�ִ��� left_min�� �ǵ��� ���
		//left_count-- ��ŭ ���鼭 �ִ� ���ϱ�
		//�� ����, �ִ��� ���� * (������ - ��ġ)
	
	int befor_loc = max_location;

	while (left_max_location != left_min_location) {
		for (int i = 0; i < left_count; i++) {
			if (left_max_high <= store[left[i]][1] && store[left[i]][0] < befor_loc ) {
				left_max_high = store[left[i]][1];
				left_max = left[i];//left_max ���� �� �� �ֱ�
				left_max_location = store[left[i]][0];
			}
		}
		area += store[left_max][1] * (befor_loc - store[left_max][0]);
		befor_loc = store[left_max][0];
		left_max_high = 0;
	}

	right_max_high = 0;
	befor_loc = max_location;
	area += max_high;
	while (right_max_location != right_min_location) {
		for (int i = 0; i < right_count; i++) {
			if (right_max_high < store[right[i]][1] && store[right[i]][0] > befor_loc) {
				right_max_high = store[right[i]][1];
				right_max = right[i];
				right_max_location = store[right[i]][0];
			}
		}
		area += store[right_max][1] * (store[right_max][0] - befor_loc);
		befor_loc = store[right_max][0];
		right_max_high = 0;
	}

	printf("%d", area);
	return 0;
}

//max�� �� ū�� N��ĵ
	//ū�� �� ������ min
		//

	//ū�� �� ū�� big