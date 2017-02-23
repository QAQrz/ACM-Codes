#include <bits/stdc++.h>
using namespace std;
struct node{
	long long x,y;
}p[100086];
int n,i,j,ans,flag,cnt,u,v;
int check(int a,int b,int c){
	return (p[a].x-p[b].x)*(p[a].y-p[c].y)==(p[a].x-p[c].x)*(p[a].y-p[b].y);
}
int main(){
	while(cin>>n){
		cin>>ans;
		flag=0,ans*=n;
		for(i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		if(n<3)
			flag=1;
		else
			for(i=0;i<1111;i++){
				cnt=0,u=rand()%n;
				for(v=rand()%n;v==u;v=rand()%n);
				for(j=0;j<n;j++)
					if(check(u,v,j))
						cnt++;
				if(cnt*100>=ans){
					flag=1;
					break;
				}
			}
		cout<<(flag?"possible":"impossible")<<endl;
	}
	return 0;
}