#include <bits/stdc++.h>
using namespace std;
int n,m,a[55][11111],i,j,x,y;
double ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		for(j=1;j<=a[i][0];j++)
			scanf("%d",&a[i][j]);
		sort(a[i]+1,a[i]+a[i][0]+1);
		a[i][0]=unique(a[i]+1,a[i]+a[i][0]+1)-a[i]-1;
	}
	scanf("%d",&m);
	while(m--){
		ans=0,i=j=1;
		scanf("%d %d",&x,&y);
		while(i<=a[x][0]&&j<=a[y][0]){
			if(a[x][i]<a[y][j])
				i++;
			else if(a[x][i]>a[y][j])
				j++;
			else
				ans++,i++,j++;
		}
		printf("%.2lf%%\n",ans/(a[x][0]+a[y][0]-ans)*100);
	}
	return 0;
}