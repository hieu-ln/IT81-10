// Bai 4 - Chuong 5 - Do Thi
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX]; // mang 2 chieu
int n; // so dinh cua do thi
char vertex[MAX]; // ten dinh

// DSLK su dung cho STACK va QUEUE
struct Node{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

//STACK
void InitStack() {
	sp = NULL;
}

int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
// end STACK

// QUEUE
void InintQueue()
{
	front = NULL;
	rear = NULL;
}

int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}

void PushQ(int x)
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

int PopQ(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
// end QUEUE

void InitGraph(){
	n = 0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile ("matranke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
	}
}

// 4.1 Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "\nNhap so dinh do thi n = "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap ten dinh: "; cin >> vertex[i];
		cout << "\\nNhap vao dong thu: " << i + 1  << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}

// 4.2 Xuat ma tran ke cua do thi
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]] << "  ";
}

// 4.3 Duyet do thi theo chieu rong BFS(Dung QUEUE va DSLK Don)
int C[100], bfs[100];
int nbfs = 0;
void InitC(){
	for(int i = 0; i < n; i++) // n la so dinh cua do thi
		C[i] = 1;
}
void BFS(int v) // v dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
			if (C[w] && A[p][w] ==1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

// 4.4 Duyet do thi theo chieu sau DFS (Dung STACK va DSLK Don)
int dfs[100];
int ndfs = 0;
void DFS(int s){

	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
	
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
			if (A[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

// 4.5 Dung BFS tim x tren do thi
void searchByBFS(int x, int v) { // v la dinh bat dau

	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL) {
	
		PopQ(p);
		if (x == p) {
		
			cout << "\nTim thay x = " << x << endl;
			return;
		}
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, sp, sp_b, x, i;
	cout << "\n-----> BAI TAP 4 - CHUONG 5 - DO THI <-----\n";
	cout << "\n1. Khoi tao MA TRAN KE rong\n";
	cout << "\n2. Nhap MA TRAN KE tu file text\n";
	cout << "\n3. Nhap MA TRAN KE\n";
	cout << "\n4. Xuat MA TRAN KE\n";
	cout << "\n5. Duyet do thi theo chieu rong BFS - DSLK\n";
	cout << "\n6. Duyet do thi theo chieu sau DFS - DSLK\n";
	cout << "\n7. Tim dinh co gia tri x theo BFS\n";
	cout << "\n8. Thoat\n";
	do{
		cout << "\nVui long ban so de thuc hien: "; cin >> choice;
		switch(choice){
		
			case 1:
				InitGraph();
				cout << "\nBan da khoi tao MA TRAN KE thanh cong !\n";
				break;
			case 2:
				inputGraphFromText();
				cout << "\nBan vua nhap MA TRAN KE tu file\n";
				outputGraph();
				break;
			case 3:
				inputGraph();
				break;
			case 4:
				outputGraph();
				break;
			case 5:
				InintQueue();
				InitC();
				cout << "\nVui long nhap dinh xuat phat: ";
				cin >> x;
				nbfs = 0;
				BFS(x);
				cout << "\nThu tu dinh sau khi duyet BFS: \n";
				output(bfs, n);
				break;
			case 6:
				InitStack();
				InitC();
				cout << "\nVui long nhap dinh xuat phat: ";
				cin >> x;
				ndfs = 0;
				DFS(x);
				cout << "\nThu tu dinh sau khi duyet DFS: \n";
				output(dfs, n);
				break;
			case 7:
				cout << "\nVui long nhap gia tri x can tim: "; cin >> x;
				InintQueue();
				InitC();
				nbfs = 0;
				searchByBFS(x, 0);
				break;
			case 8:
				cout << "\nGoodbye !!!\n";
				break;
			default:
				cout << "\nChon sai. Chon lai !!!\n";
				break;
		}
	}while (choice != 8 );
	return 0;
}