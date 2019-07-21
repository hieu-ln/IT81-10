// danh sách đặc
#include <iostream>
using namespace std;
#define max 100 
int a[max];
int n;

void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao gia tri a[" << i + 1 << "] : ";
		cin >> a[i];
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

int Seach(int a[], int n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
		if (i == n)
			return -1;
	return i;
}

int insert_Last (int a[], int &n, int x)
{
	if (n >= 0 || n < max)
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;

}

int delete_Last(int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}

int Delete (int a[], int &n, int i )
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
		n--;
		return 1;
	}
	return 0;
		
	
}

int Delete_Seach(int a[], int &n, int x)
{
	if (Seach(a, n, x) == -1)
		return 0;
	if (Delete(a, n, Seach(a, n, x)))
		return 1;
}

int main()
{
	int chon = 0;
	cout << " 1. khoi tao danh sach " << endl;
	cout << " 2. xuat danh sach  " << endl;
	cout << " 3. tim phan tu trong mang " << endl;
	cout << " 4. them phan tu cuoi mang " << endl;
	cout << " 5. xoa phan tu cuoi mang " << endl;
	cout << " 6. xoa phan tu tai vi tri thu i" << endl;
	cout << " 7. xoa phan tu co gia tri ban chon" << endl;
	cout << " 8. Thoat " << endl;
	do {
		do{
			cout << " vui long chon so de thuc hien :  ";
			cin >> chon;
			if (chon <= 0 || chon > 8)
				cout << " Nhap sai !.Moi ban nhap tu 0 den 8 ! " << endl;
		} while (chon <= 0 || chon > 8);
		switch (chon)
		{
			case 1:
				cout << "nhap vao so luong phan tu : ";
				do {
					cin >> n;
					if (n < 0 && n > max - 1)
						cout << "nhap sai, nhap lai !" << endl;
				} while (n < 0 && n > max - 1);
				input(a, n);
				cout << " khoi tao danh sach thanh cong " << endl;
				break;
			case 2:
				cout << "Danh sach la : " << endl;
				output(a, n);
				break;
			case 3:
				int x, k;
				cout << "nhap gia tri phan tu can tim : ";
				cin >> x;
				k = Seach(a, n, x);
				if ( k == -1)
					cout << "khong co gia tri " << x << "trong mang : " << endl;
				else
					cout << "co gia tri " << x << "trong mang tai vi tri " << k+1 << endl;
				break;
			case 4:
				int y;
				cout << "nhap phan tu ban muon them vao cuoi mang : ";
				cin >> y;
				if (insert_Last(a, n, y))
					cout << "them phan tu vao cuoi mang thanh cong " << endl;
				else
					cout << "them phan tu vao cuoi mang khong thanh cong " << endl;
				break;
			case 5:
				if (delete_Last(a, n))
				{
					cout << "xoa phan tu o cuoi mang thanh cong " << endl;
					cout << "mang sau khi xoa la : " << endl;
					output(a, n);
				}
				else
					cout << "xoa phan tu o cuoi mang khong thanh cong " << endl;
				break;
			case 6:
				int i;
				cout << "nhap vao vi tri phan tu ban muon xoa : ";
				cin >> i;
				if (Delete(a, n, i))
				{
					cout << "xoa thanh cong ! " << endl;
					cout << "mang sau khi xoa la : " << endl;
					output(a, n);
				}
				else
					cout << "xoa khong thanh cong " << endl;
				break;
			case 7: 
				int z, m;
				cout << "nhap vao gia tri phan tu ban muon xoa " << endl;
				cin >> z;
				m = Delete_Seach(a, n, z);
				if (m == 1)
				{
					cout << "xoa phan tu thanh cong !" << endl;
					cout << "mang sau khi xoa la : " << endl;
					output(a, n);
				}
				else
				{
					cout << "xoa phan tu khong thanh cong " << endl;
				}
					
				break;
			case 8 :
				cout << " SEE YOU AGAIN !" << endl;
				break;
			default:
				break;
		}
	} while (chon != 8);
	system("pause");
	return 0;
}