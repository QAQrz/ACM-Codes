#include <bits/stdc++.h>
using namespace std;
struct windows{
	long long lt,num;
}win[12];
struct node{
	long long t,p;
}per[1024];
long long n,i,j,ans,k,mint,x,a;
double sum;
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>per[i].t>>per[i].p;
		per[i].p=min(per[i].p,60LL);
	}
	cin>>k;
	for(i=0;i<n;i++){
		mint=0x3f3f3f3f;
		for(j=0;j<k;j++){
			if(win[j].lt<per[i].t){
				ans=j;
				break;
			}
			if(mint>win[j].lt)
				mint=win[j].lt,ans=j;
		}
		a=max(a,max(0LL,win[ans].lt-per[i].t)),sum+=max(0LL,win[ans].lt-per[i].t),win[ans].num++,win[ans].lt=max(win[ans].lt,per[i].t)+per[i].p,x=max(x,win[ans].lt);
	}
	sum/=n;
	printf("%.1f ",sum);
	cout<<a<<" "<<x<<endl;
	for(i=0; i<k; i++)
		printf("%lld%c",win[i].num,i<k-1?' ':'\n');
	return 0;
}