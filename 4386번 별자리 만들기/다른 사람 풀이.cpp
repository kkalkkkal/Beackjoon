#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<double,pair<int,int> > PP;
vector<PP> lines;
double power(double x);
double length(double x1,double y1,double x2,double y2);
int main(void)
{
    int num,i,j,roll;
    int nowi,nowj,target;
    int visit[110]={0};
    double stars[110][110]={0};
    double answer=0,nowlength;
    scanf("%d",&num);
    for(i=1; i<=num; i++)
    {
        visit[i]=i;
        scanf("%lf %lf",&stars[i][1],&stars[i][2]);
    }
    for(i=1; i<num; i++)
    {
        for(j=i+1; j<=num; j++)
        {
            lines.push_back(make_pair(length(stars[i][1],stars[i][2],stars[j][1],stars[j][2]),make_pair(i,j)));
        }
    }
    sort(lines.begin(),lines.end());
    roll=lines.size();
    for(i=0; i<roll; i++)
    {
        nowlength=lines[i].first;
        nowi=lines[i].second.first;
        nowj=lines[i].second.second;
        if(visit[nowi]!=visit[nowj])
        {
            answer+=nowlength;
            target=visit[nowj];
            for(j=1; j<=num; j++)
            {
                if(visit[j]==target)
                {
                    visit[j]=visit[nowi];
                }
            }
        }
    }
    printf("%.2lf",answer);
    return 0;
}
double power(double x)
{
    return x*x;
}
double length(double x1,double y1,double x2,double y2)
{
    return sqrt(power(x2-x1)+power(y2-y1));
}
