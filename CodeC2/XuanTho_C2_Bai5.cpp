// Bai 5 -TH 3 - Chuong 2
#include <iostream>
using namespace std;

// 5.1 Khai bao Stack 
#define Max 100
int a[Max];

// 5.2 Khoi tao stack rong
void Init(int a[], int &sp){
	sp = -1;
}

// 5.3 Kiem tra stack rong
int isEmpty(int a[], int sp){
	if (sp == -1)
		return 1;
	return 0;
}

// 5.4 Kiem tra stack (ngan xep) co day chua
int isFull(int a[], int sp) {
	if (sp == Max - 1)
		return 1;
	return 0;
}

// 5.5 Them phan tu vao stack (ngan xep)
int Push(int a[], int &sp, int x) {
	if (sp < Max - 1) {
		a[++sp] = x;
		return 1;
	}
	return 0;
}

// 5.6 Xoa 1 phan tu
int Pop(int a[], int &sp, int &x){
	if (sp != -1)// Khi stack khac rong
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

// Xuat Stack
void Process_Stack(int a[], int sp) {
	for (int i = 0; i < sp + 1; i++) // sp + 1 co nghia la ?
		cout << a[i] << "\t";
	cout << endl;
}

// Ham chinh
int main()
{
	int sp, x, i, choice = 0; // dinh stack
	cout << "\n----->	BAI TAP  5 - CHUONG 2 - STACK (NGAN XEP - DS DAC)	<----- \n";
	cout << "\n1. Khoi tao STACK rong \n";
	cout << "\n2. Them phan tu vao STACK \n";
	cout << "\n3. Lay phan tu ra khoi STACK \n";
	cout << "\n4. Kiem tra STACK co rong hay khong !\n";
	cout << "\n5. Kiem tra STACK co day hay khong !\n";
	cout << "\n6. Xuat STACK \n";
	cout << "\n7. Thoat \n";
	do{
		cout << "\nVui long chon thuc hien: "; cin >> choice;
		switch(choice)
		{
			case 1:
				Init(a, sp);
				cout << "\nBan da khoi tao STACK rong thanh cong !\n";
				break;
			case 2:
				cout << "\nVui long nhap gia tri them vao x = "; cin >> x;
				i = Push(a, sp, x);
				cout << "\nSTACK sau khi them la: ";
				Process_Stack(a, sp);
				break;
			case 3:
				i = Pop(a, sp, x);
				cout << "\nPhan tu lay ra tu STACK la x = " << x << endl;
				cout << "\nSTACK sau khi lay ra la: ";
				Process_Stack(a, sp);
				break;
			case 4:
				i = isEmpty(a, sp);
				if (i == 0)
					cout << "\nSTACK khong rong !\n";
				else
					cout << "\nSTACK rong !\n";
				break;
			case 5:
				i = isFull(a, sp);
				if (i == 0)
					cout << "\nSTACK chua day !\n";
				else
					cout << "\nSTACK day ! \n";
				break;
			case 6:
				cout << "\nSTACK hien tai la: ";
				Process_Stack(a, sp);
				break;
			case 7:
				cout << "\nGoodbye....!!\n";
			default:
				break;
		}
	}while(choice != 7);
	return 0;
}