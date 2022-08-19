#pragma once

#ifndef ALGORITHM_TEST
#define ALGORITHM_TEST

#include <iostream>
#include <cassert>

#include "MaxHeap_Sol.h"

namespace AlgorithmTest {

	// Generate an random array with n elements
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);

		int* array = new int[n];

		srand((unsigned)time(NULL));		// Reset random seed

		for (int i = 0; i < n; i++) {
			array[i] = rand() * rand() % (rangeR - rangeL + 1) + rangeL;
		}

		return array;
	}

	// Print out the content of an array
	template<typename T>
	void printArray(T array[], int n)
	{
		for (int i = 0; i < n; i++) {
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}

	// Check if the array is sorted
	template<typename T>
	bool isSorted(T array[], int n) {
		for (int i = 0; i < n - 1; i++) {
			if (array[i] > array[i + 1]) {
				return false;
			}
		}

		return true;
	}

	// Run test sort and return result
	template<typename T>
	void runTest(const std::string &sortName, void (*sortFunction)(T array[], int n), T array[], int n) {

		// Call sort function
		sortFunction(array, n);

		assert(isSorted(array, n));
		std::cout << sortName << ": PASS" << std::endl;

		printArray(array, n);

		std::cout << std::endl;
	}
}
#endif // !ALGORITHM_TEST
