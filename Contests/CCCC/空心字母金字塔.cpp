#include <bits/stdc++.h>
using namespace std;
char x;
int main(){
	cin>>x;
	for(int i=0;i<=x-'A';i++){
		for(int j=0;j<39-i;j++)
			cout<<" ";
		printf("%c",'A'+i);
		for(int j=0;j<max(0,(i-1)*2+1);j++)
			printf("%c",i==x-'A'?'A'+i:' ');
		if(i)
			printf("%c\n",'A'+i);
		else
			cout<<endl;
	}
	return 0;
}