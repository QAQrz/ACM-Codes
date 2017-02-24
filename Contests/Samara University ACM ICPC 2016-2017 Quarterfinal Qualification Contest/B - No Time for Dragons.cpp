#include <bits/stdc++.h>
using namespace std;
struct node{
	long long l,r,num;
}p[222222];
long long n,i,ans,num;
int cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>p[i].r>>p[i].l;
		p[i].num=p[i].r-p[i].l;
	}
	sort(p,p+n,cmp);
	for(i=0;i<n;i++)
		if(num<p[i].r)
			ans+=p[i].r-num,num=p[i].num;
		else
			num-=p[i].l;
	cout<<ans<<endl;
	return 0;
}