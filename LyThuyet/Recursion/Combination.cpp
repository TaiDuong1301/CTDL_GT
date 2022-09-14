// Binary recursion
#include<iostream>
using namespace std;

int choose(int n, int k);

int main(){
    int n, k;
    cout << "Input n, k: ";
    cin >> n >> k;
    cout << "nCk = " << choose(n, k);
    return 0;
}

int choose(int n, int k){
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return (choose(n - 1, k) + choose(n - 1, k - 1));
    }
    
    
}