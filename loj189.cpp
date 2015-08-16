#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void rotate(int nums[], int n, int k) {
	/*
	int *num = new int[n];
	for (int i = 0; i < n; i ++) {
			num[i] = nums[i];
	}
	for (int i = 0; i < n; i ++) {
			nums[(i+k)%n] = num[i];
	}
	delete num;
	// 39ms
	*/
	/*
	for (int i = 0; i < k; i ++) {
			int temp = nums[n-1];
			for (int j = n-1; j > 0; j --) {
				nums[j] = nums[j-1];
			}
			nums[0] = temp;
	}
	// tle
	*/
	for (int i = 0; i < n; i ++) {
		cout << nums[i] << endl;
	}	
}



int main() {
	int nums[] = {1,2,3,4,5,6,7};
	rotate(nums, 7, 3);
	return 0;
}
