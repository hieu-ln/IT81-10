#include <iostream>
using namespace std;
#define max 100

int a[max];
int n;
// them 1 phan tu vao mang da duoc sap xep 

void Nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao phan tu thu a[" << i + 1 << "] : ";
		cin >> a[i];
	}
	
}
void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
// them phan tu tai vi tri x
int Insert (int a[], int n, int i, int x)
{
	if (i > 0 && i <= n)
	{
		for (int j = n; j > i; j--)
		{
			a[j] = a[j - 1];
		}
		a[i] = x;
		n++;
	}
	return 0;
}

int KiemTra(int a[], int &n, int x)
{
	if (n == 1)
	{
		for (int i = 0; i < n; i++)
			if (a[i] <= x)
			{
				a[n] = x;
				Xuat(a, n + 1);
				break;
			}
			else
			{
				Insert(a, n, x, 0);
				Xuat(a, n);
				break;
			}
		return 1;
	}
	else
	{
		if (a[0] < a[1])
		{
			if (x > a[n - 1])
			{
				a[n] = x;
				Xuat(a, n + 1);
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					if (a[i] >= x)
					{
						Insert(a, n, x, i);
						break;
					}
				}
				Xuat(a, n);
			}
			return 1;
		}
		if (a[0] > a[1])
		{
			if (x < a[n - 1])
			{
				a[n] = x;
				Xuat(a, n + 1);
			}
			else
			{
				for (int i = 0; i <= n; i++)
				{
					if (a[i] <= x)
					{
						Insert(a, n, x, i);
						break;
					}
				}
				Xuat(a, n);
			}
			return 1;
		}
	}
	return 0;
}
int Tim_TuanTu(int a[], int n, int x)
{
	n++;
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	if (i == n)
		return -1;
	return i;
}
int Tim_NhiPhan(int a[], int n, int x)
{
	int mid, left = 0, right = n;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return 1;
		else
			if (a[mid] < x)
				right = mid - 1;
			else
				left = mid + 1;
	}
	return -1;
}
int Xoa(int a[], int &n, int vti)
{
	n++;
	if (vti >= 0 && vti < n)
	{
		for (int i = vti; i < n - 1; i++)
			a[i] = a[i + 1];
		n--;
		return 1;
	}
	return 0;
}
int TimXoa(int a[], int &n, int x)
{
	if (Tim_TuanTu(a, n, x) == -1)
		return 0;
	if (Xoa(a, n, Tim_TuanTu(a, n, x)))
		return 1;
}


int main()
{
	int gt, i, tim, j, tx;
	do
	{
		cout << "Nhap vao gia tri nguyen: ";
		cin >> n;
		if (n <= 0 || n > max)
			cout << "Nhap sai.Nhap lai!\n";
	} while (n <= 0 || n > max);
	Nhap(a, n);
	cout << "Cac phan tu trong mang la: ";
	Xuat(a, n);
	cout << "Nhap gia tri can chen vao mang: ";
	cin >> gt;
	if (KiemTra(a, n, gt) == 1)
	{
		cout << "Them gia tri thanh cong!\n";
	}
	else
		cout << "Them gia tri khong thanh cong.\n";
	cout << "Nhap gia tri can tim: ";
	cin >> tim;
	i = Tim_TuanTu(a, n, tim);
	if (i == -1)
		cout << "Gia tri " << tim << " khong ton tai trong mang!\n";
	else
		cout << "Gia tri " << tim << " ton tai trong mang o vi tri " << i << ".\n";
	j = Tim_TuanTu(a, n, tim);
	if (j == -1)
		cout << "Gia tri " << tim << " khong ton tai trong mang!\n";
	else
		cout << "Gia tri " << tim << " ton tai trong mang o vi tri " << j << ".\n";
	cout << "Nhap phan tu can tim xoa: ";
	cin >> tx;
	if (TimXoa(a, n, tx) == 1)
	{
		cout << "Xoa gia tri " << tx << " thanh cong!\n";
		Xuat(a, n);
	}
	else
		cout << "Xoa gia tri " << tx << " khong thanh cong!\n";
	system("pause");
	return 0;
}