// Bai 7 - Chương 2 - DS han che - QUEUE
#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100

// 7.2 Khoi tao QUEUE rong
void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}

// 7.3 Kiem tra QUEUE rong
int isEmpty(int a[], int &front, int &rear)
{
	if (front == rear)
		return 1;
	return 0;
}

// 7.4 Kiem tra QUEUE day
int isFull(int a[], int &front, int &rear)
{
	if ((front == 0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	return 0;
}

// 7.5 Them phan tu vao QUEUE
int Push(int a[], int &front, int &rear, int x)
{
	if (rear - front == MAX - 1) // hàng đợi đầy
		return 0;
	else
	{
		if (front == - 1) // hàng đợi rỗng
			front = 0;
		if (rear == MAX - 1) // hàng đợi bị tràn
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i]; // thực hiện dời tịnh tiến các phần tử trong hàng đợi
			rear = MAX - 1 - front; // rear nhận giá trị mới, sau khi tịnh tiến
			front = 0;// front nhận giá trị mới, sau khi tịnh tiến
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}

// 7.6 Lay 1 phan tu ra khoi QUEUE
int Pop(int a[], int &front, int &rear, int &x)
{
	if (front == -1) // hàng đợi rỗng
		return 0;
	else
	{
		x = a[front++];
		if (front > rear) // trường hợp hàng đợi có 1 phần tử, sau khi xóa hàng rỗng
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}

// Xuat QUEUE
void Process_queue(int a[], int f, int r)
{
	cout << "\nfront = " << f + 1 << "\t rear = " << r + 1 << endl; // f + 1 và r + 1 đối với người dùng.
	if (f <= r && f != -1)
	{
		cout << "<-----    ";
		for (int i = f; i < r + 1; i++)
			cout << a[i] << " ";
		cout << "   <-----" << endl;
	}
}

// Ham chinh
int main()
{
	int a[MAX];
	int choice, f, r, x, i; // front vị trí lấy ra, rear vị trí thêm vào
	char tt;
	do{
		system("cls");
		cout << "\n-----> BAI TAP 7 - CHUONG 2 - QUEUE (HANG DOI) <----- \n";
		cout << "\n1. Khoi tao QUEUE rong \n";
		cout << "\n2. Them phan tu vao QUEUE \n";
		cout << "\n3. Lay phan tu ra khoi QUEUE \n";
		cout << "\n4. Kiem tra QUEUE co rong hay khong \n";
		cout << "\n5. Kiem tra QUEUE co day hay khong \n";
		cout << "\n6. Xuat QUEUE \n";
		cout << "\nBan chon: "; cin >> choice;
		switch(choice)
		{
			case 1:
				init(a, f, r);
				cout << "\nBan vua khoi tao QUEUE thanh cong !\n";
				break;
			case 2:
				cout << "\nVui long nhap gia tri x = "; cin >> x;
				i = Push(a, f, r, x);
				cout << "\nQUEUE sau khi them la: " << endl;
				Process_queue(a, f, r);
				break;
			case 3:
				i = Pop(a, f, r, x);
				if (i == 0)
					cout << "\nQUEUE rong khong co phan tu de lay ra ! \n";
				else
				{
					cout << "\nPhan tu lay ra tu QUEUE la x = " << x << endl;
					cout << "\nQUEUE sau khi lay ra la: ";
					Process_queue(a, f, r);
				}
				break;
			case 4: 
				i = isEmpty(a, f, r);
				if (i == 0)
					cout << "\nQUEUE khong rong !\n";
				else
					cout << "\nQUEUE rong !\n";
				break;
			case 5:
				i = isFull(a, f, r);
				if (i == 0)
					cout << "\nQUEUE chua day !\n";
				else
					cout << "\nQUEUE da day !\n";
				break;
			case 6:
				cout << "\nQUEUE hien tai la: ";
				Process_queue(a, f, r);
				break;
			default:
				cout << "\nBan chon sai yeu cau !!\n";
		}
		cout << "\nBan muon tiep tuc khong (Y / N): "; cin >> tt;
		_getch();
	}while(tt == 'Y' || tt == 'y');
	return 0;
}