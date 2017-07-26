#include <bits/stdc++.h>
using namespace std;
int a[128],n,q,w,e,flag;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i&&!flag){
			if(a[i]>a[i-1]){
				if(!w&&!e)
					q=1;
				else
					flag=1;
			}
			else if(a[i]==a[i-1]){
				if(!e)
					w=1;
				else
					flag=1;
			}
			else
				e=1;
		}
	}
	cout<<(flag?"NO":"YES")<<endl;
	return 0;
}