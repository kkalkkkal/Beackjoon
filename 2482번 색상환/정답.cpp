#include<stdio.h>
#define DIV 1000000003
long long line[1010][510];
long long answer[1010][510];
int main(void)
{
    int num,pick,i,j,roll;
    scanf("%d %d",&num,&pick);
    line[2][1]=2;
    line[3][1]=3;
    line[3][2]=1;
    for(i=4; i<=num; i++)
    {
        line[i][1]=i;
        for(j=2; j<=503; j++)
        {
            line[i][j]=(line[i-2][j-1]+line[i-1][j])%DIV;
        }
    }
    answer[2][1]=2;
    answer[3][1]=3;
    answer[4][1]=4;
    answer[4][2]=2;
    for(i=5; i<=num; i++)
    {
        roll=i/2;
        answer[i][1]=i;
        for(j=2; j<=roll; j++)
        {
            answer[i][j]=(line[i-3][j-1]+line[i-1][j])%DIV;
        }
    }
    printf("%lld",answer[num][pick]);
    return 0;
}
