#include <iostream>
#include <string.h>
// #include <matplot/matplot.h>
// #include "include.hpp"
#include "include/utils.hpp" //util
#include "include/sort.hpp"	 //sort
#include "include/time.hpp"	 //test

// using namespace sort;
// void littleSize()
// {
// 	float *randomArrayList[10];
// 	for (int i = 1; i <= 10; i++)
// 	{
// 		*(randomArrayList + i - 1) = util::createRandomIntArray(i * 10000, 10000, 100000);
// 	}
// }

// void bigSize()
// {
// 	float *randomArrayList[10];
// 	for (int i = 1; i <= 10; i++)
// 	{
// 		*(randomArrayList + i - 1) = util::createRandomIntArray(i * 100000, 100000, 1000000);
// 	}
// }

int main()
{
	std::string sortFunctionsNames[4] = {
		"insertionSort",
		"selectionSort",
		"quickSort",
		"mergeSort"
	};
	void (*sortFunctions[4])(float *, int) = {
		sort::insertionSort,
		sort::selectionSort,
		sort::quickSort,
		sort::mergeSort
	};
	// float *randomArray = util::createRandomIntArray(20000, 10000, 100000);
	// float randomArray[10] = {10, 2, 1, 9, 5, 2, 8, 3, 2, 9};
	// util::printArray(randomArray, 10);
	// sort::mergeSort(randomArray, 20000);
	// util::printArray(randomArray, 10);

	// test::testSort(sort::mergeSort, 1000000, 10);
	// Esto prueba cada funcion con distintos tamaños
	if (1) {
	std::cout << "\nSMALL SIZE:\n";
	for (int i=0; i<4; i++)
	{
		std::cout << sortFunctionsNames[i] << std::endl;
		test::testSort(sortFunctions[i], 100000, 10);
	}
	std::cout << "\nBIG SIZE:\n";
	for (int i=0; i<4; i++)
	{
		std::cout << sortFunctionsNames[i] << std::endl;
		test::testSort(sortFunctions[i], 1000000, 10);
	}
	}


	// test::testSort(sort::quickSort, 1000000, 10);
	return 0;
}
