#pragma once

#ifndef BUBBLE_SORT_SOLUTION
#define BUBBLE_SORT_SOLUTION

#include <iostream>

#include "config.h"

namespace Solution {

	template<typename T>
	void BubbleSort(T input[], int n) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (input[j] > input[j + 1]) {
					std::swap(input[j], input[j + 1]);
				}
			}
		}
	}
}

#endif // !BUBBLE_SORT_SOLUTION
