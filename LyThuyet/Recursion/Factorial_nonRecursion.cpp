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
    int s = 1;
    for (int i = 2; i <= n; i++)
    {
        s = s * i;
    }
    
    return s;
}