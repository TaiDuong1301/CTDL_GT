#include<iostream>
using namespace std;

struct HOCSINH
{
    char MSHS[10];
    char TENHS[50];
    float toan, van, anh;
    float tongdiem;
};

void InputHS(HOCSINH ds[], int n);
void OutputHS(HOCSINH ds[], int n);
void tinhtongdiem(HOCSINH ds[], int n);
void InterchangeSort(HOCSINH ds[], int n);
void Swap(HOCSINH &a, HOCSINH &b);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    HOCSINH ds[100];
    InputHS(ds, n);
    tinhtongdiem(ds, n);
    InterchangeSort(ds, n);
    OutputHS(ds, n);
    return 0;
}

void InputHS(HOCSINH ds[], int n){
    cout << "Nhap thong tin hoc sinh" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Hoc sinh thu " << i+1 << endl;
        cout << "MSHS: ";
        cin >> ds[i].MSHS;
        fflush(stdin);
        cout << "Ho Ten: ";
        //cin >> ds[i].TENHS;
        gets(ds[i].TENHS);
        cout << "Diem toan: ";
        cin >> ds[i].toan;
        cout << "Diem van: ";
        cin >> ds[i].van;
        cout << "Diem anh: ";
        cin >> ds[i].anh;
    }
    
}

void OutputHS(HOCSINH ds[], int n){
    cout << "DSHS" << endl;
    printf("%5s %-20s %5s %5s %5s %10s\n", "MSHS", "Ho Ten", "Toan", "Van", "Anh", "Tong Diem");
    for (int i = 0; i < n; i++)
    {
        printf("%5s %-20s %5.2f %5.2f %5.2f %10.2f\n", ds[i].MSHS, ds[i].TENHS, ds[i].toan, ds[i].van, ds[i].anh, ds[i].tongdiem);
    }
    
}

void tinhtongdiem(HOCSINH ds[], int n){
    for (int i = 0; i < n; i++)
    {
        ds[i].tongdiem = ds[i].toan + ds[i].anh + ds[i].van;
    }
    
}

void InterchangeSort(HOCSINH ds[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].tongdiem > ds[j].tongdiem)
            {
                Swap(ds[i], ds[j]);
            }
            
        }
        
    }
    
}

void Swap(HOCSINH &a, HOCSINH &b){
    HOCSINH temp = a;
    a = b;
    b = temp;
}