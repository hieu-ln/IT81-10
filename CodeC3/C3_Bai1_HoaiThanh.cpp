#include <iostream>
using namespace std;

#define max 100 

int a[max];
int n;

void input (int a[], int n)
{
	for (int i=0 ; i < n; i++)
	{
		cout << "Nhap vao a["<< i + 1 << "] : " ;
		cin >> a[i];
	}

}

void output (int a[], int n)
{
	for (int i = 0;i < n; i++)
		cout << a[i] << "\t" ;
}

void SelectionSort (int a[], int n)
{
	int min, i, j;
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min],a[i]);
	}
}

void InsertionSort (int a[], int n)
{
	int x, i, j;
	for (int i = 1; i < n; i++)
	{
		x= a[i];
		j = i - 1 ;
		while ( 0 <= j && x < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}

void BubleSort (int a[], int n)
{
	for (int i = 0; i < n-1;i++)
		for (int j =n -1; j > i; j--)
			if(a[j-1] > a[j])
				swap(a[j], a[j-1]);
}

void InterchangeSort (int a[],int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n ; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

void QuickSort (int a[], int left, int right)
{
	int x=a[(left + right)/2];
	int i = left;
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if ( i <= j )
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
		if (left < j)
			QuickSort(a,left,j);
		if(i<right)
			QuickSort(a,i,right);
	}
}

void Shift (int a[],int i, int n)
{
	int j = 2*i+1;
	if ( j >= n)
		return;
	if (j+1 < n)
		if (a[j]  < a[j+1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		Shift(a,j,n);
	}
}

void HeapSort (int a[], int n)
{
	int i = n/2;
	while (i >= 0)
	{
		Shift(a,i,n);
		i--;
	}
	int right = n -1;
	while (right > 0)
	{
		swap(a[0],a[right]);
		right--;
		if (right > 0)
			Shift(a,0,right);
	}
}

// tim kiem tuan tu 
int Search (int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if ( i < n)
		return i;
	return -1;
}

int BinarySearch (int a[],int n, int x)
{
	int left = 0, right = n- 1, mid;
	while(left <= right )
	{
		mid = (left + right )/ 2;
		if (a[mid]== x)
			return mid;
		if ( x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;

}

int main()
{
	int chon = 0;
	system("cls");
	do{
		cout << "nhap vao so luong phan tu : " ;
		cin >> n;
		if ( n < 0 || n >= max) 
			cout << "nhap sai, nhap lai! " << endl;
	}while(n < 0 || n >= max);
	
	
		cout << "\t\t\n\n --Menu-- \t\t\n\n" << endl;
		cout << "1. khoi tao " << endl;
		cout << "2. Xuat Danh Sach " << endl;
		cout << "3. Sap xep danh sach bang SelectionSort" << endl;
		cout << "4. Sap xep danh sach bang InsertionSort" << endl;
		cout << "5. Sap xep danh sach bang BubleSort" << endl;
		cout << "6. Sap xep danh sach bang InterchangeSort" << endl;
		cout << "7. Sap xep danh sach bang QuickSort" << endl;
		cout << "8. Sap xep danh sach bang HeapSort" << endl;
		cout << "9. Tim kiem mot phan tu bang tim kiem nhi phan" << endl;
		cout << "10. Tim kiem mot phan tu bang tim kiem tuan tu " << endl;
		cout << "11. Thoat" << endl;
	do{
		cout << "\nmoi ban nhap su lua chon : " ;
		cin >> chon;
		switch(chon)
		{
			case 1:
				input(a,n);
				break;
			case 2:
				cout << "danh sach la : " ;
				output(a,n);
			case 3:
				SelectionSort(a,n);
				cout << "mang sau khi sap xep la : ";
				output(a,n);
				break;
			case 4:
				InsertionSort(a,n);
				cout << "mang sau khi sap xep la : ";
				output(a,n);
				break;
			case 5:
				BubleSort(a,n);
				cout << "mang sau khi sap xep la : ";
				output(a,n);
				break;
			case 6:
				InterchangeSort(a,n);
				cout << "mang sau khi sap xep la : ";
				output(a,n);
				break;
			case 7:
				int left,right ;
				left = 0;
				right = n -1 ;
				QuickSort(a,left,right);
				cout << "mang sau khi sap xep la : ";
				output(a,n);
				break;
			case 8:
				HeapSort(a,n);
				cout << "mang sau khi sap xep la : ";
				output(a,n);
				break;
			case 9:
				int x;
				cout << "nhap so ban muon tim kiem :";
				cin >> x;
				if (Search(a,n,x))
					cout << "tim thay duoc x tai vi tri " << Search(a,n,x); 
				else
					cout << "khong tim thay duoc x"<<endl;
				break;
			case 10:
				int y;
				cout << "nhap so ban muon tim kiem :" ;
				cin >> y;
				if(BinarySearch(a,n,y))
					cout << "tim thay duoc x tai vi tri thu " << BinarySearch(a,n,y);
				else
					cout << "khong tim thay duoc x" << endl;
				break;
			case 11:
				cout << "thoat" << endl;
				break;
			default:
				break;	
		}

	}while( chon != 11);
	system("pause");
	return 0;
}