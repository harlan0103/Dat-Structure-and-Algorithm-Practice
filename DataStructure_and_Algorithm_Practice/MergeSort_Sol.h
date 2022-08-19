#pragma once

#ifndef MERGE_SORT_SOL
#define MERGE_SORT_SOL

namespace Solution { 

	// Sort input array in given range for two parts
	template<typename T>
	void conqureHelper(T input[], int low, int mid, int hi) {
		// Need a temp array
		T* temp = new T[hi - low + 1];

		for (int i = low; i <= hi; i++) {
			temp[i - low] = input[i];
		}	

		// Based on segment [low ... mid] and [mid + 1 ... hi]
		// Rearrange all
		int m = low, n = mid + 1;
		for (int k = low; k <= hi; k++) {

			if (m > mid) {
				input[k] = temp[n - low];
				n++;
			}
			else if (n > hi) {
				input[k] = temp[m - low];
				m++;
			}
			else if (temp[m - low] > temp[n - low]) {
				input[k] = temp[n - low];
				n++;
			}
			else {
				// temp[m - 1] < temp[n - 1]
				input[k] = temp[m - low];
				m++;
			}
		}

		delete[] temp;
	}

	// Divide Helper
	// Divide the input array into two parts
	// Then call conqure function to sort
	template<typename T>
	void divideHelper(T input[], int low, int hi) {

		// Range [lo ... hi]
		if (low >= hi) {
			return;
		}

		// Find mid point and divide them
		// void out of bounds
		int mid = low + (hi - low) / 2;

		divideHelper(input, low, mid);
		divideHelper(input, mid + 1, hi);
		conqureHelper(input, low, mid, hi);
	}

	template<typename T>
	void mergeSort(T input[], int n) {
		divideHelper(input, 0, n - 1);
	}

}


#endif // !MERGE_SORT_SOL
