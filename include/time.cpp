#include "sort.hpp"
#include "utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>

namespace test
{

	long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
						std::chrono::time_point<std::chrono::high_resolution_clock> t2)
	{
		auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		return static_cast<long>(int_ms.count());
	}

	long *testSort(void (*function)(float *, int), int max_size, int n_sizes)
	{
		int *sizes = util::linspace(max_size, n_sizes);
		long *times = new long[n_sizes];
		// float* A = nullptr;
		int n = 0;
		for (int i = 0; i < n_sizes; i++)
		{
			n = sizes[i];
			float *A = new float[n];
			A = util::createRandomIntArray(n, sizes[0], max_size);
			auto start = std::chrono::high_resolution_clock::now();
			// change the sort method here
			(*function)(A, n);
			//
			auto end = std::chrono::high_resolution_clock::now();
			long elapsed = getElapsedTime(start, end);
			util::deleteArray(A);

			times[i] = elapsed;
			// std::cout << " [" << n << "," << elapsed << "]" << std::endl;
		}
		delete[] sizes;
		return times;
	}

	long *testSortSpecific(void (*function)(float *, int), int max_size, int n_sizes)
	{
		int *sizes = util::linspace(max_size, n_sizes);
		long *times = new long[n_sizes];
		// float* A = nullptr;
		int n = 0;
		for (int i = 0; i < n_sizes; i++)
		{
			n = sizes[i];
			float *A = new float[n];
			A = util::createRandomIntArray(n, 0, 99999);
			auto start = std::chrono::high_resolution_clock::now();
			// change the sort method here
			(*function)(A, n);
			//
			auto end = std::chrono::high_resolution_clock::now();
			long elapsed = getElapsedTime(start, end);
			util::deleteArray(A);

			times[i] = elapsed;
		}
		delete[] sizes;
		return times;
	}
}
