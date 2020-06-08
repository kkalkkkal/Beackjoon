 #include <iostream>
 #include <algorithm>
#include <queue>

#define MAX_SUBIN 100002
#define MAX_BRO 100000

using namespace std;


int main(void)
{
    int N, K;
    queue<int> q;
    int line[MAX_SUBIN] = { 0, }; // 방문 확인
    int ans = 0;
    int count = 0;
    int seg = 1 , i =0; // seg는 while문이 도는 순간의 큐 크기 저장 변수.
    int check = 0;

    cin >> N >> K; // 수빈, 동생 입력

    line[N] = 1; //시작점
    

    q.push(N);


    int T;

    while (!q.empty()) // 큐가 빌때까지 
    {
        count = 0;
        check = 0;
        for (i = 0; i < seg; i++) // 시작 큐 개수 만큼
        {
            T = q.front();
            q.pop();

            if (T == K)
            {
                cout << ans << endl;
                return 0;
            }


            if (line[T + 1] == 0 && T + 1 <= MAX_BRO) // X+1 노드 탐색
            {
                q.push(T + 1);
                line[T + 1] = 1;
                count++;
                check = 1;
            }

            if (line[T - 1] == 0 && T - 1 >= 0) // X-1 노드 탐색
            {
                q.push(T - 1);
                line[T - 1] = 1;
                count++;
                check = 1;
            }

            if (T * 2 <= MAX_BRO) // X * 2 노드 탐색
            {
                if (line[T * 2] == 0)
                {
                    q.push(T * 2);
                    line[T * 2] = 1;
                    count++;
                    check = 1;
                }
            }

        }
        seg = count;
        if (check) // 만일 조건에 맞아 방문을 적어도 한번 했을 경우
        {
            ans++;
        }


        
        

    }

   

    
    

	
}
