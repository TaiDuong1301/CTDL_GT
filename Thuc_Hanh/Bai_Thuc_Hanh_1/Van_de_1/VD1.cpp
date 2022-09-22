/**
 * @file VD1.cpp
 * @author Duong Van Tai
 * @brief  Ôn tập các thao tác trên mảng một chiều
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

void NhapMang(int a[], int n);
void PhatSinhMang(int a[], int n);
void XuatMang(int a[], int n);
int GhiMangVaoFileText(string filename, int a[], int n);
int DocFileTextVaoMang(string filename, int a[], int &n);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    string filename = "VD1Text.txt";

    PhatSinhMang(a, n);
    XuatMang(a, n);

    GhiMangVaoFileText(filename, a, n);

    int b[n];
    DocFileTextVaoMang(filename, b, n);

    XuatMang(b, n);

    return 0;
}

void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}

void PhatSinhMang(int a[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
}

void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int GhiMangVaoFileText(string filename, int a[], int n) {
    ofstream f(filename);

    if (!f.is_open())
        return 0;
        
    for (int i = 0; i < n; i++)
    {
        f << a[i] << "\t";
    }
    f.close();
    return 1;
}

int DocFileTextVaoMang(string filename, int a[], int &n) {
    ifstream f(filename);
    if (!f.is_open()) {
        cout << "Can't open the file";
        return 0;
    }
    int i = 0;
    while (f >> a[i]) {
        i++;
    }
    n = i;
    f.close();
    return 1;
}