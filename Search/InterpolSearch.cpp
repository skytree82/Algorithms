#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

template <class T>
int InterpolSearch(T arr[], int first, int last, T target) {

	while (first <= last) {
		int mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first; // 탐색 대상이 있을만한 인덱스 계산
		if (arr[mid] == target) return mid;
		else {
			if (arr[mid] < target) {
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
	}
	return -1;
}


int main() {
	int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	cout << InterpolSearch(arr, 0, 14, 3);


	return 0;
}
