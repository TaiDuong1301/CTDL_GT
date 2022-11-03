#include<iostream>

struct NODE
{
    NODE *pLeft;
    NODE *pRight;
    int idata;
};

typedef NODE* TREE;

NODE *TaoNode(int x);
void ThemNodeVaoCay(NODE *p, TREE &c);
void Nhap(TREE &c);
void Xuat(TREE c);

int main()
{
    TREE c = NULL;
    Nhap(c);
    printf("Xuat cay LRN (tang dan): ");
    Xuat(c);
    return 0;
}

NODE *TaoNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        return NULL;
    }
    p->pLeft = NULL;
    p->pRight = NULL;
    p->idata = x;
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
        if (p->idata < c->idata)
        {
            ThemNodeVaoCay(p, c->pLeft);
        }
        else if (p->idata > c->idata)
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
        int x;
        printf("\nNhap x: ");
        scanf("%d", &x);
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
        printf("%4d", c->idata);
        if (c->pRight != NULL)
        {
            Xuat(c->pRight);
        }
        
        
    }
    
}
