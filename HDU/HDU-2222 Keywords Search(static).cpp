#include <bits/stdc++.h>
using namespace std;
const int maxn=1000086,maxc=26;
struct trie{
	int next[maxc],flag,fail;
	void init(){
		memset(next,0,sizeof(next));
		flag=fail=0;
	}
}tree[maxn];
int cnt;
void insert(char *s){
	int p=0;
	while(*s){
		if(!tree[p].next[*s-'a']){
			tree[++cnt].init();
			tree[p].next[*s-'a']=cnt;
		}
		p=tree[p].next[*s++-'a'];
	}
	tree[p].flag++;
}
void makefail(){
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int i=0;i<maxc;i++)
			if(tree[p].next[i]){
				tree[tree[p].next[i]].fail=p?tree[tree[p].fail].next[i]:0;
				q.push(tree[p].next[i]);
			}
			else
				tree[p].next[i]=p?tree[tree[p].fail].next[i]:0;
	}
}
int match(char *s){
	int p=0,ans=0,temp;
	while(*s){
		temp=p=tree[p].next[*s++-'a'];
		while(tree[temp].flag)
			ans+=tree[temp].flag,tree[temp].flag=0,temp=tree[temp].fail;
	}
	return ans;
}
int main(){
	int t,n;
	char s[maxn];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		tree[cnt=0].init();
		while(n--){
			scanf("%s",s);
			insert(s);
		}
		scanf("%s",s);
		makefail();
		printf("%d\n",match(s));
	}
	return 0;
}