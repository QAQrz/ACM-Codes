#include <bits/stdc++.h>
using namespace std;
double E=1000,g=9.8,ans,dis,w,p;
int main(){
	cin>>w>>p;
	while(1){
		dis=E*200/w/g,ans+=dis,E=E*(100-p)*0.01;
		if(dis<1e-7)
			break;
	}
	printf("%.3lf\n",ans);
	return 0;
}