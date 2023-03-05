#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;
int cnt = 0;

template <class T>
int InterpolSearch(T arr[], int first, int last, T target) {

	while (arr[first] > target || arr[last] < target) {
		int mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;
		if (arr[mid] == target) return mid;
		else {
			if (arr[mid] < target) {
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		cnt++;
	}
	return -1;
}


int main() {
	int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int arr2[] = { 1, 3, 5, 7, 9 };

	//cout << InterpolSearch(arr, 0, 14, 3) << '\n' << cnt;

	cout << InterpolSearch(arr2, 0, 4, 2);


	return 0;
}
