#include <bits/stdc++.h>
using namespace std;
char str[111111],s[222222];
int l,i,j,maxright,rx[222222],p,ans;
int main(){
	while(~scanf("%s",str)){
		s[ans=maxright=p=l=0]='#';
		for(i=0;str[i];i++)
			s[++l]=str[i],s[++l]='#';
		s[++l]=0;
		for(i=0;i<l;i++){
			if(i>=maxright)
				rx[i]=1;
			else
				rx[i]=min(rx[p*2-i]+i-1,maxright)-i+1;
			while(i+rx[i]<l&&i-rx[i]>=0&&s[i+rx[i]]==s[i-rx[i]])
				rx[i]++;
			if(i+rx[i]-1>maxright)
				maxright=i+rx[i]-1,p=i;
			ans=max(ans,rx[i]-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}