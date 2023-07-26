#include <iostream>

#include "config.h"
#include "AlgorithmTest.h"
#include "MergeSort_Sol.h"
#include "QuickSort_Sol.h"
#include "MaxHeap_Sol.h"
#include "BubbleSort_Sol.h"
#include "SelectionSort_Sol.h"
#include "InsertionSort_Sol.h"

#include "MergeSort_Pra.h"
#include "QuickSort_Pra.h"
#include "MaxHeap_Pra.h"
#include "BubbleSort_Pra.h"
#include "SelectionSort_Pra.h"
#include "InsertionSort_Pra.h"

#include <string>
#include <vector>
#include <queue>

// Run merge sort
void runMergeSort(bool runTest) {

	if (runTest) {
		int n = SIZE;

		int* array = AlgorithmTest::generateRandomArray(n, 0, n);
		AlgorithmTest::runTest(ALGORITHM_MERGE_SORT, Practice::mergeSort, array, n);

		delete[] array;
	}
}

// Run quick sort
void runQuickSort(bool runTest) {
	
	if (runTest) {
		int n = SIZE;

		int* array = AlgorithmTest::generateRandomArray(n, 0, n);
		AlgorithmTest::runTest(ALGORITHM_QUICK_SORT, Practice::quickSort, array, n);

		delete[] array;
	}
}

// Run maxheap
void runMaxHeap() {

	Practice::MaxHeap<int> maxheap = Practice::MaxHeap<int>(100);

	srand((unsigned)time(NULL));
	for (int i = 0; i < 15; i++)
	{
		maxheap.insert(rand() % 100);
	}

	maxheap.print();
	assert(maxheap.check());

	maxheap.pop();
	maxheap.print();
	assert(maxheap.check());

	
	std::cout << std::endl;
}

// Run bubble sort
void runBubbleSort(bool runTest) {
	if (runTest) {
		int n = SIZE;

		int* array = AlgorithmTest::generateRandomArray(n, 0, n);
		AlgorithmTest::runTest(ALGORITHM_BUBBLE_SORT, Practice::BubbleSort, array, n);

		delete[] array;
	}
}

// Run selection sort
void runSelectionSort(bool runTest) {
	if (runTest) {
		int n = SIZE;

		int* array = AlgorithmTest::generateRandomArray(n, 0, n);
		AlgorithmTest::runTest(ALGORITHM_SELECTION_SORT, Practice::SelectionSort, array, n);

		delete[] array;
	}
}

// Run insertion sort
void runInsertionSort(bool runTest) {
	if (runTest) {
		int n = SIZE;

		int* array = AlgorithmTest::generateRandomArray(n, 0, n);
		AlgorithmTest::runTest(ALGORITHM_INSERTION_SORT, Practice::InsertionSort, array, n);

		delete[] array;
	}
}

int main() {

	// Run merge sort
	runMergeSort(DISABLE_TEST);

	// Run quick sort
	runQuickSort(DISABLE_TEST);

	// Run max heap
	//runMaxHeap();

	// Run bubble sort
	runBubbleSort(ABLE_TEST);

	// Run selection sort
	runSelectionSort(ABLE_TEST);

	// Run insertion sort
	runInsertionSort(ABLE_TEST);

	return 0;
}