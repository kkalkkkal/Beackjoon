/*비트 압축 연산(비트마스킹) 기법을 활용한 효율성 증대*/
#include<stdio.h>
#include<string.h>
int pow2(int x);//2의 거듭제곱을 저장한
void clear(int check[]);//암기하는 글자에 대한 정보
int main(void)
{
    int num,test,i,j,roll,func,tmp;
    int brain=0,answer=0;//
    char word[1010],letter;
    int alphabet[30]={0};
    int check[30]={0};
    int chart[10010]={0};
    for(i=1; i<=26; i++)//알파벳을 2의 거듭제곱수로 정의한다.
    {
        alphabet[i]=pow2(26-i);//a는 2^25,b는 2^24.....z는 2^0
        brain+=alphabet[i];//처음에는 모든 단어를 저장한다.
    }
    scanf("%d %d",&num,&test);
    for(i=1; i<=num; i++)
    {
        clear(check);
        scanf("%s",&word);//단어를 입력받는다
        roll=strlen(word);
        for(j=0; j<roll; j++)
        {
            tmp=word[j]-96;
            if(check[tmp]==0)
            {
                chart[i]+=alphabet[tmp];//있는 글자들을 찾아서 저장한다.
                check[tmp]=1;
            }
        }
    }
    for(i=1; i<=test; i++)
    {
        answer=0;
        scanf("%d %c",&func,&letter);//실행할 함수(쿼리)번호와 인자를 입력한다.
        tmp=letter-96;
        if(tmp==1 || tmp==5 || tmp==9 || tmp==15 || tmp==21)//모음은 절대 잊지 않으므로 입력으로 이런 게 들어오면 무시한다.
        {
            goto skip;
        }
        brain+=(func==1) ? alphabet[tmp]*(-1) : alphabet[tmp];//머리속에서 알파벳을 잊거나 기억해낸다
        skip:
        for(j=1; j<=num; j++)//단어들을 찾아본다
        {
            tmp=brain&chart[j];//현재 기억 상태와 단어들의 정보를 비트 단위로 비교한다.
            answer+=(tmp==chart[j]);//만일 모든 글자를 기억했다면 넣는다.
        }
        printf("%d\n",answer);//각각의 함수마다 정답을 출력한다.
    }
    return 0;
}
int pow2(int x)
{
    int sum=1,i;
    for(i=1; i<=x; i++)
    {
        sum*=2;
    }
    return sum;
}
void clear(int check[])
{
    int i;
    for(i=1; i<=27; i++)
    {
        check[i]=0;
    }
}
