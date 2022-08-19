#pragma once

#ifndef MAX_HEAP_SOLUTION
#define MAX_HEAP_SOLUTION

#include <iostream>

#include "config.h"

namespace Solution {

	template<typename T>
	class MaxHeap {

	public:
		MaxHeap(int _capacity) {
			capacity = _capacity;
			count = 0;
			data = new T[capacity + 1];	// Start from pos 1
		}

		~MaxHeap() {
			delete[] data;
		}

		inline int size() { return count; }

		inline bool empty() { return count == 0; }

		void insert(T item) {
			if (count + 1 > capacity) {
				return;
			}

			// First put the new item at the last position
			data[count + 1] = item;
			count++;
			shiftUp(count);	// Then shift up the last one
		}

		T pop() {
			if (!empty()) {
				// Get the top element
				T res = data[1];

				// Swap top element with the last one
				std::swap(data[1], data[count]);
				count--;

				// Do a shiftdown
				shiftDown();

				return res;
			}	

			return NULL;
		}

		// Print out heap structure
		void print() const
		{
			std::cout << "maxheap: [ ";
			int i = 1;
			for (; i < count; i++)
			{
				std::cout << data[i] << ", ";
			}
			
			std::cout << data[i] << " ]" << std::endl;		// i == count
		}

		// Check if heap structure is correct
		bool check() const {
			int i = 1;
			std::cout << data[i] << std::endl;
			while (i <= count) {
				int l = i * 2 <= count ? i * 2 : i;
				int r = i * 2 + 1 <= count ? i * 2 + 1 : i;

				if (data[i] < data[l] || data[i] < data[r]) {
					std::cout << i << " " << l << " " << r << std::endl;
					std::cout << data[i] << ", " << data[l] << "," << data[r] << std::endl;
					return false;
				}

				i++;
			}

			return true;
		}

	private:
		T* data;		// Use array to store elements, fast, but need pre-define size
		int count;		// Current size
		int capacity;	// Maximum size

		// Shift up current element to the correct position
		void shiftUp(int position) {
			while (position > 1 && data[position / 2] < data[position])
			{
				// If current element is not the root and
				// its parent is smaller than current element
				std::swap(data[position / 2], data[position]);
				position /= 2;
			}
		}

		void shiftDown() {
			int i = 1;
			while (i <= count) {
			
				// Find the larger one of its left and right child
				int l = i * 2 <= count ? i * 2 : i;
				int r = i * 2 + 1 <= count ? i * 2 + 1 : i;

				int max = data[l] > data[r] ? l : r;
				if (data[i] < data[max]) {
					std::swap(data[max], data[i]);
					i = max;
				}
				else {
					break;
				}
			}
		}

	};
}

#endif // !MAX_HEAP_SOLUTION
