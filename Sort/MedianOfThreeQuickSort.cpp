#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


template <class T>
void Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T>
int Partition(T arr[], int p, int r, bool (*cmp)(T a, T b)) {
	T tmp;
	T pivot;
	int mid = (p + r) / 2;
	if (arr[p] <= arr[mid] && arr[mid] <= arr[r]) {
		pivot = arr[mid];
		tmp = arr[mid];
		arr[mid] = arr[r];
		arr[r] = tmp;
	}
	else if (arr[mid] <= arr[p] && arr[p] <= arr[r]) {
		pivot = arr[p];
		tmp = arr[p];
		arr[p] = arr[r];
		arr[r] = tmp;
	}
	else pivot = arr[r];
	
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (cmp(arr[j], pivot)) {
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = tmp;

	return i + 1;
}

template <class T>
void QuickSort(T arr[], int p, int r, bool (*cmp)(T a, T b)) {
	if (p < r) {
		int q = Partition(arr, p, r, cmp);
		QuickSort(arr, p, q - 1, cmp);
		QuickSort(arr, q + 1, r, cmp);
	}
}

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	QuickSort(arr, 0, 14, cmp);

	for (int x : arr) cout << x << ' ';

	return 0;
}
