// #include <vector>
// using namespace std;

// class Node {
//   public:
// 	int value;
// 	Node *left;
// 	Node *right;
// }

// vector<int>
// BST(Node *&root) {
// 	int min, max, size;
// 	if (!root->left && !root->right) {
// 		size = 1;
// 		min = max = root->value;
// 		return {size, min, max};
// 	};

// 	if (!root->left && root->right) {
// 		min = root->value;
// 		x = BST(root->right);
// 		if (root->value < x[max]) {
// 			max = x[max];
// 		}
// 		size = 1 + 0 + x[size];
// 		return {size, min, max};
// 	}

// 	if (root->left && !root->right) {
// 		max = root->value;
// 		x = BST(root->left);
// 		if (root->value > x[min]) {
// 			min = x[min];
// 		}
// 		size = 1 + 0 + x[size];
// 		return {size, min, max};
// 	}

// 		leftBST = BST(root->left);
// 	rightBST = BST(root->right);

// 	if (leftBST[max] < root->value && rightBST[min] > root->value) {
// 		size = 1 + leftBST[size] + rightBST[size];
// 		return {size, leftBST[min], rightBST[max]};
// 	}

// 	if (leftBST[size] < rightBST[size]) {
// 		size = rightBST[size];
// 	} else {
// 		size = leftBST[size];
// 	}

// 	return {size, -1, -1};
// }
// int main() {}

#include <iostream>
using namespace std;
int const N = 1e3;

void insertMinHeap(int minHeap[], int &size, int value) {
	size++;
	minHeap[size] = value;
	int i = size;
	while (minHeap[i / 2] > minHeap[i] && (i / 2) > 0) {
		int temp = minHeap[i];
		minHeap[i] = minHeap[i / 2];
		minHeap[i / 2] = temp;
		i = i / 2;
	}
}

void deleteFromHeap(int minHeap[], int &size) {
	minHeap[1] = minHeap[size];
	size--;
	int curr = 1;

	while (2 * curr <= size) {
		int leftchild = 2 * curr;
		int rightchild = 2 * curr + 1;
		int minchild = leftchild;
		if (rightchild <= size && minHeap[rightchild] < minHeap[leftchild]) {
			minchild = rightchild;
		}

		if (minHeap[minchild] > minHeap[curr]) {
			return;
		}
		std::swap(minHeap[minchild], minHeap[curr]);
		curr = minchild;
	}
}

void insertMaxHeap(int maxHeap[], int &size, int value) {
	size++;
	maxHeap[size] = value;
	int i = size;
	while (i / 2 > 0 && maxHeap[i / 2] < maxHeap[i]) {
		std::swap(maxHeap[i / 2], maxHeap[i]);
		i = i / 2;
	}
}

void deleteFromMaxHeap(int maxHeap[], int &size) {
	if (size < 1) {
		cout << "can't delete from empty zero-sized Heap";
		return;
	}
	maxHeap[1] = maxHeap[size];
	size--;
	int curr = 1;
	while (2 * curr <= size) {

		int leftchild = 2 * curr;
		int rightchild = 2 * curr + 1;
		int maxchild = leftchild;
		if (rightchild <= size && maxHeap[leftchild] < maxHeap[rightchild]) {
			maxchild = rightchild;
		}

		if (maxHeap[curr] >= maxHeap[maxchild]) {
			return;
		}

		std::swap(maxHeap[curr], maxHeap[maxchild]);
		curr = maxchild;
	}
};

void heapify(int arr[], int size, int curr) {
	while (2 * curr <= size) {
		int leftchild = 2 * curr;
		int rightchild = 2 * curr + 1;
		int minchild = leftchild;

		if (rightchild <= size && arr[rightchild] < arr[minchild]) {
			minchild = rightchild;
		}

		if (arr[minchild] >= arr[curr]) {
			return;
		}

		swap(arr[minchild], arr[curr]);
		curr = minchild;
	}
}
int main() {
	int minHeap[N] = {-1, 10, 20, 30, 40, 50};
	int size = 5;

	for (int i = size / 2; i > 0; i--) {
		heapify(minHeap, size, i);
	}
	// int maxHeap[N] = {-1};
	// int sizeOfMaxHeap = 0;
	insertMinHeap(minHeap, size, 100);
	deleteFromHeap(minHeap, size);
	for (int i = 0; i <= size; i++) {
		cout << minHeap[i] << " ";
	}
	return 0;
}