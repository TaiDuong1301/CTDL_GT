#include<iostream>

int is_even(unsigned int n);
int is_odd(unsigned int n);

int main(){
    unsigned int n;
    std::cout << "Input n: ";
    std::cin >> n;
    n = 4;
    if (is_even(n))
    {
        std::cout << "n is even number";
    }
    else if (is_odd(n))
    {
        std::cout << "n is odd number";
    }
    
    
    return 0;
}

int is_even(unsigned int n){
    if (n == 0)
        return 1;
    else
        return is_odd(n - 1);
}

int is_odd(unsigned int n){
    return !is_even(n);
}