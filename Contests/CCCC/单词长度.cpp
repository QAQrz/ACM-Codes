#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int ans=0,flag=0;
    while(scanf("%c",&c))
    {
        if (ans&&(c==' '||c=='.'))
        {
            if (flag)
                printf(" %d",ans);
            else
                printf("%d",ans);
            ans=0;
            flag=1;
        }
        else if (c!=' '&&c!='.')
            ans++;
        if (c=='.')
            break;
    }
    return 0;
}
