#include <bits/stdc++.h>
using namespace std;
int n,l,nt[1123456],flag,m,l1;
char s[11234567],t[1123456];
int main(){
	scanf("%d %s",&n,t);
	l1=strlen(t),m=2;
	for(int i=0;i<l1;i++)
		m=max(m,isalpha(t[i])?t[i]-'A'+11:t[i]-'0'+1);
	for(int i=0;i<l1/2;i++)
		swap(t[i],t[l1-i-1]);
	int i,j;
	j=nt[i=0]=-1;
	while(i<l1){
		while(~j&&t[i]!=t[j])
			j=nt[j];
		nt[++i]=++j;
	}
	for(;m<17&&!flag;m++){
		l=0;
		for(int i=n;i;i--){
			int k=i;
			while(k){
				if(k%m>9)
					s[l++]=k%m-10+'A';
				else
					s[l++]=k%m+'0';
				k/=m;
			}
		}
		int i=0,j=0;
		while(i<l){
			while(~j&&s[i]!=t[j])
				j=nt[j];
			i++,j++;
			if(j>=l1){
				flag=1;
				break;
			}
		}
	}
	printf("%s\n",flag?"yes":"no");
	return 0;
}