#include <iostream>
using namespace std;

void QuickSort(int a[], int left, int right);

int main(int argc, char const *argv[])
{
    int n = 8;
    int a[] = {3, 6, 4, 7, 2, 1, 8, 9};
    QuickSort(a, 0, 8);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    

    return 0;
}

void QuickSort(int a[], int left, int right) {
    int i, j, x;
    if (left > right)
    {
        return;
    }
    x = a[(left + right)/2];
    i = left;
    j = right;
    do
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (left < j) QuickSort(a, left, i);
    if (i < right) QuickSort(a, i, right);
}