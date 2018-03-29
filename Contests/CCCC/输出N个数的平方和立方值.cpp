#include <stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    printf("Number\tSquare\tCube\t\n");
    for (i=1; i<=n; i++)
        printf("%d\t%d\t%d\t\n",i,i*i,i*i*i);
    return 0;
}
