#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	node *l,*r;
	node(){
		l=r=NULL;
	}
}*rt;
int n,a[33],b[33];
node *insert(int a[],int b[],int l){
	if(l<1)
		return NULL;
	int i;
	for(i=0;i<l;i++)
		if(b[i]==a[l-1])
			break;
	node *p=new node;
	p->x=b[i];
	p->l=insert(a,b,i);
	p->r=insert(a+i,b+i+1,l-i-1);
	return p;
}
void print(node *p){
	if(!p)
		return;
	printf(" %d",p->x);
	print(p->l);
	print(p->r);
}
int main(){
	cin>>n;
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n;i++)
		if(b[i]==a[n-1])
			break;
	rt=new node;
	rt->x=b[i];
	rt->l=insert(a,b,i);
	rt->r=insert(a+i,b+i+1,n-i-1);
	cout<<"Preorder:";
	print(rt);
	cout<<endl;
	return 0;
}