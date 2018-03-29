#include <bits/stdc++.h>
using namespace std;
char s[10086],str[]={"GPLT"};
int i,num[4];
int main(){
	cin>>s;
	for(i=0;s[i];i++)
		if(s[i]=='G'||s[i]=='g')
			num[0]++;
		else if(s[i]=='P'||s[i]=='p')
			num[1]++;
		else if(s[i]=='L'||s[i]=='l')
			num[2]++;
		else if(s[i]=='T'||s[i]=='t')
			num[3]++;
		while(num[0]+num[1]+num[2]+num[3])
			for(i=0;i<4;i++)
				if(num[i]){
					cout<<str[i];
					num[i]--;
				}
		cout<<endl;
	return 0;
}