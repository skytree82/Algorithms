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

	srand(time(NULL));
	int randIdx = p + (rand() % (r - p + 1));
	tmp = arr[r];
	arr[r] = arr[randIdx];
	arr[randIdx] = tmp;

	T pivot = arr[r];
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
	int arr[8] = { 2, 3, 7, 8, 1, 4, 5, 6 };

	QuickSort(arr, 0, 7, cmp);

	for (int x : arr) cout << x << ' ';

	return 0;
}
