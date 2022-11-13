#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct TNODE
{
    int data;
    TNODE *pLeft, *pRight;
};
typedef TNODE *TREE;

TNODE *TaoNode(int x);
void ThemNodeVaoCay(TREE &t, TNODE *p);
void Nhap(TREE &t);


int main()
{
    TREE t = NULL;
    int n;
    Nhap(t);

    return 0;
}

TNODE *TaoNode(int x)
{
    TNODE *p = new TNODE;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->data = x;
    return p;
}

void ThemNodeVaoCay(TREE &t, TNODE *p)
{
    if (t == NULL)
    {
        t = p;
    }
    else
    {
        if (p->data < t->data)
        {
            ThemNodeVaoCay(p, t->pLeft);
        }
        else if (p->data > t->data)
        {
            ThemNodeVaoCay(p, t->pRight);
        }
        else
        {
            return;
        }
        
    }
    
}

void Nhap(TREE &t)
{
    FILE *fptr = fopen("input.txt","r");
    int temp;

    if (fptr == NULL){
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    // while (!feof(fptr))
    // {
    //     fscanf(fptr,"%d", &temp);
    //     TNODE *p = TaoNode(temp);
    //     ThemNodeVaoCay(t, p);
    //     printf("%d\t", temp);
    // }
    
    fscanf(fptr,"%d", &temp);
    printf("%d\t", temp);

    fclose(fptr); 
    
}