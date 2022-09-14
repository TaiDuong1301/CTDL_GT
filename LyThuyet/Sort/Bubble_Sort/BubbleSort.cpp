#include<iostream>
using namespace std;

void BubbleSort(int a[], int n);
void Swap(int &a, int &b);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Input n:";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    BubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    return 0;
}

void BubbleSort(int a[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                Swap(a[j], a[j - 1]);
            }
            
        }
        
    }
    
}

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}