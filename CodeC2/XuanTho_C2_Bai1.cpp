//Bai 1 _ Chýõng 2
#include <iostream>
using namespace std;

// Cau 1.1 Khai bao cau truc danh sach
#define Max 100
int a[Max];
int n;

// Cau 1.2 Thu tuc nhap danh sach
void Input(int a[], int &n)
{
	cout << "\nNhap so luong phan tu can dung: "; cin >> n;
	cout << "\nNhap " << n << " phan tu : ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << endl;
}

// Cau 1.3 Xuat danh sach
void Output(int a[], int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << " "; 
	cout << endl;
}

// Cau 1.4 Tim mot phan tu trong danh sach
int Search(int a[], int n, int x){
	for (int i = 0; i < n; i++){
		if (a[i] == x)
			return i;
	}
	return -1;
}

// Cau 1.5 Them mot phan tu vao cuoi danh sach
int Insert_last(int a[], int &n, int x){
	if (n < Max)
	{
		a[n++] = x;
		return 1;
	}
	return 0;
}

// Cau 1.6 Xoa phan tu cuoi danh sach
int Delete_last(int a[], int &n){
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}

// Cau 1.7 Xoa phan tu tai vi tri thu i
int Delete_at_i(int a[], int &n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}

// Cau 8 Tim phan tu va xoa (neu co)
int Search_Delete(int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			Delete_at_i(a, n, i);
			return 1;
		}
	}
	return 0;
}
int main(){
	int choice = 0;
	int x, i, kq;
	cout << "\n---------->	BAI 1 - CHUONG 2 <----------\n";
	cout << "\n1.Nhap danh sach\n";
	cout << "\n2.Xuat danh sach\n";
	cout << "\n3.Tim mot phan tu trong danh sach\n";
	cout << "\n4.Them mot phan tu vao cuoi danh sach\n";
	cout << "\n5.Xoa phan tu cuoi danh sach\n";
	cout << "\n6.Xoa phan tu tai vi tri thu i\n";
	cout << "\n7.Tim phan tu trong danh sach va xoa (neu co)\n";
	cout << "\n8.Thoat\n";
	do{
		cout << "\nVui long chon so de thu hien: "; cin >> choice;
		switch(choice)
		{
		case 1:
			{
				Input(a, n);
				cout << "\nBan da nhap danh sach thanh cong !\n";
				break;
			}
		case 2:
			{
				cout << "\nDanh sach cac phan tu: ";
				Output(a, n);
				break;
			}
		case 3:
			{
				cout << "\nNhap phan tu can tim x = "; cin >> x;
				i = Search(a, n, x);
				
				if (i == -1)
					cout << "\nKhong tim thay phan tu " << x << " trong danh sach\n";
				else
					cout << "\nPhan tu " << x << " tim thay trong danh sach tai vi tri " << i << endl;
				break;
			}
		case 4:
			{
				cout << "\nNhap phan tu can them vao cuoi danh sach: "; cin >> x;
				Insert_last(a, n, x);
				cout << "\nDanh sau khi them phan tu vao cuoi danh sach: ";
				Output(a, n);
				break;
			}
		case 5:
			{
				Delete_last(a, n);
				cout << "\nDanh sach sau khi xoa phan tu cuoi: ";
				Output(a, n);
				break;
			}
		case 6:
			{
				cout << "\nNhap vi tri can xoa: "; cin >> i;
				Delete_at_i(a, n, i);
				cout << "\nDanh sach sau khi xoa phan tu tai vi tri " << i << " la: ";
				Output(a, n); 
				break;
			}
		case 7:
			{
				cout << "\nNhap mot phan tu x = "; cin >> x;
				kq = Search_Delete(a, n, x);
				if (kq == true)
				{
					cout << "\nDanh sach sau khi tim duoc phan tu " << x << " va xoa la: ";
					Output(a, n);
				}
				else
					cout << "\nKhong tim thay phan tu " << x << " trong danh sach\n";
				break;
			}
		case 8:
			{
				cout << "\nGood Bye !\n";
				break;
			}
		default:
			break;
		}
	}while(choice != 8);
	return 0;
}