// Bai 11 - Chuong 2 - QUEUE - List Linked
#include <iostream>
using namespace std;

// 11.1 Khai bao
struct Node{
	int info;
	Node *link;
};
Node *front, *rear;

// 11.2 Khoi tao QUEUE rong
void init()
{
	front = NULL;
	rear = NULL;
}

// 11.3 Kiem tra QUEUE rong
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}
// 11.4 Them phan tu vao QUEUE 
void Push(int x)
{
	Node *p = new Node; // cap phat phan tu moi
	p->info = x; // gan gia tri bien x cho vung info
	p->link = NULL; // gan gia tti NULL cho vung link
	if(rear == NULL)
		front = p;
	else
		rear->link = p; // rear khac NULL gan gia tri dia chi bo nho cua p cho vung link cua rear
	rear = p; 
}

// 11.4 Lay phan tu ra khoi QUEUE
int Pop(int &x)
{
	if (front != NULL)
	{
		Node *p = front; // gan gia tri bo nho cua phan tu dau ds cho bien p
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

// Xuat QUEUE
void Process_queue()
{
	Node *p = front;
	cout << "<---   ";
	//do{
	//	cout << p->info << "   ";
	//	p = p->link;
	//}while(p != NULL);
	while(p != NULL)
	{
		cout << p->info << "   ";
		p= p->link;
	}
	cout << "<---\n";
}
int main()
{
	Node *p;
	int x, choice, i;
	char tt;
	do{
		system("cls");
		cout << "\n-----> BAI TAP 11 - CHUONG 2 - QUEUE (HANG DOI - DSLK) <----- \n";
		cout << "\n1. Khoi tao QUEUE rong \n";
		cout << "\n2. Them phan tu vao QUEUE \n";
		cout << "\n3. Lay phan tu ra khoi QUEUE \n";
		cout << "\n4. Kiem tra QUEUE co rong hay khong \n";
		cout << "\n5. Kiem tra QUEUE co day hay khong \n";
		cout << "\nBan chon: "; cin >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "\nBan da khoi tao QUEUE thanh cong !\n";
				break;
			case 2:
				cout << "\nVui long nhap vao gia tri x = "; cin >> x;
				Push(x);
				cout << "\nQUEUE sau khi them la: ";
				Process_queue();
				break;
			case 3:
				Pop(x);
				cout << "\nPhan tu lay ra tu QUEUE la x = " << x << endl;
				cout << "\nQUEUE sau khi lay ra la: ";
				Process_queue();
				break;
			case 4:
				i = isEmpty();
				if (i == 0)
					cout << "\nQUEUE khong rong !\n";
				else
					cout << "\nQUEUE rong !\n";
				break;
			case 5:
				cout << "\nQUEUE hien tai la: ";
				Process_queue();
				break;
			default:
				cout << "\nBan da chon sai cac lua chon !!!\n";
		}
		cout << "\nBan co muon tiep tuc khong (Y / N): "; cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}