#include<stdio.h>
#include<string.h>
int main(void)
{
    char sound[200]={0};//소리를 저장하는 배열
    int num=0,i,roll,yes=1,count;
    scanf("%s",&sound);//소리를 입력받는다.
    roll=strlen(sound);//소리의 길이를 잰다.
    while(num<roll && yes==1)
    {
        count=0;//조사한 거리. 처음에는 0으로 초기화한다.
        if(sound[num]=='0')//0으로 시작할 때
        {
            if(sound[num+1]!='1')//01이 아닌경우
            {
                yes=0;//잠수함 아님
                break;
            }
            count=2;//2칸 조사
        }
        else if(sound[num]=='1')//1로 시작할 때
        {
            if(sound[num+1]!='0' || sound[num+2]!='0')//우선 100으로 시작하는지 확인
            {
                yes=0;//아니면 잠수함 아님
                break;
            }
            count+=3;//3칸 조사
            while(sound[num+count]=='0')//이후로는 0이 이어지므로, 1을 찾는다.
            {
                count++;
                if(sound[num+count]==0)//1이 끝까지 안나오는 경우(예: 10000)
                {
                    yes=0;//잠수함 아님
                    break;
                }
            }
            if(sound[num+count+1]=='0' && sound[num+count+2]=='0')//1이 나온 직후, 그 바로 뒤가 00이면 100도 01도 만들 수 없다ㅔ.
            {
                yes=0;//잠수함 아님
                break;
            }
            while(sound[num+count]=='1')//1이 계속 반복된다.
            {
                if(sound[num+count+1]=='0' && sound[num+count+2]=='0')//다음 100을 찾을 경우(01은 상관없음)
                {
                    break;
                }
                count++;
            }
        }
        num+=count;//조사한 칸 수만큼 더해준다.
    }//모든 칸을 다 조사해서 이상이 없으면 그것이 잠수함이다.
    yes==1 ? printf("SUBMARINE") : printf("NOISE");//최종 정답을 출력한다.
    return 0;
}
