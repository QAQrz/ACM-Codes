#include <bits/stdc++.h>
using namespace std;
char s[22],str[22],num[22];
int t,l,i,flag,f=1,top;
int level(char c){
	if(c=='+'||c=='-')
		return 0;
	else if(c=='(')
		return -1;
	else
		return 1;
}
int main(){
	cin>>str;
	l=strlen(str);
	for(i=0;i<l;i++){
		if(isdigit(str[i])||str[i]=='.')
			num[top++]=str[i];
		else{
			if(top){
				if(flag)
					printf(" ");
				else
					flag=1;
				num[top]=0;
				printf("%s",num);
				top=0;
			}
			if((str[i]=='-'||str[i]=='+')&&((!i)||(i&&str[i-1]=='('))){
				if(str[i]=='-')
					num[top++]=str[i];
				continue;
			}
			if(str[i]==')'){
				while(s[t-1]!='('){
					if(flag)
						printf(" ");
					else
						flag=1;
					printf("%c",s[--t]);
				}
				t--;
			}
			else if(str[i]=='(')
				s[t++]='(';
			else{
				while(t&&level(str[i])<=level(s[t-1])){
					if(flag)
						printf(" ");
					else
						flag=1;
					printf("%c",s[--t]);
				}
				s[t++]=str[i];
			}
		}
	}
	if(top){
		if(flag)
			printf(" ");
		else
			flag=1;
		num[top]=0;
		printf("%s",num);
	}
	while(t){
		if(flag)
			printf(" ");
		else
			flag=1;
		printf("%c",s[--t]);
	}
	printf("\n");
	return 0;
}