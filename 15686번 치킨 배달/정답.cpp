#include<stdio.h>
#include<stdlib.h>
#define INF 1000000
int city[105][105];//도시의 지도
int chouse[15][15];//치킨집의 위치
int dist[15][105];//각 집과 치킨집 사이의 거리. 행이 치킨집의 번호, 열이 민가의 번호이다.
int check[15];//치킨집 선택 여부를 저장한다.
int sum[105];//치킨 거리를 구할 떄 사용한다.
int answer=INF;//최종 정답
int chicken=0,house=0;//민가와 치킨집의 개수
void clear(void)//sum을 초기화한다.
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
void calculate(void)//선택된 치킨집별 '치킨 거리'를 계산한다.
{
    int i,j,k,tmp=0;
    for(i=1; i<=chicken; i++)
    {
        if(check[i]==1)//선택된 치킨집인 경우
        {
            for(j=1; j<=house; j++)//어떤 집과 가장 가까운 치킨집을 찾는다.
            {
                sum[j]=smaller(dist[i][j],sum[j]);
            }
        }
    }
    for(i=1; i<=house; i++)//모든 집의 치킨 거리의 합을 구한다.
    {
        tmp+=sum[i];
    }
    answer=smaller(answer,tmp);//가장 짧은 치킨 거리가 곧 최종 정답이다.
}
void func(int chicken,int target,int x,int y)//전체 치킨집 중 target개만큼을 뽑는다(셈기법-조합)
/*순서를 생각하지 않으므로 번호 순서대로 치킨집을 뽑아야 한다.*/
{
    int i;
    if(x>target)//target만큼 치킨집을 선택하면.
    {
        clear();//새로운 계산을 위해 sum을 초기화한다.
        calculate();//'치킨 거리'를 계산한다.
    }
    else
    {
        for(i=1; i<=chicken; i++)//이번 치킨집을 선택한다.
        {
            if(i>=y && check[i]==0)//이전 치킨집보다 큰 번호인가?
            {
                check[i]=1;//그 치킨집을 선택한다.
                func(chicken,target,x+1,i);//다음 치킨집을 찾는다.
                check[i]=0;//선택한 치킨집을 제거한다.
            }
        }
    }
}
int main(void)
{
    int width,target,info,i,j;
    scanf("%d %d",&width,&target);//도시의 크기와 선택할 치킨집의 개수를 입력받는다.
    for(i=1; i<=width; i++)
    {
        for(j=1; j<=width; j++)
        {
            scanf("%d",&info);//도시의 정보를 입력받는다.
            if(info==1)//민가의 위치를 저장한다.
            {
                house++;
                city[house][1]=i;
                city[house][2]=j;
            }
            else if(info==2)//치킨집의 위치를 저장한다.
            {
                chicken++;
                chouse[chicken][1]=i;
                chouse[chicken][2]=j;
            }
        }
    }
    for(i=1; i<=chicken; i++)//각각의 집과 치킨집 간의 수직-수평 거리를 계산한다.
    {
        for(j=1; j<=house; j++)
        {
            dist[i][j]=abs(chouse[i][1]-city[j][1])+abs(chouse[i][2]-city[j][2]);
        }
    }
    func(chicken,target,1,0);//치킨집을 찾아서 그 거리를 계산한다.
/*함수는 func->calculate 순으로 실행된다.*/
    printf("%d",answer);//최종 정답을 출력한다.
    return 0;
}
