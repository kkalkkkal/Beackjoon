#include<stdio.h>
#include<queue>
#include<algorithm>
#include<utility>
#define INF 1000000000
using namespace std;
typedef pair<int,int> PP;
typedef pair<pair<int,int>,pair<int,int> > MM;
queue<PP> Q;
int chart[22][22];
int complete[410];
void clear(int chart[][22],int sx,int sy);
int range(int x,int y,int width);
int drive(int city[][22],MM data[],int width,int mission,int sx,int sy,int fuel);
void search(int city[][22],int chart[][22],int width,int sx,int sy);
int find_near(MM data[],int chart[][22],int mission,int *length);
int main(void)
{
    int width,mission,start,i,j,sx,sy,answer;
    int a,b,c,d;
    int city[22][22]={0};
    MM data[410];
    scanf("%d %d %d",&width,&mission,&start);
    for(i=1; i<=width; i++)
    {
        for(j=1; j<=width; j++)
        {
            scanf("%d",&city[i][j]);
        }
    }
    scanf("%d %d",&sx,&sy);
    for(i=1; i<=mission; i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        data[i]=make_pair(make_pair(a,b),make_pair(c,d));
    }
    sort(data+1,data+mission+1);
    answer=drive(city,data,width,mission,sx,sy,start);
    printf("%d",answer);
    return 0;
}
void clear(int chart[][22],int sx,int sy)
{
    int i,j;
    for(i=1; i<=21; i++)
    {
        for(j=1; j<=21; j++)
        {
            chart[i][j]=INF;
        }
    }
    chart[sx][sy]=0;
}
int range(int x,int y,int width)
{
    if(x>=1 && x<=width)
    {
        if(y>=1 && y<=width)
        {
            return 1;
        }
    }
    return 0;
}
int drive(int city[][22],MM data[],int width,int mission,int sx,int sy,int fuel)
{
    int k,sum,target,length1,length2;
    int fail=0;
    int tx,ty,gx,gy;
    for(k=1; k<=mission; k++)
    {
        sum=0;
        length1=length2=INF;
        clear(chart,sx,sy);
        search(city,chart,width,sx,sy);
        target=find_near(data,chart,mission,&length1);
        if(target==-1)
        {
            fail=1;
            break;
        }
        tx=data[target].first.first;
        ty=data[target].first.second;
        gx=data[target].second.first;
        gy=data[target].second.second;
        clear(chart,tx,ty);
        search(city,chart,width,tx,ty);
        length2=chart[gx][gy];
        if(length1+length2>fuel)
        {
            fail=1;
            break;
        }
        else
        {
            complete[target]=1;
            fuel-=(length1+length2);
            fuel+=(length2*2);
            sx=gx;
            sy=gy;
        }
    }
    if(fail==1)
    {
        return -1;
    }
    else
    {
        return fuel;
    }
}
void search(int city[][22],int chart[][22],int width,int sx,int sy)
{
    int imove[4]={-1,0,1,0};
    int jmove[4]={0,1,0,-1};
    int ii,jj,ti,tj,i,length;
    Q.push(make_pair(sx,sy));
    while(!Q.empty())
    {
        ii=Q.front().first;
        jj=Q.front().second;
        Q.pop();
        for(i=0; i<=3; i++)
        {
            ti=ii+imove[i];
            tj=jj+jmove[i];
            if(range(ti,tj,width)==1 && city[ti][tj]==0 && chart[ti][tj]>chart[ii][jj]+1)
            {
                Q.push(make_pair(ti,tj));
                chart[ti][tj]=chart[ii][jj]+1;
            }
        }
    }
}
int find_near(MM data[],int chart[][22],int mission,int *length)
{
    int answer=-1;
    int ax=INF,ay=INF,i,gx,gy;
    for(i=1; i<=mission; i++)
    {
        gx=data[i].first.first;
        gy=data[i].first.second;
        if(complete[i]==0 && chart[gx][gy]<*length)
        {
            answer=i;
            *length=chart[gx][gy];
        }
    }
    return answer;
}
