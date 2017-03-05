#include <bits/stdc++.h>
using namespace std;
struct node{
	int num,sum,id;
}p[10086];
int n,i,k,a,b;
int cmp(node a,node b){
	if(a.sum==b.sum){
		if(a.num==b.num)
			return a.id<b.id;
		return a.num>b.num;
	}
	return a.sum>b.sum;
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		p[i].id=i;
		while(k--){
			cin>>a>>b;
			p[a].num++,p[a].sum+=b,p[i].sum-=b;
		}
	}
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)
		printf("%d %.2lf\n",p[i].id,0.01*p[i].sum);
	return 0;
}