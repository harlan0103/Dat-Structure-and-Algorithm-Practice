#pragma once
#ifndef INSERTION_SORT_PRACTICE
#define INSERTION_SORT_PRACTICE

namespace Practice {
	
	template<typename T>
	void InsertionSort(T input[], int n) {
		for (int i = 1; i < n; i++) {
			T curr = input[i];
			int j = i;
			
			while (j > 0 && input[j - 1] > curr) {
				input[j] = input[j - 1];
				j--;
			}

			input[j] = curr;
		}
	}
}

#endif // !INSERTION_SORT_PRACTICE
