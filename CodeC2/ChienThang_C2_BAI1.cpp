#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int n;

void input(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap a[" << i  << "] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int search(int a[], int n, int x)
{
	int i = 0;
	while ((i <n) && (a[i] != x) )
		i ++;
	if( i == n)
		return -1;
	return 1;
}
int insert_last(int a[], int &n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n ++;
		return 1;
	}
	else
		return 0;
}
int delete_last(int a[], int &n)
{
	if(n > 0)
	{
		n--;
		return 1;
	}
	else
		return 0;
}
int Delete(int a[], int &n, int i)
{
	if(i >= 0&& i < n)
	{
		for(int j= i; j < n-1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}
int searchanddelete(int a[], int &n, int x)
{
	for (int i = 0; i < n; i ++)
		if(a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i, n;
	system("cls");
	cout << "-----------BAI TAP 1  ,  CHUONG 2  ,  DANH SACH DAC ------" << endl;
	cout << "1.Nhap danh sach" << endl;
	cout << "2.Xuat danh sach" << endl;
	cout << "3.Tim phan tu co gia tri x trong danh sach" << endl;
	cout << "4.Them phan tu vao cuoi danh sach" << endl;
	cout << "5.Xoa phan tu cuoi danh sach" << endl;
	cout << "6.Xoa phan tu tai vi tri i" << endl;
	cout << "7.Tim phan tu voi gia tri x va xoa no neu co" << endl;
	cout << "8.Thoat" << endl;
	
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Nhap phan tu can dung: ";
				cin >> n;
				input(a, n);
				cout << "Ban vua nhap danh sach thanh cong!\n";
				break;
			case 2:
				cout << "Danh sach da nhap la: \n";
				output(a, n);
				break;
			case 3:
				cout << "Vui long nhap x can tim: ";
				cin >> x;
				i = search(a, n, x);
				if(i == -1)
					cout << "Tim khong thay phan tu co gia tri " << x << endl;
				else
					cout << "Tim thay tai vi tri i= " << i << endl;
				break;
			case 4:
				cout << "Vui long nhap x can them vao cuoi danh sach: ";
				cin >> x;
				i = insert_last(a, n, x);
				if (i == 0)
					cout << "Danh sach da day, khong the them " << x << endl;
				else
				{
					cout << "Da them phan tu x= " << i << " vao cuoi danh sach!"  << endl;
					cout << "Danh sach sau khi them la: ";
					output(a, n);
				}
				break;
			case 5:
				i = delete_last(a, n);
				if(i > 0)
				{
					cout << "Xoa thanh cong!" << endl;
					cout << "Danh sach sau khi xoa phan tu cuoi la: \n";
					output(a, n);
				}
				else
					cout << "Danh sach dang rong, khong co phan tu nao!" << endl;
				break;
			case 6:
				cout << "Vui long nhap vi tri can xoa i = ";
				cin >> i;
				i = Delete(a, n, i);
				if(i == 1)
				{
					cout << "Xoa thanh cong!" << endl;
					cout << "Danh sach sau khi xoa la: \n";
					output(a, n);
				}
				else
					cout << "Khong co phan tu nao de xoa!" <<endl;
				break;
			case 7:
				cout << "Vui long nhap gia tri can xoa x= ";
				cin >> x;
				i = searchanddelete (a, n, x);
				if(i == 1)
				{
					cout << "Xoa thanh cong phan tu co gia tri x = " << x << endl;
					cout << "Danh sach sau khi xoa la: \n";
					output(a, n);
				}
				else
					cout << "Khong co phan tu nao de xoa!" << endl;
				break;
			case 8:
				cout << "Goodbye!\n";
				break;
			default:
				cout << "Nhap sai. Nhap lai.\n";
				break;
		}
	}while(choice != 8);
	return 0;
}