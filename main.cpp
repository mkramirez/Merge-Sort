#include <iostream>
#include <cassert>

void mergeSort(int a[], int n) {
    int firstHalf = 0; //half of the array
    int secondHalf = 0; //other half of the array
    int array1[firstHalf]; //array for the first half
    int array2[secondHalf]; //array for second half
    int minVar = 0; //hold the minimum element
    int minDex = 0; //hold the index of where the element is located
    int index1 = 0; //index for first arrays
    int index2 = 0; //index for second array

    //creates array sizes
    if (n % 2 == 0) {
        firstHalf = n/2;
        secondHalf = n/2;
    }
    else {
        firstHalf = n/2 + 1;
        secondHalf = n/2;
    }

    //fill arrays
    for (int i = 0; i < firstHalf; i++) {
        array1[i] = a[i];
    }
    for (int i = firstHalf; i < n; i++) {
        array2[i] = a[i];
    }

    for (int begin = 0; begin < firstHalf; begin++) {
        minVar = array1[begin];
        for (int i = begin + 1; i < firstHalf; i++) {
            if (array1[i] < minVar) {
                minVar = array1[i];
                minDex = i;
            }
        }
        array1[minDex] = array1[begin];
        a[begin] = minVar;
    }

    for (int begin = 0; begin < secondHalf; begin++) {
        minVar = array2[begin];
        for (int i = begin + 1; i < secondHalf; i++) {
            if (array2[i] < minVar) {
                minVar = array2[i];
                minDex = i;
            }
        }
        array2[minDex] = array2[begin];
        a[begin] = minVar;
    }

    for (int i = 0; i < n; i++) {
        if (array1[index1] <= array2[index2] && index1 < firstHalf) {
            a[i] = array1[index1];
            index1++;
        }
        else if (index2 < secondHalf) {
            a[i] = array2[index2];
            index2++;
        }
    }
}

bool sorted (const int a[], int n) {
    for (int i = 0; i < n -1; ++i) {
        if (a[i] > a[i + 1])
            return true;
    }
    return false;
}

int main(int argc, char * args[]) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
    mergeSort(a, 1000);
    assert(sorted(a, 1000));
	int b[1001];
    for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergeSort(b, 1001);
	assert(sorted(b, 1001));
	int c[] = { 2 };
	mergeSort(c, 1);
	assert(sorted(c, 1));
	int d[] = { 1, 2, 3, 4, 5 };
	mergeSort(d, 5);
	assert(sorted(d, 5));

    std::cout << "All tests passed." << std::endl;
}