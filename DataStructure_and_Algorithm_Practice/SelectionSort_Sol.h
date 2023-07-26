#pragma once

#ifndef SELECTION_SORT_SOLUTION
#define SELECTION_SORT_SOLUTION

#include <iostream>

#include "config.h"

namespace Solution {

	template<typename T>
	void SelectionSort(T input[], int n) {
		for (int i = 0; i < n - 1; i++) {
			int idx = i;
			for (int j = i + 1; j < n; j++) {
				if (input[j] < input[idx]) {
					idx = j;
				}
			}

			if (idx != i) {
				std::swap(input[i], input[idx]);
			}
		}
	}
}

#endif // !SELECTION_SORT_SOLUTION
