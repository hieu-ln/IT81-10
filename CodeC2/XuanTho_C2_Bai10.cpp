// Bai 10 - Chuong 2 - Lad 4  Stack linked list
#include <iostream>
using namespace std;

// 10.1 Khai bao cau truc STACK
struct Node {
	int info;
	Node *link;
};
Node *sp; // luu tru dia chi phan tu dau tien cua stack

// 10.2 Khoi tao STACK rong
void init() {
	sp = NULL;
}

// 10.3 Kiem tra STACK
int isEmpty() {
	if (sp == NULL)
		return 1;
	return 0;
}

// 10.4 Them phan tu vao STACK
void Push(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

// 10.5 Lay phan tu ra khoi STACK
int Pop(int &x) {
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = sp->link;
		delete p;
		return 1;
	}
	return 0;
}

// 10.6 Doi he 10 sang he 2 
int Convert(int n)
{
	init();
	int snp = 0;
	while(n != 0)
	{
		int sodu = n % 2;
		Push(sodu);
		n /= 2;
	}
	while(!isEmpty())
	{
		int temp;
		if(Pop(temp))
			snp = snp * 10 + temp; 
		else
			break;
	}
	return snp;
}

// Xuat STACK
void Process_stack() {
	Node *p = sp;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
	cout << endl;
}
int main()
{
	int choice, x, i;
	char tt;
	do{
		system("cls");
		cout << "\n -----> BAI TAP 10 - CHUONG 2 - STACK (LINKED LIST) <----- \n";
		cout << "\n1. Khoi tao STACK rong\n";
		cout << "\n2. Them phan tu vao STACK \n";
		cout << "\n3. Lay phan tu ra khoi STACK \n";
		cout << "\n4. Xuat STACK \n";
		cout << "\n5. Chuyen he thap phan sang nhi phan \n"; 
		cout << "\nBan chon : "; cin >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "\nBan da khoi tao STACK thanh cong ! \n";
				break;
			case 2:
				cout << "\nVui long nhap gia tri x = "; cin >> x;
				Push(x);
				cout << "\nSTACK sau khi them la: ";
				Process_stack();
				break;
			case 3:
				Pop(x);
				cout << "\nSTACK sau khi lay ra la: ";
				Process_stack();
				break;
			case 4:
				cout << "\nSTACK hien tai la: ";
				Process_stack();
				break;
			case 5:
				cout << "\nNhap so nguyen (decimal): "; cin >> x;
				cout << "\nSo sau khi chuyen sang nhi phan(binary): " << Convert(x) << endl;
				break;
			default:
				cout << "\nBan da chon sai cac yeu cau tren !!! \n";
		}
		cout << "\nBan co muon tiep tuc khong (Y / N): "; cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}