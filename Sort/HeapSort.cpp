#include <iostream>

#define ParentIdx(idx) idx / 2
#define LeftIdx(idx) idx * 2
#define RightIdx(idx) idx * 2 + 1

using namespace std;

template <class T>
class Heap {
private:
	int heapSize;
	T heapArr[100];
	bool (*cmp)(T senior, T subord); // senior의 우선순위가 높으면 true
public:
	Heap(bool(*_cmp)(T senior, T subord)) : cmp(_cmp), heapSize(0) {}

	bool HeapEmpty() {
		if (heapSize == 0) return true;
		else return false;
	}

	void HeapInsert(T data) {
		if (heapSize == 100 - 1) {
			std::cout << "Memory Access Error!";
			exit(-1);
		}

		heapSize++;
		int curIdx = heapSize;

		while (curIdx != 1 && !(cmp(heapArr[ParentIdx(curIdx)], data))) {
			heapArr[curIdx] = heapArr[ParentIdx(curIdx)];
			curIdx = ParentIdx(curIdx);
		}

		heapArr[curIdx] = data;
	}

	T HeapDelete() {
		if (this->HeapEmpty()) {
			std::cout << "Memory Access Error!";
			exit(-1);
		}

		T delData = heapArr[1];
		T lastData = heapArr[heapSize];

		int curIdx = 1;
		int childIdx;

		while (childIdx = this->HighPrecChildIdx(curIdx)) {
			if (cmp(lastData, heapArr[childIdx])) break;

			heapArr[curIdx] = heapArr[childIdx];
			curIdx = childIdx;
		}

		heapArr[curIdx] = lastData;
		heapSize--;

		return delData;
	}

	int HighPrecChildIdx(int idx) {
		if (LeftIdx(idx) > heapSize) return 0;
		else if (LeftIdx(idx) == heapSize) return LeftIdx(idx);
		else {
			if (cmp(heapArr[LeftIdx(idx)], heapArr[RightIdx(idx)])) return LeftIdx(idx);
			else return RightIdx(idx);
		}
	}
};

template <class T>
void HeapSort(T arr[], int size, bool (*cmp)(T a, T b)) {
	Heap<T> heap(cmp);

	for (int i = 0; i < size; i++) {
		heap.HeapInsert(arr[i]);
	}
	for (int i = 0; i < size; i++) {
		arr[i] = heap.HeapDelete();
	}
}

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int arr[8] = { 2, 3, 7, 8, 1, 4, 5, 6 };

	HeapSort(arr, 8, cmp);

	for (int x : arr) cout << x << ' ';

	return 0;
}
