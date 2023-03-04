#include <iostream>

using namespace std;


template <class T>
void SelectionSort(T arr[], int size, bool (*cmp)(T a, T b)) {
	for (int i = 0; i < size - 1; i++) {
		int swapIdx = i;
		for (int j = i + 1; j < size; j++) {
			if (cmp(arr[j], arr[swapIdx])) {
				swapIdx = j;
			}
		}

		int tmp = arr[i];
		arr[i] = arr[swapIdx];
		arr[swapIdx] = tmp;
	}
}

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int arr[8] = { 2, 3, 7, 8, 1, 4, 5, 6 };

	SelectionSort(arr, 8, cmp);

	for (int x : arr) cout << x << ' ';

	return 0;
}
