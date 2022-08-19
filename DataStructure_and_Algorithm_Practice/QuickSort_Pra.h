#pragma once

#ifndef QUICK_SORT_PRACTICE
#define QUICK_SORT_PRACTICE

#include <iostream>

#include "config.h"

namespace Practice {

	template<typename T>
	int partition(T array[], int low, int hi) {
		// TODO: Partition function to return pivot index

		T val = array[low];
		int n = low + 1, m = hi;

		while (true) {
			while (n <= hi && array[n] < val) {
				n++;
			}

			while (m >= low + 1 && array[m] > val) {
				m--;
			}

			if (n > m) {
				break;
			}

			std::swap(array[m], array[n]);
			n++;
			m--;
		}

		std::swap(array[low], array[m]);
		return m;
	}


	template<typename T>
	void quickSortHelper(T array[], int low, int hi) {
		// TODO: Quicksort helper function

		if (low >= hi) {
			return;

		}
		int pivot = partition(array, low, hi);
		quickSortHelper(array, low, pivot);
		quickSortHelper(array, pivot + 1, hi);
		
	}

	template<typename T>
	void quickSort(T array[], int n) {
		// TODO: Quicksort function
		quickSortHelper(array, 0, n - 1);

	}
}

#endif // !QUICK_SORT_PRACTICE
