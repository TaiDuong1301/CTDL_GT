#include <iostream>
using namespace std;

void NhapMang(int a[], int n);
int LinearSearch(int a[], int n, int x);
int LinearSearch_CaiTien(int a[], int n, int x);

int main()
{
    int a[100], n, x;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    NhapMang(a, n);
    cout << "Nhap khoa can tim: ";
    cin >> x;
    int kq = LinearSearch(a, n, x);
    if (kq == -1)
        cout << "Khong tim thay";
    else
        cout << "Tim thay tai vi tri " << kq;
    return 0;
}

void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}

int LinearSearch(int a[], int n, int x) {
    int i = 0;
    while (i < n && a[i] != x)
    {
        i++;
    }
    if (i < n)
        return i;
    return -1;
    
}

int LinearSearch_CaiTien(int a[], int n, int x) {
    int i = 0;
    a[n] = x;
    while (a[i] != x)
    {
        i++;
    }
    if (i < n)
        return i;
    return -1;
}