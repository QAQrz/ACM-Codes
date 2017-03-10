#include <bits/stdc++.h>
using namespace std;
char s[33];
int a[4],i,ans,t;
int main() {
    cin>>s;
    for(i=0;i<32;i++){
        ans=ans*2+s[i]-'0';
        if(i%8==7)
            a[t++]=ans,ans=0;
    }
    for(i=0;i<4;i++)
        printf("%d%c",a[i],i<3?'.':'\n');
    return 0;
}