#include<iostream>
using namespace std;

int Fibo(int n);

int main(){
    int n;
    cout << "Nhap so fibonacci thu: ";
    cin >> n;
    cout << Fibo(n);
    return 0;
}

int Fibo(int n){
    if (n <= 2)
    {
        return 1;
    }
    return Fibo(n - 1) + Fibo(n - 2);
}