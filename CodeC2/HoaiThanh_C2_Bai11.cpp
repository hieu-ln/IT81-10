#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *front;
Node *rear;

void init()
{
	front = NULL;
	rear = NULL;
}

int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}

void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int pop(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

void Process_queue()
{
	if (front != NULL)
	{
		Node *p = front;
		do
		{
			cout << p->info << "\t";
			p = p->link;

		} while (p != NULL);
		cout << "--" << endl;
	}
}
int main()
{
	int chon, x, i;
	system("cls");
	cout << "Menu" << endl;
	cout << "1. Khoi tao rong" << endl;
	cout << "2. them phan tu vao Queue" << endl;
	cout << "3. lay phan tu ra khoi queue" << endl;
	cout << "4. kiem ra rong" << endl;
	cout << "5. xuat Queue" << endl;
	cout << "6. Thoat" << endl;
	do
	{
		cout << "chon so de thuc hien";
		cin >> chon;
		switch (chon)
		{
			case 1:
				init();
				cout << "khoi tao thanh cong " << endl;
				break;
			case 2:
				cout << "vui long nhap gia tri x : " << endl;
				cin >> x;
				Push(x);
				break;
			case 3:
				pop(x);
				cout << "lay phan tu ra " << endl;
			case 4:
				i = isEmpty();
				if (i == 0)
					cout << "queue khong rong" << endl;
				else
					cout << "queue rong" << endl;
			case 5:
				cout << "queue hien tai la :";
				Process_queue();
				break;
			case 6:
				cout << " Tam biet " << endl;
				break;
			default:
				break;
		}

	} while (chon != 6);
	system("pause");
	return 0;
}