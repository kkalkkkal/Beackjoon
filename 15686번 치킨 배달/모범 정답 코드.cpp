#include<stdio.h>
#include<stdlib.h>
#define INF 1000000
int city[105][105];//도시의 좌표
int chouse[15][15];//치킨집의 좌표
int dist[15][105];//도시와 치킨집간 거리
int choose[15];//치킨집 선택
int sum[105];//집과 치킨 거리
int answer=INF;
int chicken=0,house=0;
void clear(void);//계산당 초기화
int smaller(int x,int y);//더 작은 값 찾기
void calculate(int target);//치킨 거리 계산
void func(int chicken,int target,int pick);//치킨집 선택
int main(void)
{
    int width,target,info,i,j;
    scanf("%d %d",&width,&target);//도시의 크기와 선택할 치킨집의 수를 입력받는다.
    for(i=1; i<=width; i++)
    {
        for(j=1; j<=width; j++)
        {
            scanf("%d",&info);//도시의 정보를 입력받는다.
            if(info==1)//민가
            {
                house++;
                city[house][1]=i;
                city[house][2]=j;
            }
            else if(info==2)//치킨집
            {
                chicken++;
                chouse[chicken][1]=i;
                chouse[chicken][2]=j;
            }
        }
    }
    for(i=1; i<=chicken; i++)
    {
        for(j=1; j<=house; j++)
        {//집과 각 치킨집까지의 거리를 잰다.
            dist[i][j]=abs(chouse[i][1]-city[j][1])+abs(chouse[i][2]-city[j][2]);
        }
    }
    func(chicken,target,1);//치킨집을 선택한다.
    printf("%d",answer);//최종 정답을 출력한다.
    return 0;
}
void clear(void)
{
    int i;
    for(i=1; i<=102; i++)
    {
        sum[i]=INF;
    }
}
int smaller(int x,int y)
{
    if(x>=y)
    {
        return y;
    }
    return x;
}
void calculate(int target)
{
    int i,j,k,tmp=0;
    for(i=1; i<=target; i++)
    {
        for(j=1; j<=house; j++)//치킨집별 치킨거리의 최솟값을 구한다.
        {
            sum[j]=smaller(dist[choose[i]][j],sum[j]);
        }
    }
    for(i=1; i<=house; i++)
    {
        tmp+=sum[i];//치킨 거리를 합한다.
    }
    answer=smaller(answer,tmp);//최솟값을 찾는다.
}
void func(int chicken,int target,int pick)
{
    int i;
    if(pick>target)//치킨집을 모두 골랐으면
    {
        clear();
        calculate(target);//치킨 거리를 계산한다.
    }
    else
    {
        for(i=1; i<=chicken; i++)//치킨집을 중복이 되지 않게 고른다.
        {
            if(choose[pick-1]<i)
            {
                choose[pick]=i;
                func(chicken,target,pick+1);//다음 치킨집을 찾는다.
                choose[pick]=0;
            }
        }
    }
}
