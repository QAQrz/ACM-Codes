#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	a=a/100*60+a%100+b;
	printf("%d%02d\n",a/60,a%60);
	return 0;
}