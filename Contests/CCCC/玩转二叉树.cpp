#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	node *l,*r;
	node(){
		l=r=NULL;
	}
};
int n,i,a[33],b[33];
node *cal(int a[],int b[],int l){
	if(l<1)
		return NULL;
	int j;
	node *p=new node;
	p->x=b[0];
	for(j=0;j<l;j++)
		if(a[j]==b[0])
			break;
	p->l=cal(a,b+1,j);
	p->r=cal(a+j+1,b+j+1,l-j-1);
	return p;
}
int main(){	
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	node *rt=new node;
	rt->x=b[0];
	for(i=0;i<n;i++)
		if(a[i]==b[0])
			break;
	rt->l=cal(a,b+1,i);
	rt->r=cal(a+i+1,b+i+1,n-i-1);
	queue<node*>q;
	q.push(rt);
	while(q.size()){
		node *p=q.front();
		if(p->r)
			q.push(p->r);
		if(p->l)
			q.push(p->l);
		printf("%d%c",p->x,q.size()<2?'\n':' ');
		q.pop();
	}
	return 0;
}