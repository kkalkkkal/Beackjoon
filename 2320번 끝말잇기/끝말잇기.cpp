#include<stdio.h>
#include<string.h>
int answer=0;
int check[20];
int used[20];
int base[8];//앞과 뒤가 같은 단어들의 길이의 합을 모아놓은 배열. 여기서는 '코어 조각'이라고 하겠다.
int usedbase[8];//앞과 뒤가 같은 단어들 묶음을 사용했는 지에 대한 여부.
int change(char x);//알파벳을 숫자로 바꿔주는 함수
void solve(int num,int piece[][4],int length[],int placed,int now,int start);//한 조각씩 붙여보는 함수
int main(void)
{
    int num,i,j,cal=0,tmp;
    int piece[20][4];//단어 조각의 앞 글자와 뒷 글자만 저장한다.
    int length[20]={0};//각 단어 조각의 길이
    char word[110]={0};//단어를 입력하는 곳
    scanf("%d",&num);//단어 조각의 개수를 입력받는다.
    for(i=1; i<=num; i++)
    {
        scanf("%s",&word);//단어를 입력받는다.
        tmp=strlen(word);//단어의 길이를 구한다.
        length[i]=tmp;
        if(word[0]!=word[tmp-1])//앞과 뒤가 같은 단어들은 어떻게 붙여도 무방하므로, 얘네들은 따로 빼준다.
        {//앞과 뒤가 다른 단어들만 표에 모은다.
            cal++;
            piece[cal][1]=change(word[0]);
            piece[cal][2]=change(word[tmp-1]);
            length[cal]=tmp;
        }
        else//앞과 뒤가 같으면 그들은 따로 모아서 길이를 합친다.
        {
            base[change(word[0])]+=tmp;
        }
    }
    for(i=0; i<=5; i++)//앞에 아무것도 안 넣는 경우,A-A,E-E,..,U-U인 순으로 조사한다.
    {
        piece[0][2]=i;
        for(j=0; j<=6; j++)
        {
            usedbase[j]=0;
        }
        usedbase[i]=1;//코어 조각을 맨 앞에 두었을 경우 그 조각은 사용했다고 표시해준다.
        solve(cal,piece,length,1,0,i);//이제 조각들을 하나씩 붙여본다.
    }
    printf("%d",answer);
    return 0;
}
int change(char x)//AEIOU를 숫자로 바꾸어준다.
{
    switch(x)
    {
        case 'A':
            return 1;
        case 'E':
            return 2;
        case 'I':
            return 3;
        case 'O':
            return 4;
        case 'U':
            return 5;
    }
}
void solve(int num,int piece[][4],int length[],int placed,int now,int start)//조건에 맞추어 하나씩 붙인다.
{
    int i,sum,tmp;
    sum=(placed==1) ? base[start] : now;//처음 시작한다면 '코어 조각'을 설치하고, 아니면 이전까지 길이의 합을 sum으로 정한다.
    tmp=placed-1;
    if((start==0 || (placed!=1 && base[piece[used[tmp]][2]]!=start)) && usedbase[piece[used[tmp]][2]]==0)//코어 조각들을 중복되지 않도록 만들어진 배열에다 붙인다.
    {
        sum+=base[piece[used[tmp]][2]];
        usedbase[piece[used[tmp]][2]]=1;
    }
    if(answer<sum)
    {
        answer=sum;
    }
    for(i=1; i<=num; i++)
    {
        if(check[i]==0 && ((start==0 && placed==1) || piece[used[placed-1]][2]==piece[i][1]))//첫 조각을 배치하거나, 앞에 이미 다른 조각이 있고 이어서 붙일 수 있는 경우
        {
            check[i]=1;
            used[placed]=i;
            sum+=length[i];
            solve(num,piece,length,placed+1,sum,start);
            check[i]=0;
            used[placed]=0;
            sum-=length[i];
        }
    }
}
/*코어 조각끼리는 어디에 어떻게 붙여도 결과가 똑같으므로, 이들을 따로 뺴두고 앞/뒤가 다른 조각들만 이용하여 재귀함수를 돌린다.*/
