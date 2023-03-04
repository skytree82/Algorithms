#include <iostream>

using namespace std;


template <class T>
void InsertionSort(T arr[], int size, bool (*cmp)(T a, T b)) {
	int i, j;

	for (i = 1; i < size; i++) {
		int insertData = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (!cmp(arr[j], insertData)) {
				arr[j + 1] = arr[j];
			}
			else break;
		}
		arr[j + 1] = insertData;
	}
}

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int arr[8] = { 2, 3, 7, 8, 1, 4, 5, 6 };

	InsertionSort(arr, 8, cmp);

	for (int x : arr) cout << x << ' ';

	return 0;
}
