#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,h;
	node *l,*r;
	node(){
		l=r=NULL;
	}
}*rt;
int n,i,x,flag,k,ans;
node *insert(node *p,int x,int h){
	if(!p){
		p=new node;
		p->x=x,p->h=h;
		return p;
	}
	if(x>p->x)
		p->l=insert(p->l,x,h+1);
	else
		p->r=insert(p->r,x,h+1);
	return p;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		rt=insert(rt,x,1);
	}
	queue<node*>q;
	q.push(rt);
	while(q.size()){
		node *p=q.front();
		q.pop();
		if(k)
			printf(" ");
		else
			k++;
		printf("%d",p->x);
		if(p->l)
			q.push(p->l);
		if(p->r)
			q.push(p->r);
		if(p->r&&!p->l)
			ans=1;
		if(!flag&&!(p->l&&p->r)){
			flag=1;
			continue;
		}
		if(flag&&(p->l||p->r))
			ans=1;
	}
	printf("\n%s\n",ans?"NO":"YES");
	return 0;
}