#include<iostream>
#include<string.h>

struct item
{
    char masv[20];
    char name[20];
    double diem;
};

struct NODE
{
    item key;
    NODE *pLeft, *pRight;
};
typedef NODE *TREE;

NODE *TaoNode(item x);
void ThemNodeVaoCay(NODE *p, TREE &c);
void Nhap(TREE &c);
void Xuat(TREE c);
int NhapSinhVien(item &x);
void XuatSinhVien(item x);
NODE *searchNode(TREE t, item x);



int main()
{
    TREE c = NULL;
    Nhap(c);
    printf("Xuat cay LRN (tang dan): ");
    Xuat(c);
    return 0;
}

NODE *TaoNode(item x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        return NULL;
    }
    p->pLeft = NULL;
    p->pRight = NULL;
    p->key = x;
    return p;
}


void ThemNodeVaoCay(NODE *p, TREE &c)
{
    if (c == NULL)
    {
        c = p;
    }
    else
    {
        if (p->key.masv < c->key.masv)
        {
            ThemNodeVaoCay(p, c->pLeft);
        }
        else if (p->key.masv > c->key.masv)
        {
            ThemNodeVaoCay(p, c->pRight);
        }
        else
        {
            return;
        }
        
    }
}

void Nhap(TREE &c)
{
    int chon = 0;
    do
    {
        item x;
        NhapSinhVien(x);
        while (searchNode(c, x) != NULL)
        {
            printf("Trung masv, moi nhap lai: ");
            NhapSinhVien(x);
        }
        NODE *p = TaoNode(x);
        ThemNodeVaoCay(p, c);
        printf("Muon nhap thong tin tiep theo khong? 1: co, 0: khong >> ");
        scanf("%d", &chon);
    } while (chon);
    
}

void Xuat(TREE c)
{
    if (c != NULL)
    {
        if (c->pLeft != NULL)
        {
            Xuat(c->pLeft);
        }
        XuatSinhVien(c->key);
        if (c->pRight != NULL)
        {
            Xuat(c->pRight);
        }
        
        
    }
    
}

int NhapSinhVien(item &x)
{
    printf("Ma so sinh vien: ");
    fflush(stdin);
    gets(x.masv);
    if (strcmp(x.masv, "0") == 0)
    {
        return 0;
    }
    printf("Ho va ten: ");
    fflush(stdin);
    gets(x.name);
    printf("Diem: ");
    fflush(stdin);
    scanf("%lf", &x.diem);
    return 1;
}
void XuatSinhVien(item x)
{
    printf("\n|%20s|%20s|%5.2lf|", x.masv, x.name, x.diem);
}
/**
 * @brief Tìm một phần tử x trong CNPTK (dùng vòng lặp)
 * 
 * @param t 
 * @param x 
 * @return TNODE* 
 */
NODE *searchNode(TREE t, item x)
{
    NODE *p = t;
    while (p != NULL)
    {
        if (strcmp(p->key.masv, x.masv) == 0)
        {
            return p;
        }
        else if (strcmp(p->key.masv, x.masv) > 0)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
        
    }
    return NULL;

}
