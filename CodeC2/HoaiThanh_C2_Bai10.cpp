#include <iostream>
using namespace std;

struct Node {
	int info;
	Node *link;
};
Node* sp;

void init()
{
	sp = NULL;
}

int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

void outPut()
{
	Node* p = new Node;
	p = sp;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;

	}
	cout << endl;
}

int convert(int tp)
{
	init();
	while (tp != 0)
	{
		int d = tp % 2;
		push(d);
		tp /= 2;
	}
	int np = 0;
	while (isEmpty())
	{
		int so;
		if (Pop(so))
			np = np * 10 + so;
	}
	return np;
}

int main()
{
	int chon = 0;
	cout << "1. khoi tao" << endl;
	cout << "2. kiem tra rong " << endl;
	cout << "3. them mot phan tu " << endl;
	cout << "4. lay phan tu ra khoi stack " << endl;
	cout << "5. doi mot so thap phan thanh mot so nhi phan " << endl;
	cout << "6. xuat danh sach " << endl;
	cout << "7. thoat " << endl;
	do {
		cout << "vui long chon so de thuc hien :";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			cout << "khoi tao thanh cong " << endl;
			break;
		case 2:
			if (isEmpty())
				cout << "Mang rong " << endl;
			else
				cout << "mang khong rong " << endl;
			break;
		case 3:
			int x;
			cout << "nhap vao phan tu ban muon them " << endl;
			cin >> x;
			push(x);
			cout << "nhap phan tu thanh cong " << endl;
			break;
		case 4:
			int y;
			if (Pop(y))
				cout << "xoa thanh cong" << endl;
			else
				cout << "xoa khong thanh cong " << endl;
			break;
		case 5:
			int tp;
			cout << "nhap vao so ban muon chuyen: ";
			cin >> tp;
			cout << "ta duoc so : " << convert(tp) << endl;
			break;
		case 6:
			cout << "danh sach la : " << endl;
			outPut();
			break;
		case 7:
			cout << "Thoat " << endl;
			break;
		default:
			break;
		}
	} while (chon != 8);
	return 0;
}