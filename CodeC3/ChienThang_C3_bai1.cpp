#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
#define MAX 5000
int a[MAX];
int n;

void init(int a[], int &n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for(int i = 0; i < n; i++ )
		a[i] = rand() % 1000 + 1;
	cout << "Danh sach duoc nhap ngau nhien nhu sau: \n";
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu can dung: ";
	cin >> n;
	cout << "Nhap " << n << " phan tu: ";
	for(int i = 0; i < n; i++)
		cin >> a[i];
}
void output(int a[], int &n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void copyarray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i ++)
		b[i]= a[i];
}
void insertionsort(int a[], int n)
{
	int x, i, j;
	for(i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(0 <= j && x < a[j])
		{
			a[j + 1]= a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void selectionsort(int a[], int n)
{
	int min_pos, i , j;
	for (i = 0; i < n -1; i++)
	{
		min_pos = 1;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void interchangesort(int a[], int n)
{
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}
void bubblesort(int a[], int n)
{
	for(int i = 0; i < n; i++)
		for(int j = n - 1; j  > i; j--)
			if(a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}
void quicksort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
		if(left < j)
			quicksort(a, left, j);
		if(i < right)
			quicksort(a, i, right);
	}
}
void shift(int a[], int i, int n)
{
	int j = 2*i + 1;
	if(j >= n)
		return;
	if(j + 1 < n)
		if(a[j] < a[j+ 1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j , n);
	}
}
void heapsort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i , n- 1);
		i--;
	}
	int right = n-1;
	while (right > 0)
	{
		swap(a[0], a[right]);
		right --;
		if(right > 0)
			shift(a, 0, right);
	}
}
int search(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if(i < n)
		return i;
	return -1;
}
int binarysearch(int a[], int n, int x)
{
	int left = 0, right =  n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] == x)
			return mid;
		if(x > a[mid])
			left= mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, t;
	system("cls");
	cout << "----BAI TAP 1, CHUONG 3, XEP THU TU va TIM KIEM-----\n";
	cout << "0.  Khoi tao danh sach ngau nhien \n";
	cout << "1.  Nhap danh sach \n";
	cout << "2.  Xuat danh sach \n";
	cout << "3.  Sap xep bang SELECTIONSORT \n";
	cout << "4.  Sap xep bang INSERTIONSORT \n";
	cout << "5.  Sap xep bang BUBBLE SORT \n";
	cout << "6.  Sap xep bang INTERCHANGE SORT \n";
	cout << "7.  Sap xep bang QUICK SORT \n";
	cout << "8.  Sap xep bang HEAP SORT \n";
	cout << "9.  Tim kiem phan tu bang TIM KIEM TUAN TU \n";
	cout << "10. Tim kiem phan tu bang TIM KEIM NHI PHAN \n";
	cout << "11. Thoat. \n";
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 0:
				init(a, n);
				break;
			case 1:
				input(a, n);
				break;
			case 2:
				output(a, n);
				break;
			case 3:
				copyarray(a, b, n);
				start = clock();
				selectionsort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 5000)
				{
					cout << "Danh sach sau khi xep voi SELECTION SORT la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian SELECTION SORT: " << duration * 1000000 << " ms \n";
				break;
			case 4:
				copyarray(a, b, n);
				start = clock();
				insertionsort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 5000)
				{
					cout << "Danh sach sau khi xep voi INSERTION SORT la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian INSERTION SORT: " << duration * 1000000 << " ms \n";
				break;
			case 5:
				copyarray(a, b, n);
				start = clock();
				bubblesort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 5000)
				{
					cout << "Danh sach sau khi xep voi BUBBLE SORT la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 << " ms \n";
				break;
			case 6:
				copyarray(a, b, n);
				start = clock();
				interchangesort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 5000)
				{
					cout << "Danh sach sau khi xep voi INTERCHAGE SORT la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian INTERCHANGE SORT: " << duration * 1000000 << " ms \n";
				break;
			case 7:
				copyarray(a, b, n);
				start = clock();
				quicksort(b,0, n - 1);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 5000)
				{
					cout << "Danh sach sau khi xep voi QUICK SORT la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian QUICK SORT: " << duration * 1000000 << " ms \n";
				break;
			case 8:
				copyarray(a, b, n);
				start = clock();
				heapsort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 5000)
				{
					cout << "Danh sach sau khi xep voi HEAP SORT la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian HEAP SORT: " << duration * 1000000 << " ms \n";
				break;
			case 9:
				cout << "Vui long nhap gia tri x: ";
				cin >> x;
				start = clock();
				search(a, n, x);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(search(a, n, x) != -1)
					cout << "Tim thay " << x << " tai vi tri " << search(a, n, x) << endl;
				else
					cout << "Khong tim thay " << x << " trong danh sach. \n";
				if(duration > 0)
					cout << "Thoi gian TIM KIEM TUAN TU: " << duration * 1000000 << " ms \n";
				break;
			case 10:
				cout << "Vui long nhap gia tri x: ";
				cin >> x;
				start = clock();
				t = search(b, n, x);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(t != -1)
					cout << "Tim thay " << x << " tai vi tri " << t << endl;
				else
					cout << "Khong tim thay " << x << " trong danh sach. \n";
				if(duration > 0)
					cout << "Thoi gian TIM KIEM NHI PHAN: " << duration * 1000000 << " ms \n";
				break;
			case 11:
				cout << "GOOD BYE !!!\n";
				break;
			default:
				break;
				}
	}while(choice != 11);
	return 0;
}