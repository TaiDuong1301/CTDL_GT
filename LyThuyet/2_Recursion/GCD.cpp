// Tail recursion
#include<iostream>
using namespace std;

int gcd(int m, int n);

int main(){
    int m, n;
    cout << "Input m, n: ";
    cin >> m >> n;
    cout << "GCD(m, n) = " << gcd(m, n);
    return 0;
}

int gcd(int m, int n){
    int r;
    if (m < n)
    {
        return gcd(n, m);
    }
    r = m % n;
    if (r == 0)
    {
        return n;
    }
    else
    {
        return gcd(n, r);
    }
        
}