#include <bits/stdc++.h>
using namespace std;
int t;
char s[2048],ans[2048];
map<char,int>op;
map<char,int>bound;
map<string,int>key;
int main(){
	op['=']=op['+']=op['-']=op['*']=op['/']=op['<']=op['>']=op['!']=1;
	bound['{']=bound['}']=bound['(']=bound[')']=bound[',']=bound[';']=1;
	key["main"]=key["if"]=key["else"]=key["for"]=key["while"]=key["int"]=1;
	while(cin>>s)
		for(int i=0;s[i];i++)
			if(isalpha(s[i])||s[i]=='_'){
				t=0;
				while(isalpha(s[i])||isdigit(s[i])||s[i]=='_')
					ans[t++]=s[i++];
				ans[t]=0,i--;
				printf("(%s,%s)\n",key[ans]?"keyword":"identifier",ans);
			}
			else if(isdigit(s[i])){
				t=0;
				while(isdigit(s[i]))
					ans[t++]=s[i++];
				ans[t]=0,i--;
				printf("(integer,%s)\n",ans);
			}
			else if(bound[s[i]])
				printf("(boundary,%c)\n",s[i]);
			else if(op[s[i]]){
				if((s[i]=='<'||s[i]=='>'||s[i]=='='||s[i]=='!')&&s[i+1]=='='){
					printf("(operator,%c%c)\n",s[i],s[i+1]);
					i++;
				}
				else
					printf("(operator,%c)\n",s[i]);
			}
	return 0;
}