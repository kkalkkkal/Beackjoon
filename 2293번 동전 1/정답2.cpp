#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void)
{
    int num,target,i,j;
    int coins[110]={0};
    int chart[10010]={0};
    chart[0]=1;
    scanf("%d %d",&num,&target);
    for(i=1; i<=num; i++)
    {
        scanf("%d",&coins[i]);
    }
    sort(coins+1,coins+num+1);
    for(i=1; i<=num; i++)
    {
        for(j=coins[i]; j<=target; j++)
        {
            chart[j]=chart[j]+chart[j-coins[i]];
        }
    }
    printf("%d",chart[target]);
    return 0;
}
