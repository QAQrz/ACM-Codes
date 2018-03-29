#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,v;
	char s[10];
}p[55];
struct per{
	int i,j;
}a[55];
int n,i,j,t;
int cmp(per a,per b){
	return a.i<b.i;
}
int main(){
	cin>>n;
	for(i=0;i<n;i++)
		cin>>p[i].x>>p[i].s;
	for(i=0;i<n;i++)
		if(!p[i].v){
			p[i].v=1;
			for(j=n-1;j>=0;j--)
				if(p[i].x!=p[j].x&&!p[j].v){
					p[j].v=1,a[t].i=min(i,j),a[t++].j=max(i,j);
					break;
				}
		}
	sort(a,a+t,cmp);
	for(i=0;i<t;i++)
		cout<<p[a[i].i].s<<" "<<p[a[i].j].s<<endl;
	return 0;
}