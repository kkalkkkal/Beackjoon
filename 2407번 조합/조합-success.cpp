#include<stdio.h>
void mul(int answer[],int num,int *digit);//큰 수 곱하기
void div(int answer[],int num,int *digit);//큰 수 나누기
int main(void)
{
    int num,pick,digit=1,i;//digit=답의 자릿수
    int answer[200]={0};//답을 저장할 배열. 일의 자리부터 1번 인덱스에 저장한다.(수를 거꾸로 저장한다)
    scanf("%d %d",&num,&pick);//전체 대상 수와 뽑을 대상 수를 입력받는다.
    answer[1]=1;//곱의 초기값은 1
    //조합의 정의에 따라 곱하고 나눈다.
    mul(answer,num,&digit);//n!
    div(answer,num-pick,&digit);//(n-r)!
    div(answer,pick,&digit);//r!
    for(i=digit; i>=1; i--)//높은 자리부터 순차적으로 출력한다.
    {
        printf("%d",answer[i]);
    }
    return 0;
}
void mul(int answer[],int num,int *digit)
{
    int i,j;
    for(i=1; i<=num; i++)
    {
        for(j=1; j<=*digit; j++)//모든 자릿수에 곱하는 수를 곱한다.
        {
            answer[j]*=i;
        }
        for(j=1; j<=*digit; j++)//일의자리부터 검사한다.
        {
            if(answer[j]>=10)//값이 10 이상이 되는 경우가 있으면
            {
                answer[j+1]+=(answer[j]/10);//다음 자리로 넘치는 만큼 넘겨준다.
                answer[j]%=10;//일의자리만 남긴다.
                if(j==(*digit))//만일 최고 자리수를 넘겼을 경우
                {
                    *digit+=1;//자릿수를 하나 더 늘린다.
                }
            }
        }
    }
}
void div(int answer[],int num,int *digit)
{
    int i,j,blank=1;
    for(i=1; i<=num; i++)
    {
        blank=1;//처음으로 0이 아닌 값이 나올 떄까지 반복한다.
        for(j=*digit; j>=1; j--)
        {
            answer[j-1]+=(answer[j]%i)*10;//나눗셈의 나머지는 밑의 자리로 넘겨준다.
            answer[j]/=i;//나눗셈의 몫을 구힌다.
            if(answer[j]==0 && blank==1)//만일 몫이 0이면 자릿수를 빼준다. 처음으로 0이 아닌 값이 나올 때까지 반복한다.
            {
                *digit-=1;
            }
            else//0이 아닌 값이 나올 경우.
            {
                blank=0;
            }
        }
    }
}
