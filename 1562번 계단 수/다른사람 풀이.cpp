#include<stdio.h>
#define DIV 1000000000
int num_bit[10]={1,2,4,8,16,32,64,128,256,512};
long long answer[110][12][1030];
int main(void)
{
    int k,i,j,target,tmp;
    long long sum=0;
    for(i=1; i<=9; i++)
    {
        answer[1][i][num_bit[i]]=1;
    }
    for(k=2; k<=101; k++)
    {
        for(i=0; i<=9; i++)
        {
            for(j=1; j<=1023; j++)
            {
                tmp=j&num_bit[i];
                if(tmp==num_bit[i])
                {
                    if(i==0)
                    {
                        answer[k][i][j]+=(answer[k-1][i+1][j]+answer[k-1][i+1][j-num_bit[i]]);
                        answer[k][i][j]%=DIV;
                    }
                    else
                    {
                        answer[k][i][j]+=(answer[k-1][i+1][j]+answer[k-1][i+1][j-num_bit[i]]);
                        answer[k][i][j]+=(answer[k-1][i-1][j]+answer[k-1][i-1][j-num_bit[i]]);
                        answer[k][i][j]%=DIV;
                    }
                }
            }
        }
    }
    scanf("%d",&target);
    for(i=0; i<=9; i++)
    {
        sum+=answer[target][i][1023];
        sum%=DIV;
    }
    printf("%lld",sum);
    return 0;
}
