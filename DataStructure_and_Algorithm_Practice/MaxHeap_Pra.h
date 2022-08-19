#pragma once

#ifndef MAX_HEAP_PRACTICE
#define MAX_HEAP_PRACTICE

#include <iostream>

#include "config.h"

namespace Practice {

	template<typename T>
	class MaxHeap {

	public:
		MaxHeap(int _capacity) {
			// TODO: Constructor

		}

		~MaxHeap() {
			// TODO: Destructor

		}

		inline int size() { return count; }

		inline bool empty() { return count == 0; }

		void insert(T item) {
			// TODO: Insert a new element
			
		}

		T pop() {
			// TODO: Pop up first element
			return NULL;
		}

		// Print out max heap in a format
		void print()
		{
			std::cout << "maxheap: [ ";
			int i = 1;
			for (; i < count; i++)
			{
				std::cout << data[i] << ", ";
			}

			std::cout << data[i] << " ]" << std::endl;
			std::cout << std::endl;
		}

		// Check if heap structure is correct
		bool check() {
			for (int i = 1; i <= count; i++) {
				if (i * 2 > count) {
					break;
				}

				if (data[i * 2] > data[i]) {
					return false;
				}

				if (i * 2 + 1 <= count && data[i * 2 + 1] > data[i]) {
					return false;
				}
			}

			return true;
		}

	private:
		// TODO: Add members as you need
		T* data;
		int capacity;
		int count;
		
		void shiftUp(int position) {
			// TODO: Helper function to reconstruct the data strucutre

		}

		void shiftDown() {
			// TODO: Helper function to reconstrcut the data structure

		}

	};
}

#endif // !MAX_HEAP_PRACTICE

