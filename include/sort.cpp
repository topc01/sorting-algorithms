#include <iostream>
#include "sort.hpp"
#include "utils.hpp"

namespace sort
{

    void selectionSort(float *A, int n)
    {
        int smallest = 0;
        int i = 0;
        int j = 0;
        for (i = 0; i < n - 1; i++)
        {
            smallest = i;
            for (j = i + 1; j < n; j++)
            {
                if (A[j] < A[smallest])
                {
                    smallest = j;
                }
            }
            util::swap(A, i, smallest);
        }
    }

    void insertionSort(float *A, int n)
    {
        float aux;
        int j;
        for (int i = 1; i < n; i++)
        {
            aux = A[i];
            j = i - 1;
            while (j >= 0 && aux < A[j])
            {
                A[j + 1] = A[j];
                j--;
            }
            A[j + 1] = aux;
        }
    }


void merge(float *arr, int low, int high, int mid)
{
    int i, j, k;
    float c[high];
    // float *c = (float *)malloc(sizeof(float)*high);
    // float *c = new float[high - low + 1];
    // c = util::createArray(high - low + 1);
    // std::cout << 1 << std::endl;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
        arr[i] = c[i];
    // util::deleteArray(c);
}

void mergeSort(float *arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, high, mid);
    }
}

void mergeSort(float *arr, int high) {
    mergeSort(arr, 0, high);
}
    /*
    void merge(float *A, int i, int k, int j)
    {
        float *Aux = new float[j - i + 1];
        Aux = util::createArray(j - i + 1);
        int q = i;
        int p1 = i;
        int p2 = k + 1;
        while (p1 <= k && p2 <= j)
        {
            if (A[p1] <= A[p2])
            {
                Aux[q] = A[p1];
                p1++;
            }
            else
            {
                Aux[q] = A[p2];
                p2++;
            }
            q++;
        }
        // std::cout << 1 << std::endl;
        while (p1 <= k)
        {
            Aux[q] = A[p1];
            p1++;
            q++;
        }
        // std::cout << 2 << std::endl;
        while (p2 <= j)
        {
            Aux[q] = A[p2];
            p2++;
            q++;
        }
        for (int l = i; l < j; l++)
            A[l] = Aux[l];
        // std::cout << 3 << std::endl;
        util::deleteArray(Aux);
    }

    void mergeSort(float *A, int i, int j)
    {
        int k = (i + j)/2;
        if (i < j)
        {
            mergeSort(A, i, k);
            // std::cout << 4 << std::endl;
            mergeSort(A, k+1, j);
            // std::cout << 5 << std::endl;
            merge(A, i, k, j);
            // std::cout << 6 << std::endl;
        }
    }

    void mergeSort(float *A, int n)
    {
        mergeSort(A, 0, n - 1);
    }
    */

    int split_qs(float *A, int i, int j)
    {
        /***
         * split for quicksort
         * i,j are the endpoints
         */
        int p = util::getRandomInt(i, j);

        while (i < j)
        {

            while (i < p && A[i] <= A[p])
            {
                i = i + 1;
            }

            while (j > p && A[j] >= A[p])
            {
                j = j - 1;
            }

            util::swap(A, i, j);

            if (i == p)
            {
                p = j;
            }
            else if (j == p)
            {
                p = i;
            }
        }
        return p;
    }

    void quickSort(float *A, int i, int j)
    {
        if (i < j)
        {
            int k = split_qs(A, i, j);
            quickSort(A, i, k - 1);
            quickSort(A, k + 1, j);
        }
    }

    void quickSort(float *A, int n)
    {
        quickSort(A, 0, n - 1);
    }

    int k_smallest(float *A, int i, int j, int k)
    {
        int p = split_qs(A, i, j);
        int val = 0;
        if (k == p)
        {
            val = A[p];
        }
        else if (k < p)
        {
            val = k_smallest(A, i, p - 1, k);
        }
        else
        {
            val = k_smallest(A, p + 1, j, k);
        }
        return val;
    }

    int k_smallest(float *A, int n, int k)
    {
        return k_smallest(A, 0, n - 1, k);
    }

}
