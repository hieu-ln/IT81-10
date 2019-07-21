// bai 12 thuc hanh 2
#include <iostream>
using namespace std;

struct Node {
	int infor;
	Node *next;
	Node *previous;

};
Node *first;
Node *last;

void init()
{
	first = NULL;
	last = NULL;
}

void output()
{
	Node * p;
	p = first;
	while (p != NULL)
	{
		cout << p->infor << endl;
		p = p->next;
	}

}

void Insert_First(int x)
{
	Node *p;
	p = new Node;
	p->infor = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
	{
		first->previous = p;
	}
	else
	{
		last = p;
	}
	first = p;
}

void Insert_Last(int x)
{
	Node *p;
	p = new Node;
	p->infor = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
		last->next = p;
	else
		first = p;
	last = p;
}

int Delete_First()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->next;
		delete p;
		if (first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		return 1;
	}
	return 0;
}

int Delete_Last()
{
	if (last != NULL)
	{
		Node *p = last;
		last = last->previous;
		if (last != NULL)
			last->next = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

Node* Seach(int x)
{
	Node *p;
	p = first;
	while ((p != NULL) && (p->infor != x))
	{
		p = p->next;
	}
	return p;
}

int Delete_Seach(int x)
{
	Node *p = Seach(x);
	if (p != NULL)
	{
		if (p == first)
		{
			if (Delete_First())
				return 1;
			else
				return 0;
		}
		else if (p == last)
		{
			if (Delete_Last())
				return 1;
			else
				return 0;

		}
		else
		{
			Node *q;
			q = p->previous;
			q->next = p->next;
			(p->next)->previous = q;
			delete p;
			return 1;
		}
	}
	return 0;
}
// them 1 phan tu co gia tri bang x, neu khong bang x thi so chen vao so lon hon gia tri x
//int Insert(Node *p, int x, int y)
//{
//	Node *p = Seach(x);
//	if (p == first)
//	{
//		Insert_First(y);
//		return 1;
//	}
//	else if (p == last)
//	{
//		Insert_Last(y);
//		return 1;
//	}
//	else
//	{
//		Node * q;
//		q->infor = y;
//
//
//	}
//}
// con ham dem NOde nua
int main()
{
	int chon = 0;
	system("cls");
	cout << "\n\n\t\t Menu \t\t\n\n" << endl;
	cout << "1. Khoi tao " << endl;
	cout << "2. Xuat danh sach " << endl;
	cout << "3. Them mot phan tu vao dau danh sach " << endl;
	cout << "4. Them mot phan tu vao cuoi danh sach " << endl;
	cout << "5. Xoa mot phan tu dau danh sach " << endl;
	cout << "6. Xoa mot phan tu cuoi danh sach" << endl;
	cout << "7. Tim phan tu " << endl;
	cout << "8. Tim va Xoa phan tu" << endl;
	cout << "10. Thoat" << endl;
    do {
		do {
			cout << "Nhap vao lua chon cua ban: ";
			cin >> chon;
			if (chon < 0 || chon > 8)
				cout << " Nhap sai, Nhap lai" << endl;
		} while (chon < 0 || chon > 8);
		switch (chon)
		{
		case 1:
			cout << " Danh sach da duoc khoi tao thanh cong " << endl;
			init();
			break;
		case 2:
			cout << " Danh sach la : " << endl;
			output();
			break;
		case 3:
			int x;
			cout << "Nhap vao gia tri mot phan tu ban muon them vao dau danh sach :  ";
			cin >> x;
			Insert_First(x);
			break;
		case 4:
			int y;
			cout << "Nhap gia tri phan tu ban muon them vao cuoi danh sach : ";
			cin >> y;
			Insert_Last(y);
			break;
		case 5:
			if ((Delete_First()) == 1)
				cout << "Xoa phan tu tai vi tri dau thanh cong ! " << endl;
			else
				cout << "Xoa khong thanh cong " << endl;
			break;
		case 6:
			if (Delete_Last() == 1)
				cout << "Xoa phan tu tai vi tri cuoi thanh cong" << endl;
			else
				cout << "Xoa khong thanh cong " << endl;
			break;
		case 7:
			int z;
			cout << "nhap vao gia tri ban muon tim : " << endl;
			cin >> z;
			if (Seach(z) == NULL)
				cout << "Khong tim thay phan tu !" << endl;
			else
				cout << "tim thay phan tu tai vi tri " << int(Seach(z)) << endl;
			break;
		case 8:
			int k;
			cout << "nhap vao gia tri ban muon xoa trong danh sach : ";
			cin >> k;
			if (Delete_Seach(k))
				cout << " Xoa phan tu thanh cong !" << endl;
			else
				cout << "xoa phan tu khong thah cong !" << endl;
			break;
		case 9:
			break;
		case 10:
			cout << "Thoat !";
			break;
		default:
			break;
		}
	} while (chon != 10);
	system("pause");
	return 0;
}