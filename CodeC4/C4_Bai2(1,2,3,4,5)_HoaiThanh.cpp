#include <iostream>
using namespace std;
#define count 10
struct Node
{
	int info;
	Node *left;
	Node *right;
 };
Node *root;

void tree_empty()
{
	root = NULL;
}
void them(Node* a, int x)
{
	Node* newNode = new Node;      
	Node* b;
	newNode->info = x;
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		b = NULL;
		while (true)
		{
			b = a;
			if (x < b->info)
			{
				a = a->left;
				if (a == NULL)
				{
					b->left = newNode;
					return;
				}
			}
			else if (b->info == x)
			{
				return;
			}
			else
			{
				a = a->right;
				if (a == NULL)
				{
					b->right = newNode;
					return;
				}
			}
		}
	}
}

Node *SearchTree( Node*p ,int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
		{
			if (p->info > x)
				p = p->right;
			else
				p = p->left;
		}
	}
	return NULL;
}
void print(Node *p, int space)
{
	if (p == NULL)
		return;
	space += count;
	print(p->right, space);
	cout << endl;
	for (int i = count; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	print(p->left, space);
}
void Process_Print()
{
	print(root, 0);
}
void SeachStandFor(Node *&p, Node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		SeachStandFor(p, q->left);
}
int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else
			SeachStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);

}
int main()
{
	int i, chon, x;
	system("cls");
	cout << "\t\t\n\nBai 2-Chuong 4\t\t\n\n";
	cout << "1. Khoi tao cay rong\n";
	cout << "2. Them mot phan tu vao cay\n";
	cout << "3. xoa mot node trong cay"
	cout << "4. Thoat\n";
	do
	{
		cout << "Vui long nhap yeu cau: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			tree_empty();
			cout << "Khoi tao cay rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri can them vao cay NPTK: ";
			cin >> x;
			them(root, x);
			cout << "Cay NPTK sau khi duoc them: \n";
			Process_Print();
			break;
		case 3:
			int z;
			cout << "nhap 1 phan tu muon xoa trong cay : ";
			cin >> z;
			if (Delete(root, z))
				cout << "xoa thanh cong " << endl;
			else
				cout << "xoa khong thanh cong " << endl;
			break;
		case 4:
			cout << "tam biet !"
		default:
			cout << "lua chon tu 1 den 4"
			break;
		}
	} while (chon != 4);
	system("pause");
	return 0;
}