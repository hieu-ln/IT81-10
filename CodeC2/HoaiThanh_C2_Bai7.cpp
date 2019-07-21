// queue 
#include <iostream>
using namespace std;

# define max 100 
int a[max];
int front, rear;

void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}
int isEmpty(int a[], int front, int rear)
{
	if (front == -1)
		return 1;
	if (rear == -1)
		return 1;
	return 0;
}
int isFull(int a[], int front, int rear)
{
	if (rear - front == max - 1)
		return 1;
	return 0;
}

int push(int a[], int front, int rear, int x)
{
	if (rear - front == max - 1)
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == max - 1)
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = max - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}


}

int Pop(int a[], int &front, int &rear, int x)
{
	if (front == -1)
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}


int main()
{
	int chon = 0;
	cout << "1. khoi tao" << endl;
	cout << "2. kiem tra rong " << endl;
	cout << "3. kiem tra day " << endl;
	cout << "4. them mot phan tu " << endl;
	cout << "5. xoa mot phan tu " << endl;
	cout << "6. Thoat " << endl;
	do {
		cout << "vui long chon so de thuc hien :";
		cin >> chon;
		switch (chon)
		{
			case 1:
				init(a, front, rear);
				cout << "khoi tao thanh cong " << endl;
				break;
			case 2:
				if (isEmpty(a, front, rear))
					cout << "Mang rong " << endl;
				else
					cout << "mang khong rong " << endl;
				break;
			case 3:
				if (isFull(a, front, rear))
					cout << "mang day " << endl;
				else
					cout << "mang khong day" << endl;
				break;
			case 4:
				int x;
				cout << "nhap gia tri phan tu mun them : ";
				cin >> x;
				if (push(a, front, rear, x))
					cout << "nhap thanh cong" << endl;
				else
					cout << "nhap khong thanh cong " << endl;
				break;
			case 5:
				int y;
				cout << "nhao vao gia tri phan tu muon xoa : ";
				cin >> y;
				if (Pop(a, front, rear, y))
					cout << "xoa thanh cong " << endl;
				else
					cout << "xoa khong thanh cong " << endl;
			    break;
			case 6:
				cout << " thoat " << endl;
				break;
			default:
				break;
		}
	} while (chon != 6);
	system("pause");
	return 0;

}
