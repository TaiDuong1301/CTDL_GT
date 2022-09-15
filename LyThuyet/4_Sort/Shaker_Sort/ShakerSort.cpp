#include <iostream>
using namespace std;

void ShakerSort(int a[], int n);

int main(int argc, char const *argv[])
{
    int n = 9;
    int a[] = {5, 7, 1, 8, 6, 9, 4, 2, 3};

    ShakerSort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

void ShakerSort(int a[], int n) {
    int left, right, k;
    left = 0;
    right = n - 1;
    k = n - 1;
    int i;
    while (left < right)
    {
        for (i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
            
        }
        right = k;
        for (i = right; i > left; i --)
        {
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
            }
            
        }
        left = k;
    }
    
}