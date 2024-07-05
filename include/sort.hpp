#pragma once

namespace sort {
	void selectionSort(float* A, int n);
	void insertionSort(float*, int);
	void merge(float*, int, int, int);
	void mergeSort(float*, int, int);
	void mergeSort(float*, int);
	int split_qs(float* A, int i, int j);
	void quickSort(float* A, int i, int j);
	void quickSort(float* A, int n);
	int  k_smallest(float* A, int i, int j, int k);
	int  k_smallest(float* A, int n, int k);
	int maxValue(float*, int);
	void bucketSort(float*, int, int);
	void radixSort(float*, int);
}
