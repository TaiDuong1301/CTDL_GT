#include<iostream>
using namespace std;

int gt(int n);

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "n! = " << gt(n);
    return 0;
}

int gt(int n){
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * gt(n-1);
    }
    
}