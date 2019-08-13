// Bai 6 - Chuong 6
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

# define MAX 20
int a[MAX][MAX];
int n; // so dinh cua do thi
char vertex[MAX];

void initG()
{
	n = 0;
}

void inputG()
{
	cout << "\nNhap so dinh do thi n: ";
	cin >> n;
	cout << "\nNhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
//xuat ma tran ke cua do thi
void outputGraph()
{
	cout << setw(6) << left;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}

// khai bao Tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // so phan tu tap E

// khai bao Tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT=0; // so phan tu tap T

int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void taoE()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}

void sapXepE()
{
	for (int i = 0; i < nE - 1; i++)
		for (int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
}

void kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}

void output(bool vertexname)
{
	int tong = 0;
	for (int i = 0; i < nT; i++)
	{
		if (vertexname)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\nTong = " << tong;
}
int main()
{
	int choice, x, i;
	cout << "\n -----> BAI 5 - CHUONG 6 - TIM KIEM CAY KHUNG TOI THIEU, KRUSKAL <----- " << endl;
	cout << "\n1. Khoi tao ma tran ke rong " << endl;
	cout << "\n2. Nhap ma tran ke" << endl;
	cout << "\n3. Xuat ma tran ke" << endl;
	cout << "\n4. Tim cay khung toi tieu bang KRUSKAL Cai Tien" << endl;
	cout << "\n5. Thoat" << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			initG();
			cout << "\nBan vua khoi tao ma tran ke rong thanh cong!\n";
			break;
		case 2:
			inputG();
			break;
		case 3:
			cout << endl;
			outputGraph();
			break;
		case 4:
			sapXepE();
			taoE();
			kruskal();
			cout << "\nCay khung toi tieu bang KRUSKAL Cai Tien " << endl;
			output(true);
			break;
		case 5:
			cout << "\nGoodbye ...!!!!!\n";
			break;
		default:
			cout << "\nChon sai. Chon lai !!!\n";
			break;
		}
	} while (choice != 5);
	return 0;
}
