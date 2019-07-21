// Single Linked List
#include <iostream>
using namespace std;

// 3.1 Khai bao cau truc danh sach
struct Node {
	int info; // du lieu chua trong 1 Node
	Node *link; // con tro dung de lien ket giua cac Node voi nhau
};
Node *first;

// 3.2 Khoi tao danh sach rong
void Init() {
	first = NULL;
}

// 3.3 Xuat cac phan tu trong DS
void Process_list() {
	Node *p;
	p = first;
	while (p != NULL) {
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

// 3.4 Tim mot phan tu trong DS
Node *Search(int x) {
	Node *p = first;
	while(p != NULL && p->info != x) {
		p = p->link;
	}
	return p;
}

// 3.5 Them phan tu vao dau DS
void Insert_First(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

// 3.6 Xoa phan tu dau DS
int Delete_First() {
	if (first != NULL) {
		Node *p = first;
		first = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// 3.7 Them phan tu cuoi DS
void Insert_Last(int x) {
	Node *p = new Node ;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

// 3.8 Xoa phan tu cuoi danh sach
int Delete_Last() {
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = NULL;
		while (p->link != NULL) {
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

// 3.9 Tim phan tu trong DS, roi xoa phan tu neu tim thay
int SearchAndDelete(int x) {
	if (first != NULL) {
		Node *p, *q;
		p = first;
		q = first;
		while(p->info != x && p->link != NULL) {
			q = p;
			p = p->link; 
		}
		if(p->link != first && p->link != NULL) {
			// Phan tu giua ds
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if(p == first) 
		{
			// Phan tu dau ds
			first = p->link;
			delete p;
			return 1;
		}
			else if(p->link == NULL && p->info == x) 
			{
				// Phan tu cuoi ds
				q->link = NULL;
				delete p;
				return 1;
			}
				else
					return 0;
	}
	return 0;
}

// Hoan doi cho giua 2 gia tri
void Swap(Node *a, Node *b) {
	int temp = a->info;
	a->info = b->info;
	b->info = temp;
}

// 3.10 Sap xep danh sach co thu tu tang dan 
// Su dung Selection Sort
void Sort() {
	Node *p, *q, *min;
	// Di chuyen ranh gioi cua cac mang sap xep va chua sap xep
	p = first;
	while (p != NULL) {
		// Tim phan tu nho nhat trong mang chua duoc sap xep
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info <  min->info) 
			{
				min = q;
			}
			q = q->link;
		}
		// Doi cho phan tu nho nhat voi phan tu dau tien
		Swap(min, p);
		p = p->link;
	}
}

// 3.10 Sap xep danh sach co thu tu giam dan 
// Su dung Selection Sort
void SortDesc() {
	Node *p, *q, *min;
	// Di chuyen ranh gioi cua cac mang sap xep va chua sap xep
	p = first;
	while (p != NULL) {
		// Tim phan tu nho lon trong mang chua duoc sap xep
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info >  min->info) 
			{
				min = q;
			}
			q = q->link;
		}
		// Doi cho phan tu nho lon voi phan tu dau tien
		Swap(min, p);
		p = p->link;
	}
}

// Ham chinh
int main() {
	int x, i, choice = 0;
	Node *p;
	cout << "\n ----------> BAI TAP 3 - CHUONG 2 - DANH SACH LIEN KET DON <---------- \n";
	cout << "\n1. Khoi tao DSLK DON rong \n";
	cout << "\n2. Them phan tu vao dau DSLK DON \n";
	cout << "\n3. Them phan tu vao cuoi DSLK DON \n";
	cout << "\n4. Xoa phan tu dau DSLK DON \n";
	cout << "\n5. Xoa phan tu cuoi cung DSLK DON \n";
	cout << "\n6. Xuat DSLK DON \n";
	cout << "\n7. Tim kiem mot phan tu gia tri x trong DSLK DON \n";
	cout << "\n8. Tim kiem mot phan tu gia tri x va xoa neu co \n";
	cout << "\n9. Sap xep DSLK DON tang dan \n";
	cout << "\n10, Sap xep DSLK DON giam dan \n";
	cout << "\n11. Thoat \n";
	do{
		cout << "\nVui long chon so de thuc hien: "; cin >> choice;
		switch(choice){
			case 1:
				Init();
				cout << "\nBan da khoi tao DSLK DON thanh cong ! \n";
				break;
			case 2:
				cout << "\nVui long nhap gia tri x = ";
				cin >> x;
				Insert_First(x);
				cout << "\nDanh sach sau khi them la: ";
				Process_list();
				break;
			case 3:
				cout << "\nVui long nhap gia tri x = ";
				cin >> x;
				Insert_Last(x);
				cout << "\nDanh sach sau khi them la: ";
				Process_list();
				break;
			case 4:
				i = Delete_First();
				if (i == 0)
					cout << "\nDanh sach rong, khong the xoa ! \n";
				else
				{
					cout << "\nDa xoa thanh cong phan tu dau cua DSLK DON ! \n";
					cout << "\nDanh sach sau khi xoa la: ";
					Process_list();
				}
				break;
			case 5:
				i = Delete_Last();
				if (i == 0)
					cout << "\nDanh sach rong, khong the xoa ! \n";
				else
				{
					cout << "\nDa xoa thanh cong phan tu cuoi cua DSLK DON ! \n";
					cout << "\nDanh sach sau khi xoa la: ";
					Process_list();
				}	
				break;
			case 6:
				cout << "\nDanh sach hien tai la: ";
				Process_list();
				break;
			case 7:
				cout << "\nVui long nhap gia tri can tim x = "; cin >> x;
				p = Search(x);
				if (p != NULL)
					cout << "\nDa tim thay phan tu co gia tri x = " << x << endl;
				else
					cout << "\nKhong tim thay phan tu co gia tri  x = " << x << endl;
				break;
			case 8:
				cout << "\nVui long nhap gia tri can tim x = "; cin >> x;
				i = SearchAndDelete(x);
				if (i == 1)
				{
					cout << "\nDa tim thay x = " << x << " va da xoa thanh cong ! \n";
					cout << "\nDanh sach sau khi tim thay va xoa la: ";
					Process_list();
				}
				else
					cout << "\nKhong tim thay gia tri x = " << x << endl;
				break;
			case 9:
				Sort();
				cout << "\nDanh sach sau khi sap xep tang dan la: ";
				Process_list();
				break;
			case 10:
				SortDesc();
				cout << "\n Danh sach sau khi sap xep giam dan la: ";
				Process_list();
				break;
			case 11: 
				cout << "\n Good Bye :)) !! \n";
				break;
			default:
				break;
		}
	}while(choice != 11);
	return 0;
}