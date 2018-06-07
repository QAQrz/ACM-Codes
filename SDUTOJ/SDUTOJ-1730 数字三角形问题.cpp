#include <stdio.h>
int main(){
    int d[101][101],a[101][101],n,i,j;
    scanf("%d",&n);
    for (i=1; i<=n; i++)
        for (j=1; j<=i; j++)
            scanf("%d",&d[i][j]);
    for (j=1; j<=n; j++)
        a[n][j]=d[n][j];
    for (i=n; i>1; i--)
        for (j=1; j<i; j++)
            if (a[i][j]>a[i][j+1])
                a[i-1][j]=a[i][j]+d[i-1][j];
            else
                a[i-1][j]=a[i][j+1]+d[i-1][j];
    printf("%d",a[1][1]);
    return 0;
}