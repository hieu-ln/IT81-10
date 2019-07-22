#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100

//cau 5.2: khoi tao stack rong
void init (int a[],int &sp)
{
	sp = -1;
}

//cau 5.3: kiem tra ngan xep rong
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

//cau 5.4: keim tra ngan xep day
int isFull(int a[], int sp)
{
	if(sp == MAX -1)
		return -1;
	return 0;
}

//cau 5.5: them phan tu vao ngan xep
int Push(int a[], int &sp, int x)
{
	if(sp < MAX -1)
	{
		a[++sp] = x;
		return -1;
	}
	return 0;
}

//cau 5.6: xoa 1 phan tu
int Pop(int a[], int &sp, int &x)
{
	if(sp != -1)
	{
		x = a[sp --];
		return -1;
	}
	return 0;
}

//xuat STACK
void Process_stack(int a[], int sp)
{
	for(int i = 0; i < sp + 1; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[MAX];
	int choice, sp, x, i;
	system("cls");
	cout << "-----BAI TAP 5, CHUONG 2, STACK-----\n";
	cout << "1. Khoi tao STACK rong\n";
	cout << "2. Them phan tu vao STACK\n";
	cout << "3. Lay phan tu ra khoi STACK\n";
	cout << "4. Kiem tra STACK co rong hay khong\n";
	cout << "5. Kiem tra STACK co day hay khong\n";
	cout << "6. Xuat STACK\n";
	cout << "7. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init(a, sp);
				cout << "Ban vua khoi tao STACK rong thanh cong!\n";
				break;
			case 2:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				i = Push(a, sp, x);
				cout << "STACK sau khi them la: ";
				Process_stack(a, sp);
				break;
			case 3:
				i = Pop(a, sp, x);
				cout << "Phan tu lay ra tu STACK la x = " << x << endl;
				Process_stack(a, sp);
				break;
			case 4:
				i = isFull(a, sp);
				if (i == 0)
					cout << "Stack chua day! " << x << endl;
				else
					cout << "STACK da day!\n";
				break;
			case 5:
				i= isEmpty(a, sp);
				if(i == 0)
					cout << "STACK khong rong! " << x << endl;
				else
					cout << "STACK rong!\n";
				break;
			case 6:
				cout << "STACK hien tai la: ";
				Process_stack(a, sp);
				break;
			case 7:
				cout << "GOOD BYE!!!\n";
				break;
			default:
				break;
		}
	}while(choice != 7);
	return 0;
}