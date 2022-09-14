#include<iostream>
using namespace std;

void InterchangeSort(int a[], int n);
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
    InterchangeSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    

    return 0;
}

void InterchangeSort(int a[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                Swap(a[i], a[j]);
            }
            
        }
        
    }
    
}

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}