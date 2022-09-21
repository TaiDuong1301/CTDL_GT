/**
 * @file VD1.cpp
 * @author your name (you@domain.com)
 * @brief  Ôn tập các thao tác trên mảng một chiều
 * @version 0.1
 * @date 2022-09-20
 * 
 * @copyright Copyright (c) 2022
 * 
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
    cout << "Input n: ";
    cin >> n;
    int a[n];
    PhatSinhMang(a, n);
    XuatMang(a, n);

    string filename;
    filename = "VD1Text.txt";

    GhiMangVaoFileText(filename, a, n) ? cout << "Success" << endl : cout << "Error" << endl;

    int b[n];

    DocFileTextVaoMang(filename, b, n) ? cout << "Success" << endl : cout << "Error" << endl;

    XuatMang(b, n);

    XuatMang(a, n);

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
    // FILE *f = fopen(filename, "wt");
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
        return 0;
    }
    int i = 0;
    while (f.eof()) {
        f >> a[i];
        i++;
    }
    // n = i;
    f.close();
    return 1;
}