#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[11234],x,l,r,num;
int main(){
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(m--){
		scanf("%d %d %d",&l,&r,&x);
		for(i=l,num=0;i<x;i++)
			if(a[i]>a[x])
				num++;
		for(i=x+1;i<=r;i++)
			if(a[i]<a[x])
				num--;
		printf("%s\n",num?"No":"Yes");
	}
	return 0;
}