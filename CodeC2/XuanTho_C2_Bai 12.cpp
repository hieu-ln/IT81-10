// Bai 12 - Chuong 2 - Bai lam them (DS lien ket Kep)
#include <iostream>
using namespace std;

// 12. 1 Khai bao cau truc ds
struct Node{
	int info;
	Node *next, *previous;
};
Node *first, *last;

//12.2 Khoi tao rong
void init()
{
	first = NULL;
	last = NULL;
}
// Note: con tro first , last duoc khai bao toan cuc trong chuong trinh

// duyet tu dau ve cuoi 
void Process_list() 
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}
// duyet tu cuoi len dau
void Process_list_begin_last()
{
	Node* p;
	p = last;
	while(p != NULL)
	{
		cout << p->info << " ";
		p = p->previous;
	}
	cout << endl;
}

// 12.4 Them mot phan tu vao dau ds
void Insert_first(int x)
{
	Node *p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
		first->previous = p;
	else // Nguoc lai ds rong, truoc khi them p
		last = p; // sau khi them phan tu p, ds co 1 phan tu
	first = p;
}

// 12.5 Them mot phan tu vao cuoi ds
void Insert_last(int x)
{
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
		last->next = p;
	else // danh sach rong, truoc khi them p
		first = p; // sau khi them phan tu p. ds co 1 phan tu
	last = p;
}

// 12.6 Xoa mot phan tu o dau danh sach
int Delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->next;
		delete p;
		if (first != NULL) // truong hop ds khac phan tu rong nao
			first->previous = NULL;
		else
			last = NULL; // truong hop ds khong con phan tu nao
		return 1;
	}
	return 0;
}

// 12.7 Xoa phan tu cuoi danh sach
int Delete_last()
{
	if (last != NULL)
	{
		Node *p = last;
		last = last->previous;
		if (last != NULL) // truong hop ds khac rong
			last->next = NULL;
		else
			first = NULL; // ds khong con phan tu nao
		delete p;
		return 1;
	}
	return 0;
}

//Tim kiem phan tu
Node* Search(int x)
{
	Node *p = first;
	while ((p != NULL) && (p->info != x))
		p = p->next;
	return p;
}
// 12.8 Tim phan tu trong ds tim thay xoa (neu co)
int searchAndDelete(int x)
{
	Node *p = Search(x);
	if (p != NULL)
	{
		if (p == first)
		{
			if(Delete_first())
				return 1;
			else
				return 0;
		}
		else if (p == last)
			{
				if (Delete_last())
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

// Ham menu

int main()
{
	int x, kq, choice;
	Node *i;
	cout << "\n----->	BAI 12 - CHUONG 2 - DANH SACH LIEN KET KEP	<-----\n";
	cout << "\n1. Khoi tao danh sach rong !\n";
	cout << "\n2. Them phan tu vao dau DSLK\n";
	cout << "\n3. Them phan tu vao cuoi DSKL\n";
	cout << "\n4. Xuat cac phan tu\n";
	cout << "\n5. Tim kiem phan tu trong DSLK\n";
	cout << "\n6. Xoa phan tu dau DSLK\n";
	cout << "\n7. Xoa phan tu cuoi DSLK\n";
	cout << "\n8. Tim phan tu va xoa (neu tim thay)\n";
	cout << "\n9 Thoat\n";
	do{
		cout << "\nVui long ban chon so de thuc hien: "; cin >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "\nBan da khoi tao thanh cong !\n";
				break;
			case 2:
				cout << "\nVui long nhap gia tri can them x = "; cin >> x;
				Insert_first(x);
				cout << "\nDanh sach phan tu vua them vao la: ";
				Process_list();
				break;
			case 3:
				cout << "\nVui long nhap gia tri can them x = "; cin >> x;
				Insert_last(x);
				cout << "\nDanh sach phan tu vua them vao la: ";
				/*Process_list_begin_last();*/
				Process_list();
				break;
			case 4:
				cout << "\nDanh sach cac phan tu la: ";
				Process_list();
			/*	Process_list_begin_last();*/
				break;
			case 5:
				cout << "\nVui long nhap gia tri can them x = "; cin >> x;
				i = Search(x);
				if (i == NULL)
					cout << "\nKhong tim thay x = " << x << " tong danh sach\n";
				else
					cout << "\nTim thay x = " << x << " trong danh sach \n";
				break;
			case 6:
				if (Delete_first() == 1)
				{
					cout << "\nDa xoa thanh cong phan tu dau  !\n";
					cout << "\nDanh sach sau khi xoa la: ";
					Process_list();
				}
				else
					cout << "\nXoa khong thanh cong !\n";
				break;
			case 7:
				if (Delete_last() == 1)
				{
					cout << "\nDa xoa thanh cong phan tu cuoi!\n";
					cout << "\nDanh sach sau khi xoa la: ";
					/*Process_list_begin_last();*/
					Process_list();
				}
				else
					cout << "\nXoa khong thanh cong !\n";
				break;
			case 8:
				cout << "\nVui long nhap gia tri can tim x = "; cin >> x;
				kq = searchAndDelete(x);
				if (kq == 1)
				{
					cout << "\nDa tim thay va xoa thanh cong phan tu x = " << x << " trong danh sach\n";
					cout << "\nDanh sach sau khi xoa la: ";
					Process_list();
				}
				else
					cout << "\nXoa khong thanh cong !\n";
				break;
			case 9:
				cout << "\nGoodbye !!!\n";
				break;
			default:
				break;

		}
	}while (choice != 9);
	return 0;
}