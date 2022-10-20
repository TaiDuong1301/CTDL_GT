/**
 * @file QLSV.cpp
 * @author DuongVanTai_21136801 (21136801.tai@student.iuh.edu.vn)
 * @brief Bai thuc hanh so 5, van de 1
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string.h>

typedef struct Ngay
{
    int ngay, thang, nam;
};

typedef struct SinhVien
{
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

typedef struct Node
{
    SinhVien data;
    Node *link;
};

typedef struct List 
{
    Node *first;
    Node *last;
};

//Khoi tao danh sach rong
void init(List &l);
//gan node new_ele vao danh sach
void AddLast(List &l, Node *new_ele);
// them mot node voi du lieu la sinh vien x
void InsertLast(List &l, SinhVien x);
// tao node moi voi du lieu la sinh vien x
Node *GetNode(SinhVien x);
// ham nhap mot sinh vien. nhap thanh cong tra ve 1, nhap khong thanh cong (maSV  = 0) thi tra ve 0
int NhapSinhVien(SinhVien &x);
// ham nhap danh sach sinh vien, nhap 0 de dung
void NhapDSSV(List &l);
//Ham xuat mot sinh vien
void XuatSinhVien(SinhVien s);
// ham xuat danh sach sinh vien
void XuatDSSV(List l);

int main()
{
    List(l);
    init(l);
    NhapDSSV(l);
    XuatDSSV(l);
    return 0;
}

void init(List &l)
{
    l.first = l.last = NULL;
}

Node *GetNode(SinhVien x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho");
        return NULL;
    }
    p->data = x;
    p->link = NULL;
    return p;
}

void AddLast(List &l, Node *new_ele)
{
    if (l.first == NULL)
    {
        l.first = l.last = new_ele;
    }
    
    l.last->link = new_ele;
    l.last = new_ele;
}

void InsertLast(List &l, SinhVien x)
{
    Node *p = GetNode(x);
    AddLast(l, p);
}

int NhapSinhVien(SinhVien &x)
{
    printf("Ma so sinh vien: ");
    fflush(stdin);
    gets(x.maSV);
    if (strcmp(x.maSV, "0") == 0)
    {
        return 0;
    }
    printf("Ho va ten: ");
    fflush(stdin);
    gets(x.hoTen);
    printf("Gioi tinh: ");
    fflush(stdin);
    scanf("%d", &x.gioiTinh);
    printf("Ngay thang nam sinh: ");
    fflush(stdin);
    scanf("%d %d %d", &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam);
    printf("Dia chi: ");
    fflush(stdin);
    gets(x.diaChi);
    printf("Lop: ");
    fflush(stdin);
    gets(x.lop);
    printf("Khoa: ");
    fflush(stdin);
    gets(x.khoa);
    return 1;
}

void NhapDSSV(List &l)
{
    printf("\nBat dau nhap DSSV. Nhap maSV = 0 de dung\n");
    SinhVien x;
    int flag = NhapSinhVien(x);
    while (flag)
    {
        InsertLast(l, x);
        flag = NhapSinhVien(x);
    }
    printf("\nKet thuc nhap DSSV.");
}

void XuatSinhVien(SinhVien s)
{
    char gt[4];
    if (s.gioiTinh == 0)
    {
        strcpy(gt, "Nam");
    }
    else
    {
        strcpy(gt, "Nu");
    }
    printf("\n%10s|%20s|%5d/%d/%d|%5s|%40s|%8s|%8s", s.maSV, s.hoTen, s.ngaySinh.ngay, s.ngaySinh.thang, s.ngaySinh.nam, gt, s.diaChi, s.khoa, s.lop);
    
}

void XuatDSSV(List l)
{
    Node *p = l.first;
    while (p != NULL)
    {
        XuatSinhVien(p->data);
        p = p->link;
    }
    
}