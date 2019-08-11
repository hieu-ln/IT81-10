// Bai 5 _ Chuong 5 _ DS Ke
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// DSLT su dung STACK va QUEUE va DANH SACH KE
struct Node{
	int info;
	Node *link;
};
#define MAX 20
Node* First[MAX]; // DS cac DSKE
int n; // so dinh cua do thi
char vertex[MAX]; // ten dinh

Node *sp;
Node *front, *rear;

// STACK
void initStack(){
	sp = NULL;
}
int isEmptyS(){
	if (sp == NULL)
		return 1;
	return 0;
}
void pushS(int x){
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int popS(int &x){
	if (sp != NULL){
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//end STACK

// QUEUE
void initQueue(){
	front = NULL;
	rear = NULL;
}
int isEmptyQ(){
	if (front == NULL)
		return 1;
	return 0;
}
void pushQ(int x){
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int popQ(int &x){
	if (front != NULL){
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
	}
	return 0;
}
// end QUEUE

void initGraph(int &n){

	for (int i = 0; i < n; i++)
		First[i] = NULL;
	 n = 0;
}

void insertLast(Node *&first, Node *p){
	if (first == NULL)
		first = p;
	else{
		Node *q = first;
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
} 
void inputGraphFromText(){
	string line;
	ifstream myfile("danhsachke1.txt");
	if (myfile.is_open()){
		myfile >> n;
		for(int i = 0; i <n; i++)
			myfile >> vertex[i];
		string str;
		int  i = 0;
		while (getline(myfile, str)){
			istringstream ss(str);
			int u;
			while (ss >> u){
				// Dinh u
				Node *p = new Node; 
				p->info = u;
				p->link = NULL;
				insertLast(First[i - 1], p);
			}
			i++;
		}
	}
}

void inputGraph(){
	cout << "\nNhap dinh cua do thi: "; cin >> n;
	cout << "\nNhap ten dinh: ";
	for (int i = 0; i < n; i++){
		if (i > 0)
			cout << "\nNhap DSK cua dinh thu " << i - 1 << " ( " << vertex[i - 1] << " ) " << endl;
		 int u;
		 string str;
		 while (getline(cin, str)){
			 istringstream ss(str);
			 while (ss >> u){
				// dinh u
				Node *p = new Node; 
				p->info = u;
				p->link = NULL;
				insertLast(First[i - 1], p);
			 }
			 //cout << " i " << i - 1 << endl; 
			 break;
		 }
	}
}
// 5.2 Xuat danh sach ke cua do thi
void outPutGraph(){
	for (int i = 0; i < n; i++){
		cout << "Dinh " << i <<  " ( " << vertex[i] << " ):  ";
		Node *p = First[i];
		while (p != NULL){
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}
void outPut(int a[], int n){
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}

// BFS 
int C[100], bfs[100];
int nbfs = 0;
void initC(){
	for (int i = 0; i < n; i++) // n la so dinh cua do thi
		C[i] = 1 ;
}
void BFS(int v){ // v la so dinh bat dau
	int p;
	Node *w;
	pushQ(v);
	C[v] = 0;
	while (front != NULL){
		popQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;
		while (w != NULL){
			if (C[w->info]){
				pushQ(w->info);
				C[w->info] = 0; 
			}
			w = w->link;
		}
	}
} 
// DFS
int dfs[100];
int ndfs = 0;
void DFS(int s){
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	Node *v = NULL;
	while (isEmptyS() == 0){
		if (v == NULL)
			popS(u);
		v = First[u];
		while (v != NULL){
			if (C[v->info] == 1){
				pushS(u);
				pushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}
void search_by_BFS(int x, int v){ // v la dinh bat dau
	int p;
	Node *w;
	pushQ(v);
	C[v] = 0;
	while (front != NULL){
		popQ(p);
		if(x == p){
			cout << "\nTim thay x = " << x << endl;
			return ;
		}
		w = First[p];
		while (w != NULL){
			if (C[w->info]){
				pushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "\n-----> BAI TAP 5 - CHUONG 5 - DO THI <-----\n";
	cout << "\n1. Khoi tao DANH SACH KE rong\n";
	cout << "\n2. Nhap DANH SACH KE tu file \n";
	cout << "\n3. Nhap DANH SACH KE\n";
	cout << "\n4. Xuat DANH SACH KE\n";
	cout << "\n5. Duyet do thi theo chieu rong BFS - DSK\n";
	cout << "\n6. Duyet do thi theo chieu sau DFS - DSK\n";
	cout << "\n7. Tim dinh co gia tri x theo BFS\n";
	cout << "\n8. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: "; cin >> choice;
		switch(choice){
			case 1:
				n = 5; // so luong dinh bat ky
				initGraph(n);
				cout << "\nBan vua khoi tao DANH SACH KE thanh cong !!\n";
				break;
			case 2:
				inputGraphFromText();
				cout << "\nBan tu nhap DANH SACH KE tu file: " << endl;
				outPutGraph();
				break;
			case 3:
				inputGraph();
				break;
			case 4:
				outPutGraph();
				break;
			case 5:
				initQueue();
				initC();
				cout << "\nVui long nhap dinh xuat phat: ";
				cin >> x;
				nbfs = 0;
				BFS(x);
				cout << "\nThu tu dinh sau khi duyet BFS la: " << endl;
				outPut(bfs, n);
				break;
			case 6:
				initStack();
				initC();
				cout << "\nVui long nhap dinh xuat phat: ";
				cin >> x;
				ndfs = 0;
				DFS(x);
				cout << "\nThu tu dinh sau khi duyet DFS la: " << endl;
				outPut(dfs, n);
				break;
			case 7:
				initQueue();
				initC();
				cout << "\nVui long nhap gia tri x can tim: ";
				cin >> x;
				nbfs = 0;
				search_by_BFS(x, 0);
				break;
			case 8:
				cout << "\nGoodbye....!!!\n";
				break;
			default:
				break;
		}
	}while (choice != 8);
	return 0;
}