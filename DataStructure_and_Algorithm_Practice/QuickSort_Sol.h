#pragma once

#ifndef QUICK_SORT_SOLUTION
#define QUICK_SORT_SOLUTION

#include <iostream>

#include "config.h"

namespace Solution {

	// Partition for [low ... hi]
	// Return a pivot point
	template<typename T>
	int partitionHelper(T input[], int low, int hi) {
		// Use this value as pivot
		T v = input[low];

		int i = low + 1, j = hi;
		while (true) {
			// Make sure input[i] less than V
			while (i <= hi && input[i] < v) {
				i++;
			}

			// Make sure input[j] bigger than V
			while (j >= low + 1 && input[j] > v) {
				j--;
			}

			if (i > j) {
				break;
			}

			// For now we must have input[i] > v and input[j] < v
			// swap them
			std::swap(input[i], input[j]);
			i++;
			j--;
		}

		// For now i > j
		// and input[j] is the last element that smaller than pivot
		// so we need to swap it with pivot so that all elements on pivot left is smaller than pivot
		// and all elements on pivot right is bigger than pivot
		// After swap, pivot is at input[j]
		std::swap(input[low], input[j]);

		return j;
	}


	// Find pivit pivot
	// [low ... pivot] smaller than pivot
	// [pivot + 1 ... hi] larger than pivot
	template<typename T>
	void quickSortHelper(T input[], int low, int hi) {
		if (low >= hi) {
			return;
		}	

		// Find pivit point
		int p = partitionHelper(input, low, hi);
		quickSortHelper(input, low, p);
		quickSortHelper(input, p + 1, hi);
	}

	template<typename T>
	void quickSort(T input[], int n) {
		quickSortHelper(input, 0, n - 1);
	}

}

#endif // !QUICK_SORT_SOLUTION
