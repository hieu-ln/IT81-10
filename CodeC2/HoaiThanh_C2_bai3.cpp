#include <iostream>
using namespace std;

struct Node {
	int infor; 
	Node* link;
};
Node* first;

void init()
{
	first = NULL;
}

void Duyetdanhsach()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->infor << endl;
		p = p->link;
	}
}

Node *Seach(int x)
{
	Node *p = first;
	while ((p != NULL) && (p->infor != x))
	{
		p = p->link;
	}
	return p;
}

void Insert_First(int x)
{
	Node * p;
	p = new Node;
	p->infor = x;
	p->link = first;
	first = p;
}

void Insert_Last(int x)
{
	Node * p;
	p = new Node;
	p->infor = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node * q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

int Delete_First()
{
	if (first != NULL)
	{
		Node * p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

int Delete_Last()
{
	Node * p = first;
	Node * q = first;
	if (first != NULL)
	{
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int Delete_Seach(int x)
{
	if (first != NULL)
	{
		Node* p = first;
		Node *q = first;
		while (p->infor != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			if (p->link == NULL)
			{
				q->link = p->link;
			}
			else
			{
				q->link = NULL;
			}
			delete p;
			return 1;

		}
		else if (p->link == NULL && p->infor == x)
		{
			q->link = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

void swap(Node * a, Node *b)
{
	int t = a->infor;
	a->infor = b->infor;
	b->infor = t;
}

void sort()
{
	Node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->infor < min->infor)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}

void sortDesc()
{
	Node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->infor > min->infor)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}

int main()
{
	int chon = 0;
	Node* p;
	system("cls");
	cout << "\t\t\n\n Menu \t\t\n\n" << endl;
	cout << " 1. khoi tao danh sach " << endl;
	cout << " 2. xuat danh sach  " << endl;
	cout << " 3. them phan tu dau mang " << endl;
	cout << " 4. them phan tu cuoi mang " << endl;
	cout << " 5. xoa phan tu dau mang " << endl;
	cout << " 6. xoa phan tu cuoi mang" << endl;
	cout << " 7. xoa phan tu co gia tri ban chon" << endl;
	cout << " 8. tim phan tu trong mang" << endl;
	cout << " 9. sap xep danh sach tang dan" << endl;
	cout << " 10. sap xep danh sach giam dan" << endl;
	cout << " 11. Thoat " << endl;
	do {
		cout << "chon so de thuc hien : ";
		cin >> chon;
		switch (chon)
		{
			case 1:
				init();
				cout << "khoi tao danh sach thanh cong " << endl;
				break;
			case 2:
				cout << "Danh sach la : " << endl;
				Duyetdanhsach();
				break;
			case 3:
				int x;
				cout << "nhap gia tri phan tu ma ban muon them vao dau mang : ";
				cin >> x;
				Insert_First(x);
				break;
			case 4:
				int y;
				cout << "nhap gia tri phan tu ma ban muon them vao cuoi mang : ";
				cin >> y;
				Insert_Last(y);
				break;

			case 5:
				if (Delete_First())
					cout << "xoa phan tu dau mang thanh cong !" << endl;
				else
					cout << "Danh Sach Rong !" << endl;
				break;
			case 6:
				if (Delete_Last())
					cout << "xoa phan tu cuoi mang thang cong" << endl;
				else
					cout << "Danh Sach Rong" << endl;
				break;
			case 7:
				int z;
				cout << "nhap vao gia tri phan tu ban muon xoa " << endl;
				cin >> z;
				if (Delete_Seach(z))
					cout << "xoa gia tri phan tu thanh cong" << endl;
				else
					cout << "xoa khong thanh cong " << endl;
				break;
			case 8:
				int k;
				cout << "nhap vao gia tri phan tu ban muon tim kiem : ";
				cin >> k;
				if (Seach(x))
					cout << "tim thay gia tri cua " << x << "tai vi tri " << int(Seach(x)) << endl;
				else
					cout << "khong tim thay " << x << endl;
				break;
			case 9:
				sort();
				cout << "Danh sach da duoc sap xep tang dan " << endl;
				break;
			case 10:
				sortDesc();
				cout << "Danh sap da duoc sap xep giam dan" << endl;
				break;
			case 11:
				cout << "Tam Biet !" << endl;
				break;
			default:
			break;
		}
	} while (chon != 11);
	system("pause");
	return 0;
}