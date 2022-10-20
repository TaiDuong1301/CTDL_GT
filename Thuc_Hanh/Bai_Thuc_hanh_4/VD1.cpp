#include <iostream>

struct NODE
{
	float heSo;
	int soMu;
	NODE *link;	
};

struct LIST
{
	NODE *pHead;
	NODE *pTail;
};

NODE *GetNode(float heso, int somu);
void Init(LIST &l);
void addTail(LIST &l, NODE *new_ele);
void InsertTail(LIST &l, float he_so, int so_mu);
void NhapDaThuc(LIST &l);
void XuatDanhSach(LIST l);
void CongDaThuc(LIST d1, LIST d2, LIST &d3);
void InterchangeSort(LIST &l);
void BTVN(LIST &l);
void Swap1(float &a, float &b);
void Swap2(int &a, int &b);

int main()
{
	LIST d1, d2, d3;
	Init(d1);
	Init(d2);
	Init(d3);
	NhapDaThuc(d1);
	printf("\nDanh sach bieu dien da thuc d1: ");
	XuatDanhSach(d1);

	NhapDaThuc(d2);
	printf("\nDanh sach bieu dien da thuc d2: ");
	XuatDanhSach(d2);
	XuatDanhSach(d1);
	CongDaThuc(d1, d2, d3);
	printf("\nDanh sach bieu dien da thuc tong: ");
	XuatDanhSach(d3);
	// InterchangeSort(d3);
	BTVN(d3);
	return 0;
}
/**
 * @brief Tao moi node moi
 * 
 * @param he_so
 * @param so_mu
 * @return NODE
 */
NODE *GetNode(float he_so, int so_mu) 
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		printf("Error\n");
		return NULL;
	}
	p->heSo = he_so;
	p->soMu = so_mu;
	p->link = NULL;
	return p;
}
/**
 * @brief Khoi tao danh sach rong
 * @param LIST
 */
void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}
/**
 * @brief Gan node vao cuoi danh sach
 */
void addTail(LIST &l, NODE *new_ele)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = new_ele;
	}
	else
	{
		l.pTail->link = new_ele;
		l.pTail = new_ele;
	}
}
/**
 * @brief Them mot node voi du lieu la he so va so mu vao danh sach
 * @param LIST
 * @param he_so
 * @param so_mu
 */
void InsertTail(LIST &l, float he_so, int so_mu)
{
	NODE *new_ele = GetNode(he_so, so_mu);
	if (new_ele == NULL)
	{
		return;
	}
	addTail(l, new_ele);
}
/**
 * @brief Ham nhap da thuc
 * 
 * @param list
 */
void NhapDaThuc(LIST &l)
{
	float heSo;
	int soMu;
	printf("Bat dau nhap da thuc (nhap he so 0 de ket thuc): \n");
	do
	{
		printf("Nhap he so: ");
		scanf("%f", &heSo);
		if (heSo == 0)
		{
			break;
		}
		printf("Nhap so mu: ");
		scanf("%d", &soMu);
		InsertTail(l, heSo, soMu);
	} while (heSo != 0);
	printf("\nDa nhap da thuc xong: \n");
}
/**
 * @brief Xuat danh sach bieu dien da thuc
 * 
 * @param LIST
 */
void XuatDanhSach(LIST l)
{
	NODE *p;
	p = l.pHead;
	printf("\n");
	while(p != NULL)
	{
		printf("%.0fx^%d \t", p->heSo, p->soMu);
		p = p->link;
	}	
	printf("\n\n");
}

void CongDaThuc(LIST d1, LIST d2, LIST &d3)
{
	Init(d3);
	NODE *p = d1.pHead;
	NODE *q = d2.pHead;
	float tongHeSo;
	while(p && q)
	{
		if (p->soMu == p->soMu)	// Hai số mũ bằng nhau
		{
			tongHeSo = p->heSo + q->heSo;
			if (tongHeSo != 0)
			{
				InsertTail(d3, tongHeSo, p->soMu);
			}
			p = p->link;
			q = q->link;
		}
		else
		{
			if (p->soMu > q->soMu)
			{
				InsertTail(d3, p->heSo, p->soMu);
				p = p->link;
			}
			else
			{
				if (p->soMu < q->soMu)
				{
					InsertTail(d3, q->heSo, q->soMu);
					q = q->link;
				}
			}
		}
	}
	while(q)	// bieu thuc d1 ket thuc truoc
	{
		InsertTail(d3, q->heSo, q->soMu);
		q = q->link;
	}
	while(p)	// bieu thuc d2 ket thuc truoc
	{
		InsertTail(d3, p->heSo, p->soMu);
		p = p->link;
	}
}

void InterchangeSort(LIST &l)
{
	for (NODE *p = l.pHead; p != l.pTail; p = p->link)
	{
		for (NODE *q = p->link; q != NULL; q = q->link)
		{
			if (p->soMu > q->soMu)
			{
				Swap1(p->heSo, q->heSo);
				Swap2(p->soMu, q->soMu);
			}
		}
	}
}

void BTVN(LIST &l)
{
	NODE *p = l.pHead;
	while (p != NULL)
	{
		if (p->heSo > 0)
		{
			if (p->soMu == 0)
			{
				printf("+ %.0f ", p->heSo);
			}
			else
			{
				printf("+ %.0fx^%d ", p->heSo, p->soMu);
			}
		}
		else if (p->heSo < 0)
		{
			if (p->soMu == 0)
			{
				printf("- %.0f ", p->heSo);
			}
			else
			{
				printf("- %.0fx^%d ", p->heSo, p->soMu);
			}
		}
		p = p->link;
	}
	printf("\n");
}

void Swap1(float &a, float &b)
{
	float temp = a;
	a = b;
	b = temp;
}

void Swap2(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}