#include <iostream>
#define MAX 100
using namespace std;
/**
 * @brief 
 * Sắp xếp mảng (a, n) tăng dần
 * 
 * @param a 
 * @param N 
 */
void MergeSort(int a[], int N);
/**
 * @brief Phân phối đều luân phiên các dãy con độ dài k từ mảng a vào hai mảng con b, c
 * 
 * @param a 
 * @param N 
 * @param nb 
 * @param nc 
 * @param k 
 */
void Distribute(int a[], int N, int &nb, int &nc, int k);
/**
 * @brief Trộn mảng b và c vào mảng a
 * 
 * @param a 
 * @param nb 
 * @param nc 
 * @param k 
 */
void Merge(int a[], int nb, int nc, int k);
/**
 * @brief Trộn một cặp dãy con từ b và c vào a
 * 
 * @param a 
 * @param nb 
 * @param nc 
 * @param pa 
 * @param pb 
 * @param pc 
 * @param k 
 */
void MergeSubarr(int a[], int nb, int nc, int &pa, int &pb, int &pc, int k);
/**
 * @brief Trả về số nhỏ hơn trong hai số a và b
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int min(int a, int b);

int b[MAX], c[MAX], nb, nc;

int main(int argc, char const *argv[])
{
    
    return 0;
}

void MergeSort(int a[], int N) {
    int k;
    for (k = 0; k < N; k++) {
        Distribute(a, N, nb, nc, k);
        Merge(a, nb, nc, k);
    }
}

void Distribute(int a[], int N, int &nb, int &nc, int k) {
    int i, pa, pb, pc;
    pa = pb = pc = 0;
    while (pa < N)
    {
        for (i = 0; (pa < N) && (i < k); i++, pa++, pb++)
            b[pb] = a[pa];
        for (i = 0; (pa < N) && (i < k); i++, pa++, pc++)
            c[pc] = a[pa];
    }
    nb = pb;
    nc = pc;
}

void Merge(int a[], int nb, int nc, int k) {
    int p, pb, pc, ib, ic, kb, kc;
    p = pb = pc = 0;
    ib = ic = 0;
    while ((nb > 0) && (nc > 0)) {
        kb = min(k, nb);
        kc = min(k, nc);
        if (b[pb + ib]  <= c[pc + ic]) {
            a[p++] = b[pb + ib];
            ib++;
            if (ib == kb) {
                for (;ic < kc; ic++)
                    a[p++] = c[pc + ic];

                    pb += kb;
                    pc += kc;
                    ib = ic = 0;
                    nb -= kb;
                    nc -= kc;
            }
        }else {
                a[p++] = c[pc + ic];
                ic++;
                if (ic == kc) {
                    for (; ib < kb; ib++)
                        a[p++] = b[pb + ib];
                    
                    pb += kb;
                    pc += kc;
                    ib = ic = 0;
                    nb -= kb;
                    nc -= kc;
                }
            }
    }
}

int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}