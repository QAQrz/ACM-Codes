#include <bits/stdc++.h>
using namespace std;
int n,i,j,cnt,s,a[12][12];
int main(){
	cin>>n;
	while(cnt<n*n){
		if(s==0){
			a[i][j++]=++cnt;
			if(j+1>=n||a[i][j+1])
				s=(s+1)%4;
		}
		else if(s==1){
			a[i++][j]=++cnt;
			if(i+1>=n||a[i+1][j])
				s=(s+1)%4;
		}
		else if(s==2){
			a[i][j--]=++cnt;
			if(!j||a[i][j-1])
				s=(s+1)%4;
		}
		else{
			a[i--][j]=++cnt;
			if(!i||a[i-1][j])
				s=(s+1)%4;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			printf("%3d",a[i][j]);
			if(j>n-2)
				cout<<endl;
		}
	return 0;
}