#include <iostream>
#include <string.h>
#include <fstream>
#include "include/utils.hpp" //util
#include "include/sort.hpp"	 //sort
#include "include/time.hpp"	 //test

const int SMALL_SIZE = 100000;
const int BIG_SIZE = 1000000;
const int PARTITIONS = 10;

void writeFile(std::ofstream *file, std::string filename, long **arr, int size, int partitions)
{
	int *sizes = utils::linspace(size, partitions);

	file->open(filename);
	*file << "insertionSort,selectionSort,quickSort,mergeSort" << std::endl;

	int n = 0;
	for (int i = 0; i < partitions; i++)
	{
		n = sizes[i];
		*file << n << ",";
		for (int j = 0; j < 3; j++)
			*file << arr[j][i] << ",";
		*file << arr[4][i] << std::endl;
	}
	file->close();
}

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

	//GENERICOS	
	long **smallSize1 = new long *[4];
	long **smallSize2 = new long *[4];
	long **bigSize = new long *[4];

	for (int i=0; i<4; i++)
	{
		smallSize1[i] = new long[PARTITIONS];
		smallSize1[i] = time::generic(sortFunctions[i], SMALL_SIZE, PARTITIONS);
		std::cout << sortFunctionsNames[i] << ": Test small size array 1 done" << std::endl;

		smallSize2[i] = new long[PARTITIONS];
		smallSize2[i] = time::generic(sortFunctions[i], SMALL_SIZE, PARTITIONS);
		std::cout << sortFunctionsNames[i] << ": Test small size array 2 done" << std::endl;

		bigSize[i] = new long[PARTITIONS];
		bigSize[i] = time::generic(sortFunctions[i], BIG_SIZE, PARTITIONS);
		std::cout << sortFunctionsNames[i] << ": Test big size array done" << std::endl;
	}
	std::ofstream file1, file2, file3;
	writeFile(&file1, "times/small_size_1.csv", smallSize1, SMALL_SIZE, PARTITIONS);
	writeFile(&file2, "times/small_size_2.csv", smallSize2, SMALL_SIZE, PARTITIONS);
	writeFile(&file3, "times/big_size.csv", bigSize, BIG_SIZE, PARTITIONS);
	
	//ESPECIFICOS
	long *quickSortTime = new long[PARTITIONS];
	long *radixSortTime = new long[PARTITIONS];

	quickSortTime = time::testSortSpecific(sort::quickSort, BIG_SIZE, PARTITIONS);
	std::cout << "quickSort: Specific test done" << std::endl;
	radixSortTime = time::testSortSpecific(sort::radixSort, BIG_SIZE, PARTITIONS);
	std::cout << "radixSort: Specific test done" << std::endl;

	int *sizes = utils::linspace(BIG_SIZE, PARTITIONS);

	std::ofstream file4;
	file4.open("times/specific.csv");
	file4 << "quickSort,radixSort" << std::endl;
	for (int i = 0; i < PARTITIONS; i++) {
		file4 << sizes[i] << ",";
		file4 << quickSortTime[i] << ",";
		file4 << radixSortTime[i] << std::endl;
	}
	file4.close();
	
	return 0;
}
