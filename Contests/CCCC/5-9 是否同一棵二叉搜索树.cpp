#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	node *l,*r;
	node(){
		l=r=NULL;
	}
}*rt,*rt1;
int n,m,i,a;
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
int check(node *p1,node *p2){
	if(!(p1||p2))
		return 1;
	if(!(p1&&p2))
		return 0;
	if(p1->x!=p2->x)
		return 0;
	return check(p1->l,p2->l)&&check(p1->r,p2->r);
}
int main(){
	while(~scanf("%d",&n)&&n){
		scanf("%d",&m);
		rt=NULL;
		for(i=0;i<n;i++){
			scanf("%d",&a);
			rt=insert(rt,a);
		}
		while(m--){
			rt1=NULL;
			for(i=0;i<n;i++){
				scanf("%d",&a);
				rt1=insert(rt1,a);
			}
			printf(check(rt,rt1)?"Yes\n":"No\n");
		}
	}
	return 0;
}