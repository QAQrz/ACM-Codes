#include <bits/stdc++.h>
using namespace std;
int t,i,j,l,a[128],vis[128];
char s[1000086];
int main() {
    while(gets(s)&&strcmp(s,".")){
        l=strlen(s);
        for(i=0;i<l;i++){
            if(s[i]=='(')
                a[t++]=2;
            else if(s[i]==')'){
                if(t&&a[t-1]==2)
                    t--;
                else
                    a[t++]=6;
            }
            if(s[i]=='[')
                a[t++]=3;
            else if(s[i]==']'){
                if(t&&a[t-1]==3)
                    t--;
                else
                    a[t++]=7;
            }
            if(s[i]=='{')
                a[t++]=4;
            else if(s[i]=='}'){
                if(t&&a[t-1]==4)
                    t--;
                else
                    a[t++]=8;
            }
            if(i<l-1&&s[i]=='/'&&s[i+1]=='*')
                a[t++]=1,i++;
            else if(i<l-1&&s[i]=='*'&&s[i+1]=='/'){
                i++;
                if(t&&a[t-1]==1)
                    t--;
                else
                    a[t++]=5;
            }
        }
    }
    if(t){
        for(i=1;i<t-1;i++)
            if(a[i-1]==a[i+1]-4)
                break;
        if(i>=t)
            i=0;
        printf("NO\n");
        if(a[i]==1)
            printf("/*-?\n");
        else if(a[i]==2)
            printf("(-?\n");
        else if(a[i]==3)
            printf("[-?\n");
        else if(a[i]==4)
            printf("{-?\n");
        else if(a[i]==5)
            printf("?-*/\n");
        else if(a[i]==6)
            printf("?-)\n");
        else if(a[i]==7)
            printf("?-]\n");
        else
            printf("?-}\n");
    }
    else
        printf("YES\n");
    return 0;
}