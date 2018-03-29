#include <bits/stdc++.h>
using namespace std;
struct node{
	node *l,*r;
	node(){
		l=r=NULL;
	}
}*rt;
int n,ans;
char s1[55],s2[55];
node *insert(node *p,char *s1,char *s2,int l,int s){
	if(l<1)
		return NULL;
	int i;
	p=new node;
	ans=max(ans,s);
	for(i=0;i<l;i++)
		if(s1[0]==s2[i])
			break;
	p->l=insert(p->l,s1+1,s2,i,s+1);
	p->r=insert(p->r,s1+i+1,s2+i+1,l-i-1,s+1);
	return p;
}
int main(){
	cin>>n>>s1>>s2;
	rt=insert(rt,s1,s2,n,1);
	printf("%d\n",ans);
	return 0;
}