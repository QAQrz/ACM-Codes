#include <bits/stdc++.h>
using namespace std;
char s[15];
int i,j,ans[15],t,a[15];
int cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>s;
	for(i=0;i<11;i++){
		for(j=0;j<t;j++)
			if(a[j]==s[i]-'0')
				break;
		if(j>=t)
			a[t++]=s[i]-'0';
	}
	sort(a,a+t,cmp);
	for(i=0;i<11;i++)
		for(j=0;j<t;j++)
			if(a[j]==s[i]-'0'){
				ans[i]=j;
				break;
			}
	cout<<"int[] arr = new int[]{";
	for(i=0;i<t;i++)
		printf("%d%s",a[i],i<t-1?",":"};\n");
	cout<<"int[] index = new int[]{";
	for(i=0;i<11;i++)
		printf("%d%s",ans[i],i<10?",":"};\n");
	return 0;
}