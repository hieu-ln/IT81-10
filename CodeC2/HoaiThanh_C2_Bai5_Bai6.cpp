// bai tap 5 - thuc hanh 2
#include <iostream>
using namespace std;
#define max 100

int a[max];
int sp;

// khoi tao stack rong 
void init(int a[], int &sp)
{
	sp = -1;
}
// kiem tra ngan xep co rong hay khong  

int isEmpty(int a[], int &sp)
{
	if (sp == -1)
		return 1; // ngan xep rong 
	return 0;
}
// kiem tra stack co day` khon  

int isFull(int a[], int sp)
{
	if (sp == max - 1)
		return 1;
	return 0;
}
// them 1 phan tu vao trong stack

int Push(int a[], int &sp, int x)
{
	if (sp <= max - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
// lay mot phan tu ra 

int pop(int a[], int &sp, int x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
// xuat danh sach

void xuat(int a[], int sp)
{
	for (int i = sp; i >= 0; i--)
		cout << a[i] << " ";
}




int convert(int so)
{
	init(a, sp);
	int np = 0;
	int du;
	while (np != 0)
	{
		du = so % 2;
		if (Push(a, sp, du))
			so /= 2;
		else
			break;
	}
	while (!isEmpty(a, sp))
	{
		if (pop(a, sp, du ))
		{
			np = np * 10 + du;
		}
		else
			break;
	}
	return np;
}



int main()
{
	int chon = 0;
	system("cls");
	cout << "\n\n\t\t MENU \n\n\t\t" << endl;
	cout << " 1. khoi tao " << endl;
	cout << " 2. kiem tra rong " << endl;
	cout << " 3. kiem tra day " << endl;
	cout << " 4. them 1 phan tu " << endl;
	cout << " 5. xoa 1 phan tu " << endl;
	cout << " 6. doi 1 so tu thap phan sang nhi phan " << endl;
	cout << " 7. xuat danh sach " << endl;
	cout << " 8. Thoat " << endl;
	do {
		cout << " moi ban nhap su lua chon " << endl;
		cin >> chon;
		switch (chon)
		{

		case 1:
			init(a, sp);
			cout << " ban vua khoi tao thanh cong danh sach" << endl;
			break;
		case 2:
			if (isEmpty(a, sp))
				cout << " mang rong " << endl;
			else
				cout << " mang khong rong " << endl;
			break;
		case 3:
			if (isFull(a, sp))
				cout << " mang da day " << endl;
			else
				cout << " mang chua day " << endl;
			break;
		case 4:
			int x;
			cout << " nhap vao gia tri phan tu ban muon them: " << endl;
			cin >> x;
			if (Push(a, sp, x))
				cout << " them phan tu thanh cong " << endl;
			else
				cout << " them phan tu khong thanh cong " << endl;
			break;
		case 5:
			int y;
			cout << "nhap phan tu ban muon xoa : ";
			cin >> y;
			if (pop(a, sp, y))
				cout << " xoa phan tu thanh cong" << endl;
			else
				cout << " xoa phan tu khong thanh cong " << endl;
		case 6:
			int tp;
			cout << "nhap gia tri he thap phan can chuyen : ";
			cin >> tp;
			cout << "Gia tri nhi phan tuong ung la  : " << convert(tp) << endl;
			break;
		case 7:
			cout << "danh sach : ";
			xuat(a, sp);
			cout << endl;
			break;
		case 8:
			cout << "Thoat " << endl;
			break;
		default:
			break;
		}

	} while (chon != 8);
	system("pause");
	return 0;
}