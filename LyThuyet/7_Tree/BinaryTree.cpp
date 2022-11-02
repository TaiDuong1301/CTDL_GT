#include<iostream>

typedef struct TNODE
{
    int data;
    TNODE *pLeft, *pRight;
};

typedef TNODE *TREE;

void NLR(TREE t);
void LNR(TREE t);
void LRN(TREE t);
TNODE *searchNode_Recursion(TREE t, int x);
TNODE *searchNode(TREE t, int x);
int insertNode(TREE &t, int x);
int delNode(TREE &t, int x);
void searchStandFor(TREE &p, TREE &q);
void removeTree(TREE &t);


int CountLeaf(TREE t);

int main()
{
    
    return 0;
}
/**
 * @brief Duyệt theo thứ tự đứng trước - Preorder
 * Node-left-right
 * Thăm nút gốc rồi rồi sau đó thăm các nút của cây con trái rồi đến cây con phải
 * 
 * @param t 
 */
void NLR(TREE t)
{
    if (t != NULL)
    {
        //Xu ly t
        NLR(t->pLeft);
        NLR(t->pRight);
    }
    
}
/**
 * @brief Duyệt theo thứ tự giữa - inorder.
 * Left-node-right .
 * Đầu tiên thăm các nút của cây con trái sau đó thăm nút gốc rồi thăm cây con phải.
 * 
 * @param t 
 */
void LNR(TREE t)
{
    if (t != NULL)
    {
        LNR(t->pLeft);
        // Xu ly t
        LNR(t->pRight);
    }
    
}
/**
 * @brief Duyệt theo thứ tự sau - postorder
 * Left-Right-Node 
 * 
 * @param t 
 */
void LRN(TREE t)
{
    if (t != NULL)
    {
        LRN(t->pLeft);
        LRN(t->pRight);
        // Xu ly t
    }
    
}
/**
 * @brief Tìm một phần tử x trong CNPTK (dùng đệ quy)
 * 
 * @param t 
 * @param x 
 * @return TNODE* 
 */
TNODE *searchNode_Recursion(TREE t, int x)
{
    if (t)
    {
        if (t->data == x)
        {
            return t;
        }
        else if (t->data > x)
        {
            return searchNode(t->pLeft, x);
        }
        else
        {
            return searchNode(t->pRight, x);
        }
        
    }
    return NULL;
    
}
/**
 * @brief Tìm một phần tử x trong CNPTK (dùng vòng lặp)
 * 
 * @param t 
 * @param x 
 * @return TNODE* 
 */
TNODE *searchNode(TREE t, int x)
{
    TNODE *p = t;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p;
        }
        else if (p->data > x)
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
/**
 * @brief Thêm một phần tử vào cây
 * 
 * @param t 
 * @param x 
 * @return -1 Khi không đủ bộ nhớ, 0 khi gặp nút cũ, 1 khi thêm thành công
 */
int insertNode(TREE &t, int x)
{
    if (t)
    {
        if (t->data == x)
        {
            return 0;
        }
        if (t->data > x)
        {
            return insertNode(t->pLeft, x);
        }
        else
        {
            return insertNode(t->pRight, x);
        }
        
    }
    t = new TNODE;
    if (t == NULL)
    {
        return -1;
    }
    t->data = x;
    t->pLeft = t->pRight = NULL;
    return 1;
}
/**
 * @brief Hủy một phần tử có khóa X 
 * 
 * @param t 
 * @param x 
 * @return int 
 */
int delNode(TREE &t, int x)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->data > x)
    {
        return delNode(t->pLeft, x);
    }
    if (t->data < x)
    {
        return delNode(t->pRight, x);
    }
    TNODE *p = t;
    if (t->pLeft == NULL)
    {
        t = t->pRight;
    }
    else
    {
        if (t->pRight == NULL)
        {
            t = t->pLeft;
        }
        else
        {
            searchStandFor(p, t->pRight);
        }
    }
    
}
/**
 * @brief Tìm phần tử thế mạng 
 * 
 * @param p 
 * @param q 
 */
void searchStandFor(TREE &p, TREE &q)
{
    if (q->pLeft)
    {
        searchStandFor(p, q->pLeft);
    }
    else
    {
        p->data = q->data;
        p = q;
        q = q->pRight;
    }
}
/**
 * @brief Đếm số node lá
 * 
 * @param t 
 * @return int 
 */
int CountLeaf(TREE t)
{
    if (t == NULL)
    {
        return 0;
    }
    else if (t->pLeft == NULL && t->pRight == NULL)
    {
        return 1;
    }
    else
    {
        return CountLeaf(t->pLeft) + CountLeaf(t->pRight);
    }
}
/**
 * @brief Huỷ toàn bộ cây
 * 
 * @param t 
 */
void removeTree(TREE &t)
{
    if (t)
    {
        removeTree(t->pLeft);
        removeTree(t->pRight);
        delete(t);
    }
    
}