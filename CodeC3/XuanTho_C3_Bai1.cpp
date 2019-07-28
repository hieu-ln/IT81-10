//Bai 1 _ Chuong 3
#include <iostream>
#include <ctime>
using namespace std;
// 1.1 Khai bao danh sach
#define Max 500
int a[Max];
int n;

// 1.2 Nhap danh sach 
void Init(int a[], int &n)
{
	cout << "\nNhap so luong phan tu cho danh sach: "; cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 1000 + 1;
	cout << "\nDanh sach da duoc nhap ngau nhien nhu sau: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void Input (int a[], int &n){
	cout << "\nNhap so luong phan tu cho danh sach : "; cin >> n;
	cout << "\nNhap " << n  << " phan tu cho danh sach: "; 
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << endl;
}
// 1.3 Xuat danh sach 
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

// Copy mang de thuc hien tinh toan thoi gian
void CopyArray(int a[], int b[], int n) {
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

// 1.4 Insertion Sort
void InsertionSort(int a[], int n) {
	int x, i, j;
	for (int i = 0; i < n; i++)
	{
		x = a[i]; // Bien x luu gia tri cua a[i]
		j = i - 1;
		while (j >= 0 && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
// Hoan doi 2 so nguyen
void Swap(int &a, int &b)
{
	int temp = a;
	a = b; 
	b = temp;
}
// 1.5 Selection Sort 
void SelectionSort(int a[], int n){
	int min_idx, i, j;
	// Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		// Tim phan tu nho nhat chua duoc sap xep
		for (j = i + 1; j < n; j++) 
		{
			if (a[j] < a[min_idx])
				min_idx = j;
		}
		Swap(a[min_idx], a[i]);
	}
}

// 1.6 Interchange Sort
void InterchangeSort(int a[], int n){
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if(a[j] < a[i])
				Swap(a[j], a[i]);
	}
}

// 1.7 Bubble Sort 
void BubbleSort(int a[], int n){
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if(a[j - 1] > a[j])
				Swap(a[j], a[j - 1]);
}

// 1.8 Quick Sort
void QuickSort(int a[], int left, int right){
	int x = a[(left + right) / 2];
	int i = left, j = right;
	while(i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

// Shift 
void Shift(int a[], int i, int n){
	int j = 2 * i + 1;
	if (j >= n) // neu vi tri khong ton tai trong danh sach dang xet thi thoat khoi chuong trinh
		return;
	if (j + 1 < n) // neu ton tai vi tri j + 1 trong danh sach dang xet thi thoat khoi chuong trinh
		if (a[j] < a[j + 1]) // neu vi tri j khong ton tai phan tu a[j] < a[j + 1]
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		Shift(a, j, n);
	}
}
// 1.10 Heap Sort
void HeapShort(int a[], int n){
	int i = n / 2 - 1;
	while(i >= 0)
	{
		Shift(a, i, n);
		i--;
	}
	int right = n - 1;// Vi tri cuoi cung heap dang xet
	while (right > 0)
	{
		Swap(a[0], a[right]); // Hoan vi phan tu a[0] cho phan tu cuoi heap dang xet
		right--; // gioi han lai phan tu dang xet
		if(right > 0)// kiem tra mang dang xet con nhieu hon 1 phan tu 
			Shift(a, 0, right);
	}
}

// 1.11 SearchSequence
void searchSequence(int a[], int n, int x){
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		cout << "\nKhong tim thay\n";
	else
		cout << "\nTim thay tai vi tri " << i ;
}

// 1.12 Search Binary
int searchBinary(int a[], int l, int r, int x){
	if ( r >= l)
	{
		int mind = l +(r - l) / 2; // tuong duong (l + r) / 2
		// neu a[mind] = x thi tra ve chi so ket thuc
		if(a[mind] == x)
			return mind;

		// Neu a[mind] > x, thuc hien tim nua mang trai
		if(a[mind] > x)
			return searchBinary(a, l, mind - 1, x);

		// Neu a[mind] < x, thuc hien tim nua mang phai
		if(a[mind] < x)
			return searchBinary(a, mind + 1, r, x);
	}
	return -1; // Neu khong tim thay
}
int main()
{
	int b[Max];
	int choice, x, i;
	clock_t start;
	double duration;
	cout << "\n -----> BAI TAP 1 - CHUONG 3 - XEP THU TU VA TIM KIEM <----- \n";
	cout << "\n0.Khoi tao danh sach ngau nhien \n";
	cout << "\n1. Nhap danh sach \n";
	cout << "\n2. Xuat danh sach \n";
	cout << "\n3. Xep thu tu danh sach bang SELECTION SORT\n";
	cout << "\n4. Xep thu tu danh sach bang INSERTION SORT\n";
	cout << "\n5. Xep thu tu danh sach bang BUBBLE SORT\n";
	cout << "\n6. Xep thu tu danh sach bang INTERCHANGE SORT\n";
	cout << "\n7. Xep thu tu danh sach bang QUICK SORT\n";
	cout << "\n8. Xep thu tu danh sach bang HEAP SORT\n";
	cout << "\n9. Tim kiem phan tu x bang TIM KIEM TUAN TU \n";
	cout << "\n10. Tim kiem phan tu x bang TIM KIEM NHI PHAN \n";
	cout << "\n11. Thoat \n";
	do{
		cout << "\nVui long chon so de thuc hien: "; cin >> choice;
		switch(choice)
		{
			case 0:
				Init(a, n);
				break;
			case 1:
				Input(a, n);
				break;
			case 2:
				cout << "\nDanh sach la: " << endl;
				Output(a, n);
				break;
			case 3:
				CopyArray(a, b, n);
				start = clock();
				SelectionSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
				if (n < 100)
				{
					cout << "\nDS sau khi xep thu tu voi SELECTION SORT la: " << endl;
					Output(b, n);
				}
				if (duration > 0)
					cout << "\nThoi gian SELECTION SORT: " << duration * 1000000 << " Microseconds \n";
				break;
			case 4:
				CopyArray(a, b, n);
				start = clock();
				InsertionSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
				if (n < 100)
				{
					cout << "\nDS sau khi xep thu tu voi INSERTION SORT la: " << endl;
					Output(b, n);
				}
				if (duration > 0)
					cout << "\nThoi gian INSERTION SORT: " << duration * 1000000 << " Microseconds \n";
				break;
			case 5:
				CopyArray(a, b, n);
				start = clock();
				BubbleSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
				if (n < 100)
				{
					cout << "\nDS sau khi xep thu tu voi BUBBLE SORT la:" << endl;
					Output(b, n);
				}
				if (duration > 0)
					cout << "\nThoi gian BUBBLE SORT: " << duration * 1000000 << " Microseconds \n";
				break;
			case 6:
				CopyArray(a, b, n);
				start = clock();
				InterchangeSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
				if (n < 100)
				{
					cout << "\nDS sau khi xep thu tu voi INTERCHANGE SORT la: " << endl;
					Output(b, n);
				}
				if (duration > 0)
					cout << "\nThoi gian INTERCHANGE SORT: " << duration * 1000000 << " Microseconds \n";
				break;
			case 7:
				CopyArray(a, b, n);
				start = clock();
				QuickSort(b, 0, n - 1);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
				if (n < 100)
				{
					cout << "\nDS sau khi xep thu tu voi QUICK SORT la: " << endl;
					Output(b, n);
				}
				if (duration > 0)
					cout << "\nThoi gian QUICK SORT: " << duration * 1000000 << " Microseconds \n";
				break;
			case 8:
				CopyArray(a, b, n);
				start = clock();
				HeapShort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
				if (n < 100)
				{
					cout << "\nDS sau khi xep thu tu voi HEAP SORT la: " << endl;
					Output(b, n);
				}
				if (duration > 0)
					cout << "\nThoi gian HEAP SORT: " << duration * 1000000 << " Microseconds \n";
				break;
			case 9:
				cout << "\nVui long nhap gia tri x = "; cin >> x;
				start = clock();
				searchSequence(a, n, x);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
				if (duration > 0)
					cout << "\nThoi gian TIM KIEM TUAN TU la: " << duration * 1000000 << " Microseconds \n";
				break;
			case 10:
				cout << "\nVui long nhap gia tri x = "; cin >> x;
				start = clock();
				i = searchBinary(b, 0, n, x);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
				if (i == -1)
					cout << "\nKhong tim thay x = " << x  << " trong day !" << endl;
				else
					cout << "\nTim thay x = " << x << " tai vi tri i = "  << i + 1 << endl;
				if (duration > 0)
					cout << "\nThoi gian TIM KIEM NHI PHAN la: " << duration * 1000000 << " Microseconds \n";
				break;
			case 11:
				cout << "\nGoodbye .... !! \n";
				break;
			default:
				break;
		}
	}while (choice != 11);
	return 0;
}