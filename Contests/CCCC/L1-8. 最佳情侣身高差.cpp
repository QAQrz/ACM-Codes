#include <bits/stdc++.h>
using namespace std;
char s[2];
int n;
double a;
int main(){
	cin>>n;
	while(n--){
		cin>>s>>a;
		printf("%.2lf\n",s[0]=='F'?a*1.09:a/1.09);
	}
	return 0;
}