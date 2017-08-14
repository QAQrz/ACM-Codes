#include <bits/stdc++.h>
using namespace std;
const int maxn=1000086,maxc=26;
struct trie{
	trie *next[maxc],*fail;
	int flag;
	trie(){
		memset(next,0,sizeof next);
		fail=NULL,flag=0;
	}
};
void insert(trie *p,char *s){
	while(*s){
		if(!p->next[*s-'a'])
			p->next[*s-'a']=new trie;
		p=p->next[*s++-'a'];
	}
	p->flag++;
}
void makefail(trie *root){
	queue<trie*>q;
	q.push(root);
	while(q.size()){
		trie *p=q.front();
		q.pop();
		for(int i=0;i<maxc;i++)
			if(p->next[i]){
				p->next[i]->fail=(p==root)?p:p->fail->next[i];
				q.push(p->next[i]);
			}
			else
				p->next[i]=(p==root)?p:p->fail->next[i];
	}
}
int match(trie *p,char *s){
	int ans=0;
	while(*s){
		p=p->next[*s++-'a'];
		trie *temp=p;
		while(temp&&temp->flag)
			ans+=temp->flag,temp->flag=0,temp=temp->fail;
	}
	return ans;
}
int main(){
	int t,n,i;
	char s[maxn];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		trie *root=new trie;
		while(n--){
			scanf("%s",s);
			insert(root,s);
		}
		scanf("%s",s);
		makefail(root);
		printf("%d\n",match(root,s));
	}
	return 0;
}