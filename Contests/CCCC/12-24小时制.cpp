#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	scanf("%d:%d",&a,&b);
	if(a>11)
		printf("%d:%d PM\n",a>12?a-12:a,b);
	else
		printf("%d:%d AM\n",a,b);
	return 0;
}