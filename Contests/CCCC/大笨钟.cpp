#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	scanf("%d:%d",&a,&b);
	if(a>12||(a==12&&b>0)){
		if(b)
			a++;
		a-=12;
		while(a--)
			cout<<"Dang";
		cout<<endl;
	}
	else
		printf("Only %02d:%02d.  Too early to Dang.\n",a,b);
	return 0;
}