#include <bits/stdc++.h>
using namespace std;
char sa[1024],sb[1024];
int numa[15],numb[15],n,i,j,ans1,ans2,tempa[15],tempb[15],m;
int main(){
	cin>>n>>sa>>sb;
	for(i=0;i<n;i++)
		numa[sb[i]-'0']++,numb[sa[i]-'0']++;
	memcpy(tempa,numa,sizeof numa);
	memcpy(tempb,numb,sizeof numb);
	for(i=9;i>=0;i--)
		for(j=i;tempa[i]&&j>=0;j--)
			m=min(tempa[i],tempb[j]),tempa[i]-=m,tempb[j]-=m;
	for(i=0;i<10;i++)
		ans1+=tempa[i];
	for(i=9;i>=0;i--)
		for(j=i-1;numa[i]&&j>=0;j--)
			m=min(numa[i],numb[j]),numa[i]-=m,numb[j]-=m,ans2+=m;
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}