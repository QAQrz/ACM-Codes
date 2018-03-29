#include <bits/stdc++.h>
using namespace std;
struct node{
	char s[33];
	int flag,num;
	node *l,*r;
	node(){
		l=r=NULL,num=1,flag=0;
	}
}*rt;
int n,i;
char s[33];
node* insert(node *p){
	if(!p){
		p=new node;
		strcpy(p->s,s);
		p->flag=1;
		return p;
	}
	int k=strcmp(p->s,s);
	if(!k)
		p->num++;
	else if(k>0)
		p->l=insert(p->l);
	else
		p->r=insert(p->r);
	return p;
}
void print(node *p){
	if(!p)
		return;
	print(p->l);
	if(p->flag)
		printf("%s %.4lf%%\n",p->s,100.0*p->num/n);
	print(p->r);
}
int main(){
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		gets(s);
		rt=insert(rt);
	}
	print(rt);
	return 0;
}