#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	node *l,*r;
	node(){
		l=r=NULL;
	}
};
int n,a[1024],i,cnt,cnt1,num;
node *rt,*rt1;
node *insert(node *p,int x){
	if(!p){
		p=new node;
		p->x=x;
		return p;
	}
	if(x<p->x)
		p->l=insert(p->l,x);
	else
		p->r=insert(p->r,x);
	return p;
}
node *insert1(node *p,int x){
	if(!p){
		p=new node;
		p->x=x;
		return p;
	}
	if(x>=p->x)
		p->l=insert1(p->l,x);
	else
		p->r=insert1(p->r,x);
	return p;
}
int check(node *p){
	if(!p)
		return 1;
	if(p->x!=a[cnt])
		return 0;
	cnt++;
	return check(p->l)&&check(p->r);
}
int check1(node *p){
	if(!p)
		return 1;
	if(p->x!=a[cnt1])
		return 0;
	cnt1++;
	return check1(p->l)&&check1(p->r);
}
void print(node *p){
	if(!p)
		return;
	print(p->l);
	print(p->r);
	printf("%d%c",p->x,num++<n-1?' ':'\n');
}
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		rt=insert(rt,a[i]);
		rt1=insert1(rt1,a[i]);
	}
	if(check(rt)){
		cout<<"YES"<<endl;
		print(rt);
	}
	else if(check1(rt1)){
		cout<<"YES"<<endl;
		print(rt1);
	}
	else
		cout<<"NO"<<endl;
	return 0;
}