# include <stdio.h>
# include <stdlib.h>
#include <iostream>


struct SinhVien
{
    char Masv[8];
    char hoTen[20];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[50];
    char lop[12];
    char khoa[7];
    Diem diem;
    
};
struct Diem
{
    float tk,gk,ck,tong;
};
struct Ngay
{
    int ngay,thang,nam;
};


struct Node
{
    SinhVien data;
    Node *link;
};

struct List
{
    Node *Head,*Tail;
};

Node *GetNode(SinhVien x);
void Init(List &l);
void AddList(List &l, Node *new_ele);
void AddStudent(SinhVien sv);

int main()
{
    
    return 0;
}


Node *GetNode (SinhVien x)
{
    Node *p;
    p = new Node;
    if(p == NULL)
        return NULL;
    else
    {
        p->data = x;
        p->link = NULL;
    }
};

void Init(List &l) 
{
    l.Head = l.Tail = NULL;
};

void AddLast (List &l, Node *new_ele)
{
    if (l.Head == NULL)
    {
        l.Head=l.Tail=new_ele;
    }
    else
    {
        l.Tail -> link = new_ele;
        l.Tail = new_ele;
    }
};

void AddStudent(SinhVien sv) {
    printf("Enter StudentID: ");
    gets(sv.Masv);
    printf("Enter name: ");
    gets(sv.hoTen);
    printf("Enter gender: ");
    scanf("%d", sv.gioiTinh);
    printf("D.O.F: ");
    scanf("%d%d%d", sv.ngaySinh.ngay, sv.ngaySinh.thang, sv.ngaySinh.nam);
    printf("Enter address: ");
    gets(sv.diaChi);
    printf("Enter GPA: ");

}