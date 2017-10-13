#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
const int MAX = 1e5+10;
const double PI = acos(-1.0);
typedef long long LL;
using namespace std;
int t,m,a[112345],l,l1,st[412345],nt[15],u,v;
char ch;
char s[112345],s1[15],s2[5];
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define MID int m=(l+r)>>1
template <class T>
inline bool read(T &ret) {
	char c;
	if(c=getchar(), c==EOF) return 0;
	while(!(c>='0' && c<='9') && !(c>='A' && c<='Z') && !(c>='a' && c<='z'))
		c=getchar();
	if((c>='A' && c<='Z') || (c>='a' && c<='z')) {
		ret = c;
		return 1;
	}
	ret = c-'0';
	while(c=getchar(), c>='0'&&c<='9') ret = ret*10 + (c-'0');
	return 1;
}
void PushUp(int rt) {
	st[rt] = st[rt<<1] + st[rt<<1|1];
}
void Build(int l, int r, int rt) {
	if(l == r) {
		st[rt] = a[l];
		return;
	}
	MID;
	Build(lson);
	Build(rson);
	PushUp(rt);
}
void Rebuild(int L, int R, int l, int r, int rt) {
	if(R<l || L>r) return;
	if(l == r) {
		st[rt] = a[l];
		return;
	}
	MID;
	Rebuild(L, R, lson);
	Rebuild(L, R, rson);
	PushUp(rt);
}
void Update(int p, int v, int l, int r, int rt) {
	if(l == r) {
		st[rt] = v;
		return;
	}
	MID;
	if(p <= m) Update(p, v, lson);
	else Update(p, v, rson);
	PushUp(rt);
}
int Query(int L, int R, int l, int r, int rt) {
	if(L<=l && r<=R) return st[rt];
	MID;
	int ret = 0;
	if(L <= m) ret += Query(L, R, lson);
	if(R > m) ret += Query(L, R, rson);
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	scanf("%d", &t);
	int i,j;
	while(t--) {
		scanf("%d %s %s", &m, s, s1);
		l=(int)strlen(s),l1=(int)strlen(s1);
		for(int i=0; i<=l; ++i) {
			a[i] = 0;
		}
		nt[i=0]=j=-1;
		while(i<l1) {
			while(~j&&s1[i]!=s1[j])
				j=nt[j];
			nt[++i]=++j;
		}
		i=j=0;
		while(i<l) {
			while(~j&&s[i]!=s1[j])
				j=nt[j];
			i++,j++;
			if(j>=l1)
				a[i]=1,j=nt[j];
		}
		Build(1,l,1);
		while(m--) {
			scanf("%s", s2);
			if(s2[0]=='C') {
				read(u);
				read(ch);
				if(s[u-1] == ch) continue;
				s[u-1]=ch;
				i=max(0,u-l1),j=0;
				while(i<u-1+l1&&i<l) {
					if(i>=u-1)
						a[i+1]=0;
					while(~j&&s[i]!=s1[j])
						j=nt[j];
					i++,j++;
					if(j>=l1)
						a[i]=1,j=nt[j];
				}
				Rebuild(u, min(u+l1-1, l),1,l,1);
			} else {
				read(u);
				read(v);
				if(u>v)
					swap(u,v);
				u+=l1-1;
				printf("%d\n", (u<=v?Query(u,v,1,l,1):0));
			}
		}
		printf("\n");
	}
	return 0;
}