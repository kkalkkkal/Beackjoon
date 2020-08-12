#include<stdio.h>
int check(int house[][20],int nowi,int nowj,int status);
void move(int house[][20],int nowi,int nowj,int gi,int gj,int status);
int answer=0;
int main(void)
{
    int width,i,j;
    int house[20][20]={0};
    scanf("%d",&width);//집의 크기를 입력받는다.
    for(i=1; i<=width; i++)
    {
        for(j=1; j<=width; j++)
        {
            scanf("%d",&house[i][j]);//집의 정보를 입력받는다.
        }
    }
    move(house,1,2,width,width,1);//파이프를 옮긴다.
    printf("%d",answer);
}
int check(int house[][20],int nowi,int nowj,int status)//올바른 위치에 놓여있는지 확인한다.
{//방향별로 지정된 칸이 비어있는지 확인한다.
    if(status==1)
    {
        if(house[nowi][nowj]==0)
        {
            return 1;
        }
    }
    else if(status==2)
    {
        if(house[nowi][nowj]==0 && house[nowi][nowj-1]==0 && house[nowi-1][nowj]==0)
        {
            return 1;
        }
    }
    else if(status==3)
    {
        if(house[nowi][nowj]==0)
        {
            return 1;
        }
    }
    return 0;
}
void move(int house[][20],int nowi,int nowj,int gi,int gj,int status)
{
    if(house[gi][gj]==0 && check(house,nowi,nowj,status)==1 && nowi==gi && nowj==gj)
    {
        answer++;//목적지까지 무사히 옮길 경우, 답을 추가한다.
    }
    else if(nowi<=gi && nowj<=gj && check(house,nowi,nowj,status)==1)//만일 옮길 수 있는 위치로 파이프가 이동한 경우
    {//이동 가능한 모든 경우를 다 옮긴다.
        if(status==1)//가로 방향
        {
            move(house,nowi,nowj+1,gi,gj,1);
            move(house,nowi+1,nowj+1,gi,gj,2);
        }
        else if(status==2)//대각선 방향
        {
            move(house,nowi,nowj+1,gi,gj,1);
            move(house,nowi+1,nowj+1,gi,gj,2);
            move(house,nowi+1,nowj,gi,gj,3);
        }
        else if(status==3)//세로 방향
        {
            move(house,nowi+1,nowj+1,gi,gj,2);
            move(house,nowi+1,nowj,gi,gj,3);
        }
    }
}
