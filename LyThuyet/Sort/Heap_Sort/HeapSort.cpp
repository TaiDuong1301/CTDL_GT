#include <iostream>
using namespace std;

void shift(int a[], int l, int r);
void CreateHeap(int a[], int n);
void HeapSort(int a[], int n);

int main()
{
    int size = 9;
    int a[] = {5, 7, 1, 8, 6, 9, 4, 2, 3};

    HeapSort(a, size);

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}
/**
 * @brief Hiệu chỉnh al, al+1, ..., ar thành heap
 * 
 * @param a int[]
 * @param l int
 * @param r int
 */
void shift(int a[], int l, int r) {
    int x, i, j;
    i = l;
    j = 2 * i + 1;
    x = a[i];
    while (j <= r)
    {
        if (j < r)
            if (a[j] < a[j + 1])
                j++;
        if(a[j] <= x)
            return;
        else
        {
            a[i] = a[j];
            a[j] = x;
            i = j;
            j = 2 * i + 1;
            x = a[i];
        }
    }
    
}
/**
 * @brief Hiệu chỉnh a0, ..., a_n-1 thành heap
 * 
 * @param a 
 * @param n 
 */
void CreateHeap(int a[], int n) {
    int l;
    l = n/2 - 1;    // last partent node
    while (l >= 0) {
        shift(a, l, n - 1);
        l = l - 1;
    }

}

void HeapSort(int a[], int n) {
    int r;
    CreateHeap(a, n);
    r = n - 1;
    while (r > 0) {
        swap(a[0], a[r]);
        r--;
        if (r > 0)
            shift(a, 0, r);
    }
}

/*
    Left node = 2n + 1
    Right node = 2n + 2
    Parent node = Math.floor((n - 1) / 2)
    Last parent node = Math.floor(size/2 - 1)
*/

/*
    Heap : 
        1. Min Heap:
            - Số nhỏ nhất là root
            - Tất cả children phải lớn hơn parent
        2. Max Heap
            - Số lớn nhất là root
            - Tất cả children phải nhỏ hơn parent
*/