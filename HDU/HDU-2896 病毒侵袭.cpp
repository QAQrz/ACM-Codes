#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=512,maxm=1024,maxc=128;
struct trie{
	int flag,vis;
	trie *next[maxc],*fail;
	trie(){
		memset(next,0,sizeof(next));
		vis=flag=0,fail=NULL;
	}
};
int ans,n,m,k,num,a[maxn],i;
void insert(trie *p,char *s,int x){
	while(*s){
		if(!p->next[*s])
			p->next[*s]=new trie;
		p=p->next[*s++];
	}
	p->flag=x;
}
void makefail(trie *root){
	queue<trie*>q;
	q.push(root);
	while(!q.empty()){
		trie *p=q.front();
		q.pop();
		for(i=0;i<maxc;i++)
			if(p->next[i]){
				p->next[i]->fail=(p==root)?p:p->fail->next[i];
				q.push(p->next[i]);
			}
			else
				p->next[i]=(p==root)?p:p->fail->next[i];
	}
}
void match(trie *p,char *s,int x){
	num=0;
	while(*s){
		p=p->next[*s++];
		trie *temp=p;
		while(temp&&temp->flag&&temp->vis<x)
			a[num++]=temp->flag,temp->vis=x,temp=temp->fail;
	}
}
int main(){
	char s[maxm*10];
	trie *root=new trie;
	scanf("%d\n",&n);
	for(k=1;k<=n;k++){
		gets(s);
		insert(root,s,k);
	}
	makefail(root);
	scanf("%d\n",&m);
	for(k=1;k<=m;k++){
		gets(s);
		match(root,s,k);
		if(num){
			ans++;
			printf("web %d: ",k);
			sort(a,a+num);
			for(i=0;i<num;i++)
				printf(i<num-1?"%d ":"%d\n",a[i]);
		}
	}
	printf("total: %d\n",ans);
	return 0;
}