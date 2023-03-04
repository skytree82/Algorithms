#include <iostream>

using namespace std;


template <class T>
void BubbleSort(T arr[], int size, bool (*cmp)(T a, T b)) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (!cmp(arr[j], arr[j + 1])) {
				T tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int arr[8] = { 2, 3, 7, 8, 1, 4, 5, 6 };

	BubbleSort(arr, 8, cmp);

	for (int x : arr) cout << x << ' ';

	return 0;
}
