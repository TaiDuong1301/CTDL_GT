#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    clock_t start, end;
    start = clock();
    //tim kiem tuyen tinh
    end = clock();
    double t = end - start;
    cout << "Thoi gian tim kiem tuyen tinh la: " << t;
    start = clock();
    //tim kiem nhi phan;
    end = clock();
    double t = end - start;
    cout << "Thoi gian tim kiem nhi phan la: " << t;
    return 0;
}
