

#include <stdio.h>
int a[10005]={0,1,2,3,5};
void data_init()
{
    int i;
    for(i=3;i<10005;i++)
    {
        a[i]=a[i-1]+a[i-2];
        if(a[i]>=10000) a[i]%=10000;
    }
}
int main()
{
    int n,t;
    data_init();
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d",&t);
                        printf("%04d",a[t]);
        }
        printf("\n");
    }
    return 0;
}
/*矩阵是   |1 1|^2=|1 1|*|1 1|=|2 1|
//         |1 0|   |1 0| |1 0| |1 1|
 
 n的取值：1 2 3 4 5 6 ....
左上角值：1 2 3 5 8 13 ....
 
又是变式的斐波那契！！！！！！！！！！！
*/