// Bai 1 _ Chuong 4 - Cay nhi phan tim kiem
#include <iostream>
using namespace std;

#define COUNT 10
// 1.1 Khai bao cau truc cay nhi phan 
struct Node{
	int info;		// Luu tru gia tri cua phan tu, gia tri khoa cua Node
	Node *left;		// Left luu tru dia chi phan tu ben trai (cay con trai)
	Node *right;	// Left luu tru dia chi phan tu ben phai (cay con phai)
};
Node *root; // Node goc

// Khoi tao cay rong
void Init(){
	root = NULL;
}

// 1.3 Them mot phan tu vao cay (dung de quy)
//su dung dia con tro
void Insert_Node(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(p->info == x)
			return; // da co gia tri x
		else if(p->info > x)
				return Insert_Node(p->left, x);
			else
				return Insert_Node(p->right, x);
	}
}

// 1.4 Tim phan tu trong Cay NPTK
Node *search(Node *p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else if (x > p->info)
				return search(p->right, x);
			else
				return search(p->left, x);

	}
	return NULL;
}
void searchStandFor(Node *&p, Node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
// 1.5 Xoa mot node trong cay (su dung dia chi con tro)
int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p = T;
		if(T->left == NULL)
			T = T->right;
		else if(T->right == NULL)
				T = T->left;
			else // co 2 con
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
}

// 1.6 Duyet cay theo thu tu LNR (dung de quy)
void duyetLNR(Node *p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << "	";
		duyetLNR(p->right);
	}
}

// 1.7 Duyet cay theo thu tu NLR (dung de quy)
void duyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << "	";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

// 1.8 Duyet cay theo thu tu LRN (dung de quy)
void duyetLRN(Node *p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << "	";
	}
}

// Xuat Cay NPTK
void print2DUtil(Node *p, int space)
{
	// Base case
	if (p == NULL)
		return;
	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(p->right, space);

	// Print current node after space 
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout <<" ";
	cout << p->info << "\n";

	//Process left child
	print2DUtil(p->left, space);
}

// Wrapper over print2DUtil
void Process_Tree()
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}
int main()
{
		int x, i, choice;
		char tt;
		Node *p;
		cout << "\n----->	BAI TAP 1 - CHUONG 4 - CAY NPTK		<-----\n";
		cout << "\n1. Khoi tao cay NPTK rong\n";
		cout << "\n2. Them phan tu vao CAY NPTK\n";
		cout << "\n3. Tim kiem phan tu co gia tri x trong cay NPTK\n";
		cout << "\n4. Xoa phan tu co gia tri x trong cay NPTK\n";
		cout << "\n5. Duyet cay NPTK theo LNR\n";
		cout << "\n6. Duyet cay NPTK theo NLR\n";
		cout << "\n7. Duyet cay NPTK theo LRN\n";
		cout << "\n8. Xuat cay NPTK\n";
		cout << "\n9.Thoat\n";
		do{
			cout << "\nBan chon: ";
			cin >> choice;
			switch(choice)
			{
				case 1:
					Init();
					cout << "\nBan da khoi tao cay NPTK rong thanh cong !\n";
					break;
				case 2:
					cout << "\nVui long nhap gia tri can them x = "; cin >> x;
					Insert_Node(root, x);
					cout << "\nCay NPTK sau khi them la: " << endl;
					Process_Tree();
					break;
				case 3:
					cout << "\nVui long nhap gia tri can tim x = "; cin >> x;
					p = search(root, x);
					if (p != NULL)
						cout << "\nTim thay x = " << x << " trong cay NPTK\n";
					else
						cout << "\nKhong tim x = " << x << " trong cay NPTK\n";
					break;
				case 4:
					cout << "\nVui long nhap gia tri can xoa x = "; cin >> x;
					i = Delete(root, x);
					if (i == 0)
						cout << "\nKhong tim thay x = " << x << " de xoa !\n";
					else
					{
						cout << "\nDa xoa thanh cong phan tu x = " << x << " trong cay NPTK\n";
						cout << "\nCay NPTK sau khi xoa la: ";
						Process_Tree();
					}
					break;
				case 5:
					cout << "\nCay NPTK duyet theo LNR la: ";
					duyetLNR(root);
					cout << endl;
					break;
				case 6:
					cout << "\nCay NPTK duyet theo NLR la: ";
					duyetNLR(root);
					cout << endl;
					break;
				case 7:
					cout << "\nCay NPTK duyet theo LRN la: ";
					duyetLRN(root);
					cout << endl;
					break;
				case 8:
					cout << "\nCay NPTK nhu sau: ";
					Process_Tree();
					break;
				case 9:
					cout << "\nGoodbye... !!\n";
					break;
				default:
					break;
			}
	}while (choice != 9);
	return 0;
}