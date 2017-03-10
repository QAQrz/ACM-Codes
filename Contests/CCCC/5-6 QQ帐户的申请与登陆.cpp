#include <bits/stdc++.h>
using namespace std;
map<long long,string>m;
string str;
char s[5];
long long a,n;
int main() {
    scanf("%lld",&n);
    while(n--){
        scanf("%s %lld",s,&a);
        cin>>str;
        if(s[0]=='N')
            if(!m[a].length()){
                printf("New: OK\n");
                m[a]=str;
            }
            else
                printf("ERROR: Exist\n");
        else{
            if(!m[a].length())
                printf("ERROR: Not Exist\n");
            else if(m[a].compare(str))
                printf("ERROR: Wrong PW\n");
            else
                printf("Login: OK\n");
        }
    }
    return 0;
}