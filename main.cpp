#include <iostream>
#include <cassert>
#include <vector>

// s = start of range to sort
// e = end of range to sort
/*
 * void msort(int a[], int x[], int s, int e) {
    // stub
}

void mergesort(int a[], int n) {
    // stub
}
*/

/*bool sorted(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}*/

void merge_sort(std::vector<int> & v) {
    if (v.size() <= 1) //.size() returns # of elements in Vector
        return;
    int middleVec = v.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    for (size_t k = 0; k < middleVec; ++k)
        left.push_back(v[k]);
    for (size_t k = 0; k < (v.size()) - middleVec; ++k)
        right.push_back(v[middleVec + k]);

    merge_sort(left);
    merge_sort(right);
    sorted(left, right, v);
}

void sorted(std::vector<int>& left, std::vector<int>& right, std::vector<int>& v){
    int nL = left.size();
    int nR = right.size();
    int i = 0, k = 0,  j= 0;

    while (k < nL && j < nR)
    {
        if (left[k] < right[j]) {
            v[i] = left[k];
            ++k;
        }
        else {
            v[i] = right[j];
            ++j;
        }
        ++i;
    }
    while (k < nL) {
        v[i] = left[k];
        ++k; ++i;
    }
    while (j < nR) {
        v[i] = right[j];
        ++j; ++i;
    }
}


int main(int argc, char * args[]) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
    merge_sort(a, 1000);
    assert(sorted(a, 1000));
/*
	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));
	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));
	int d[] = { 1, 2, 3, 4, 5 };
	mergesort(d, 5);
	assert(sorted(d, 5));
*/
    std::cout << "All tests passed." << std::endl;
}