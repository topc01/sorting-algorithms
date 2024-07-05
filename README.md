# Sorting algorithms

## Data Structures and Algorithms

Simple project to time sorting algorithms, including insertion sort, selection sort, quick sort and merge sort, sorting arrays of integers of lengths that vary from 10 to 1000000.

Includes code for radix sort using bucket sort, getting max value of a list, and finding the kth smallest element in a list.

Also, implements some utility functions to generate, delete and print random arrays of integers, to swap two elements in an array, set all elements of an array to a given value, and to generate a linspace of integers.

The code is written in C++.

## How to compile

To compile the code, run the following command in the terminal:

```bash
make build
```

This will create a `build` directory with cache files handled by cmake. Then, run the following command:

```bash
make code
```

To create the executable file in the `build` directory.

## How to run

To run the code, execute the following command in the terminal:

```bash
make run
```

This will create a `times` directory with the time measurements of the sorting algorithms.

## Output

The output of the code is a set of files in the `times` directory, with the time measurements of the sorting algorithms.
Authors: Vicente Cuevas and Tomás Pfingsthorn
