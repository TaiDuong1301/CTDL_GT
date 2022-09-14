#include<iostream>
using namespace std;

void ShellSort(int a[], int n, int h[], int k);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

void ShellSort(int a[], int n, int h[], int k) {
    int step, i, j, x, len;
    for ( step = 0; step < k; step++)
    {
        len = h[step];
        for ( i = len; i < n; i++)
        {
            x = a[i];
            j = i - len;
            while ((x < a[i]) && (i >= 0))
            {
                
            }
            
        }
        
    }
    
}