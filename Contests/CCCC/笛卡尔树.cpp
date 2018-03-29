#include <bits/stdc++.h>
using namespace std;
struct node{
	int k1,k2,l,r;
}p[1024];
int n,i;
int main(){
	cin>>n;
	for(i=0;i<n;i++)
		cin>>p[i].k1>>p[i].k2>>p[i].l>>p[i].r;
	for(i=0;i<n;i++){
		if(~p[i].l&&(p[p[i].l].k1>=p[i].k1||p[p[i].l].k2<=p[i].k2))
			break;
		if(~p[i].r&&(p[p[i].r].k1<=p[i].k1||p[p[i].r].k2<=p[i].k2))
			break;
		p[i].k1=max(p[i].k1,p[p[i].r].k1);
	}
	cout<<(i<n?"NO":"YES")<<endl;
	return 0;
}