#include <bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,x;
}p[222222];
long long n,k,i,ans;
int cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>p[i].a;
	for(i=0;i<n;i++){
		cin>>p[i].b;
		p[i].x=p[i].a-p[i].b;
	}
	sort(p,p+n,cmp);
	for(i=0;i<n&&(i<k||p[i].x<0);i++)
		ans+=p[i].a;
	for(;i<n;i++)
		ans+=p[i].b;
	cout<<ans<<endl;
	return 0;
}