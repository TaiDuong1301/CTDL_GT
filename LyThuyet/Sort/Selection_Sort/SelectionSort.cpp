#include<iostream>
using namespace std;

void SelectionSort(int a[], int n);
// void Swap(int &a, int &b);

int main(int argc, char const *argv[])
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SelectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    
    return 0;
}

void SelectionSort(int a[], int n) {
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
            
        }
        if (min != i)
        {
            swap(a[min], a[i]);
        }
        
    }
    
}

// void Swap(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b =temp;
// }