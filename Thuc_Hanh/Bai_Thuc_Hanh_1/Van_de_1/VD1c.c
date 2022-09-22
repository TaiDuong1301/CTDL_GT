#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void NhapMang(int a[], int n);
void PhatSinhMang(int a[], int n);
void XuatMang(int a[], int n);
int GhiMangVaoFileText(char *filename, int a[], int n);
int DocFileTextVaoMang(char *filename, int a[], int *n);

int main() {
    char *filename = "VD1Text.txt";
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    PhatSinhMang(a, n);
    XuatMang(a, n);

    GhiMangVaoFileText(filename, a, n);

    int b[n];
    DocFileTextVaoMang(filename, b, &n);
    XuatMang(b, n);

    return 0;
}

void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
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
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int GhiMangVaoFileText(char *filename, int a[], int n) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Can't open the file");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d\t", a[i]);
    }
    
    fclose(f);
    return 1;
}

int DocFileTextVaoMang(char *filename, int a[], int *n) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Can't open the file");
        return 0;
    }
    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%d", &a[i]);
        i++;
    }
    *n = i;
    return 1;
}