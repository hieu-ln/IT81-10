#include<iostream>
using namespace std;
#define MAX 100
int a[MAX];
int sp;
void init(int a[], int &sp)
{
	sp=-1;
}
int push(int a[], int &sp, int x)
{
	if(sp < MAX-1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int pop(int a[], int &sp, int &x)
{
	if(sp!=-1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}
int isfull(int a[], int sp)
{
	if(sp == MAX -1)
		return 1;
	return 0;
}
int isempty(int a[], int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}
void xuat( int a[], int sp)
{
		for(int i=sp;i>=0;i--)
			cout<<a[i]<<endl;
}
void xuat2( int a[], int sp)
{
		for(int i=0;i<=sp;i++)
			cout<<a[i]<<endl;
}
int nhiphan(int so)
{
	init (a,sp);
	int np=0;
	while(so!=0)
	{
		int du=so%2;
		if(push(a,sp,du))
			so/=2;
		else
			break;
	}
	while(!isempty(a,sp))
	{
		int x;
		if(pop(a,sp,x))
			np=np*10+x;
		else
			break;
	}
	return np;
}
int main()
{
	int x,t,chon,n;
	char tt;
	do{
		cout<<"\nNhap chon:\n"
			<<"1.khoi tao\n"
			<<"2.kiem tra rong\n"
			<<"3.kiem tra day\n"
			<<"4.them 1 phan tu\n"
			<<"5.xoa 1 phan tu\n"
			<<"6.doi 1 so thap phan sang nhi phan\n"
			<<"7.xuat danh sach\n"
			<<"Chon: ";
		cin>>chon;
		switch(chon)
		{
			case 1:
				init(a, sp);
				cout<<"Khoi tao danh sach thanh cong\n";
				break;
			case 2:
				if(isempty(a,sp)!=0)
					cout<<"Danh sach rong\n";
				else
					cout<<"Danh sach khong rong\n";
				break;
			case 3:
				if(isfull(a,sp)!=0)
					cout<<"Danh sach day\n";
				else
					cout<<"Danh sach chua day\n";
				break;
			case 4:
				cout<<"Nhap gia tri muon them: ";
				cin>>x;
				t=push(a, sp,x);
				if(t!=0)
					cout<<"Them thanh cong!\n";
				else
					cout<<"Stack day khong the them!\n";
				break;
			case 5:
				t=pop(a,sp,x);
				if(t!=0)
					cout<<"Phan tu lay ra co gia tri"<<x<<"\n";
				else
					cout<<"Stack rong!\n";
				break;
			case 6:
				cout<<"Nhap gia tri can doi nhi phan: ";
				cin>>n;
				cout<<"So sau khi chuyen sang nhi phan la: ";
				cout<<nhiphan(n)<<endl;
				break;
			case 7:
				cout<<"Danh sach cua stack:\n";
				xuat2(a,sp);
				break;
			default:
				cout<<"Gia tri chon khong hop le!\n";
				break;
		}
		cout<<"Ban muon tiep tuc khong(Y/N):";
		cin>>tt;
	}while(tt=='y'||tt=='Y');
	return 0;
}