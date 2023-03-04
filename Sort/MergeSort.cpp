#include <iostream>

using namespace std;

template <class T>
void Merge(T arr[], int left, int mid, int right, bool (*cmp)(T a, T b)) {
	T* mergedArr = new T[right + 1];
	int curFront = left; int curBack = mid + 1;
	int curIdx = left;

	while (curFront <= mid && curBack <= right) {
		if (cmp(arr[curFront], arr[curBack])) {
			mergedArr[curIdx] = arr[curFront++];
		}
		else {
			mergedArr[curIdx] = arr[curBack++];
		}
		curIdx++;
	}

	if (curFront > mid) {
		for (int i = curBack; i <= right; i++, curIdx++) {
			mergedArr[curIdx] = arr[i];
		}
	}
	else {
		for (int i = curFront; i <= mid; i++, curIdx++) {
			mergedArr[curIdx] = arr[i];
		}
	}

	for (int i = left; i <= right; i++) {
		arr[i] = mergedArr[i];
	}

	delete[] mergedArr;
}

template <class T>
void MergeSort(T arr[], int left, int right, bool(*cmp)(T a, T b)) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid, cmp);
		MergeSort(arr, mid + 1, right, cmp);

		Merge(arr, left, mid, right, cmp);
	}
}

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int arr[8] = { 2, 3, 7, 8, 1, 4, 5, 6 };
	MergeSort(arr, 0, 7, cmp);


	for (int x : arr) cout << x << ' ';

	return 0;
}
