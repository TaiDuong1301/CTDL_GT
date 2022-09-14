#include <iostream>
using namespace std;

void InsertionSort(int a[], int n);
void InsertSort(int a[], int n);

int main()
{
    int size = 9;
    int a[] = {5, 7, 1, 8, 6, 9, 4, 2, 3};

    // InsertionSort(a, size);
    InsertSort(a, size);

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

void InsertionSort(int a[], int n) {
    int pos, x;
    for (int i = 0; i < n; i++)
    {
        x = a[i+1];
        pos = i;
        while (pos >= 0 && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos] = x;
    }
    
}

/**
 * @brief 
 * @link https://vi.wikipedia.org/wiki/Sắp_xếp_chèn @endlink
 * 
 * @param array[]
 * @param size of the array
 */
void InsertSort (int a[],int n)
{
    int x, pos;
    for(int i=1;i<n;i++)
    {
       pos = i - 1;
       x = a[i];
       while(pos >= 0 && x < a[pos])
       {
           a[pos + 1] = a[pos];
           pos--;
       }
       a[pos+1] = x; // Chèn
    }  
}