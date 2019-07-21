#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *first;
void Init()
{
	first = NULL;
}

void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

void Insert (int x)
{
	Node *p, *q, *before;
	p = new Node;
	p->info = x;
	q = first;
	while (q != NULL && q->info > x)
	{
		before = q;
		q = q->link;
	}
	if (q == first)
		first = p;
	else
		q->link = p;
	p->link = q;
}
void output()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}


Node *Search(int x)
{
	Node *p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

int del_f()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

int del_l()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int Search_Del(int x)
{
	if (Search(x) != NULL)
	{
		Node *t = Search(x);
		if (t == first)
		{
			if (del_f())
				return 1;
		}
		else
			if (t->link == NULL)
			{
				if (del_l())
					return 1;
			}
			else
			{
				Node *q = first, *p = first;
				while (p != t)
				{
					q = p;
					p = p->link;
				}
				q->link = t->link;
				delete t;
				return 1;
			}
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "\t\t\n\nMenu \t\t\n\n" << endl;
	cout << "1.Khoi tao danh sach rong" << endl;
	cout << "2.Them 1 phan tu vao vi tri phu hop" << endl;
	cout << "3.Xuat danh sach" << endl;
	cout << "4.Tim 1 phan tu" << endl;
	cout << "5.Tim va xoa 1 phan tu " << endl;
	cout << "6.Thoat " << endl;
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao danh sach rong thanh cong! " << endl;
			break;
		case 2:
			int y;
			cout << "Nhap phan tu can them: ";
			cin >> y;
			Insert(y);
			break;
		case 3:
			cout << "Danh sach hien tai la: ";
			output();
			break;
		case 4:
			cout << "Vui long nhap gia tri can tim ";
			cin >> x;
			p = Search(x);
			if (p != NULL)
				cout << "Tim thay phan tu " << endl;
			else
				cout << "Khong tim thay "  << endl;
			break;
		case 5:
			cout << "Nhap gia tri x: ";
			cin >> x;
			if (Search_Del(x))
			{
				cout << " da xoa thanh cong " << endl;
			}
			else
				cout << " xoa khong thanh cong " << endl;
			break;
		case 6:
			cout << "Goodbye.....!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	return 0;
}