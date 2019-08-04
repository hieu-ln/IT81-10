#include <iostream>
using namespace std;
#define count 10

struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node* root;

void tree_empty()
{
	root = NULL;
}

void InsertNode (Node *&p, int x)
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
			return;
		else if( p->info > x)
			return InsertNode(p->left,x);
		else
			return InsertNode(p->right,x);
	}
		

}

void print (Node *p, int space)
{
	if (p==NULL)
		return;
	space += count;
	print(p->right, space);
	cout << endl;
	for ( int i = count ; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	print(p->left,space);
}

void Process_Print ()
{
	print(root,0);
}

Node *Search (Node *p,int x)
{
	while(p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info > x)
				p = p->left;
			else
				p=p->right;
	}
	return NULL;

}

void duyetLNR (Node *p)
{
	if (p!=NULL)
	{
		duyetLNR(p->left);
		cout << p->info <<" ";
		duyetLNR(p->right);
	}
}

void duyetNLR (Node *p)
{
	if (p!= NULL)
	{
		cout << p->info << " ";
		duyetLNR(p->left);
		duyetLNR(p->right);
	}
}
void duyetLRN (Node *p)
{
	if ( p != NULL)
	{
		duyetLNR(p->left);
		duyetLNR(p->right);
		cout << p->info <<"";
	}
}

void SeachStandFor(Node *&p, Node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q= q->right;
	}
	else
		SeachStandFor(p,q->left);
}

int Delete (Node *&T, int x)
{
	if ( T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p =T;
		if ( T-> left == NULL)
			T = T->right;
		else if ( T->right == NULL)
			T =T->left;
		else
			SeachStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right,x);
	if (T->info > x)
		return Delete(T->left,x);

}

int countNode( Node*&p )
{
	if ( p == NULL)
		return 0;
	else
		return 1+ countNode(p->left) + countNode(p->right);
}

int SearchMax (Node *p)
{
	if (p == NULL )
		return INT_MIN;
	else
	{
		while(p->right != NULL)
			p=p->right;
		return p->info;
	}
}

int CountNodeLeftTree (Node *p)
{
	if( p == NULL || p->left == NULL)
		return 0;
	else
		return countNode( p->left);
}

int main()
{
	int chon  = 0;
	cout << "\t\t\n\n --Menu \t\t\n\n" <<endl
		<<"1. khoi tao rong "<< endl
		<<"2. xuat cay nhi phan " << endl
		<<"3. them mot phan tu vao cay "<<endl
		<<"4. tim phan tu trong cay " << endl
		<<"5. xoa mot nut trong cay " << endl
		<<"6. duyet cay theo LNR " << endl
		<<"7. duyet cay theo NLR " << endl
		<<"8. duyet cay theo LRN " << endl
		<<"9. dem node trong cay" << endl
		<<"10. tim node lon nhat" << endl
		<<"11. dem so node trai " << endl
		<<"12. thoat " << endl;
	do{
		cout <<"\nnhap vao lua chon cua ban : ";
		cin >> chon;
		switch(chon)
		{
			case 1:
				tree_empty();
				cout << "khoi tao cay rong thanh cong " << endl;
				break;
			case 2:
				Process_Print();
				break;
			case 3:
				int x;
				cout << "nhap gia tri ban muon them vao cay :" ;
				cin >> x;
				InsertNode(root, x);
				break;
			case 4:
				int y;
				cout << "nhap gia tri ban muon tim trong cay : " ;
				cin >> y;
				if(Search(root,x))
					cout << "tai dia chi : " << Search(root,x) << endl;
				else
					cout << " khong co phan tu trong cay " << endl;
				break;
			case 5:
				int z;
				cout << "nhap 1 phan tu muon xoa trong cay : " ;
				cin >> z;
				if(Delete(root,z))
					cout << "xoa thanh cong " << endl;
				else
					cout << "xoa khong thanh cong " << endl;
				break;
			case 6:
				duyetLNR(root);
				break;
			case 7:
				duyetNLR(root);
				break;
			case 8:
				duyetLRN(root);
				break;
			case 9:
				if(countNode(root) == 0)
					cout << "mang rong " ;
				else
					cout << "so Node la : "<< countNode(root) << endl;
				break;
			case 10:
				if(SearchMax(root) == NULL)
					cout << "mang rong " << endl;
				else
					cout << " Node lon nhat la :" << SearchMax(root) << endl;
				break;
			case 11:
				if(CountNodeLeftTree(root))
					cout << "so node la:" <<CountNodeLeftTree(root) << endl;
				else
					cout << "mang rong" << endl;
				break;
			case 12:
				cout << "thoat" << endl;
				break;
			default:
				cout << "nhap tu 1 den 9" << endl;
		}
	}while( chon != 12);
	system("pause");
	return 0;
}