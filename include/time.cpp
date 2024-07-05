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

	void testSort(void (*function)(float *, int), int max_size, int n_sizes)
	{
		int *sizes = util::linspace(max_size, n_sizes);
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
			std::cout << " [" << n << "," << elapsed << "]" << std::endl;
		}
		delete[] sizes;
	}
}

// int main(int nargs, char** nvargs){
//	int n_sizes = 10;
//	int max_size = 100000;
//	testSort(max_size, n_sizes);
//	return 0;
// }

// int main(int nargs, char** args){

// 	std::srand(std::time(nullptr));
// 	int n = 10;
// 	float* A = sort::createRandomIntArray(n, 0, 100);
// 	sort::printArray(A, n);
// 	std::cout << sort::k_smallest(A, n, 2);
// //	auto start = std::chrono::high_resolution_clock::now();
// //	sort::quickSort(A, n);
// //	sort::printArray(A, n);
// //	sort::deleteArray(A);
// //	auto end = std::chrono::high_resolution_clock::now();
// //	std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
// 	return 0;
// }