#include<iostream>
using namespace std;

int LinearSentinel(int a[], int n, int x);

int main(int argc, char const *argv[])
{
    
    return 0;
}

int LinearSentinel(int a[], int n, int x) {
    a[n] = x;
    for (int i = 0; ; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
        
    }
    
}