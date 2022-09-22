#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int BinarySearch(int a[], int left, int right, int x);
void PhatSinhMangTang(int a[], int n);
void XuatMang(int a[], int n);

int main()
{
    int a[100], n, x;
    cout << "Ban can phat sinh mang co bao nhieu phan tu: ";
    cin >> n;
    PhatSinhMangTang(a, n);
    XuatMang(a, n);
    cout << "Nhap khoa can tim: ";
    cin >> x;
    int kq = BinarySearch(a, 0, n - 1, x);
    if (kq == -1)
        cout << "Khong tim thay";
    else
        cout << "Tim thay tai vi tri " << kq;
    return 0;
}

int BinarySearch(int a[], int left, int right, int x) {
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (x == a[mid])
        return mid;
    if (x < a[mid])
        return BinarySearch(a, left, mid - 1, x);
    if (x > a[mid])
        return BinarySearch(a, mid + 1, right, x);
}

void PhatSinhMangTang(int a[], int n) {
    srand(time(NULL));
    a[0] = rand() % 50;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + rand() % 10;
    }
    
}

void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}