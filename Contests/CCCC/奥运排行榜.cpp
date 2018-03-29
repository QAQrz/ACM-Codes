#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	double d,e;
}p[255];
int n,m,i,x,a[4],k;
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		p[i].d=1.0*p[i].a/p[i].c,p[i].e=1.0*p[i].b/p[i].c;
	}
	while(m--){
		cin>>x;
		memset(a,0,sizeof a);
		k=0;
		for(i=0;i<n;i++)
			if(i!=x){
				if(p[i].a>p[x].a)
					a[0]++;
				if(p[i].b>p[x].b)
					a[1]++;
				if(p[i].d>p[x].d)
					a[2]++;
				if(p[i].e>p[x].e)
					a[3]++;
			}
		for(i=1;i<4;i++)
			if(a[i]<a[k])
				k=i;
		printf("%d:%d%c",a[k]+1,k+1,m?' ':'\n');
	}
	return 0;
}