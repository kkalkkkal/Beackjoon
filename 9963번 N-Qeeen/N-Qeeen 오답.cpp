 #include <iostream>
 #include <algorithm>
#include <stack>

#define MAX_N 15 // 범위 : 1~14


using namespace std;

/*

퀸끼리 못 공격하는 위치는 나이트가 이동하는 간격과 같다.
방향은 총 8가지.
*/

int main(void)
{
    
    int N; 
    int chess[MAX_N][MAX_N]; // 체스판
    
    int ans = 0;

    // (2,1) : --_ , (2,-1) : --^, (-2,1) : _--, (-2,-1) : ^--
    // (1,2) : -↓ , (1, -2) : -↑, (-1, 2) : ↓-, (-1,-2) : ↑-
    int dx[8] = {2, 2, -2, -2, 1,  1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2,  2, -2};

    stack <pair<int, int>> s; // (x,y) 스택
    int x = 1, y=1;

    cin >> N;

    

    for (int test = 1; test <= N; test++) //  열을 기준으로 N회시행
    {

        for (int i = 1; i <= N; i++) // 외곽 초기화
        {
            for (int j = 1; j <= N; j++)
            {
                chess[i][j] = 0;
            }

        }

        s.push(make_pair(1, test));

        x = s.top().first;
        y = s.top().second;

        //그리고 시작점을 기준으로 8방향 모두 놓을 수 없게 만든다.

        int btw = abs(x - y);
        int k = N - btw;
        for (int j = btw; j <= N; j++) // ↘
        {
            chess[j][btw + j] = 1;
        }

        for (int j = N; j >= 1; j--, k++) // ↗
        {
            chess[j][k] = 1;
        }

        for (int j = 1; j <= N; j++) // ㅡ
        {
            chess[j][y] = 1;
        }

        for (int j = 1; j <= N; j++) // ㅣ
        {
            chess[x][j] = 1;
        }


        while (!s.empty()) // 전수 조사
        {
            x = s.top().first;
            y = s.top().second;
            s.pop();

            ans++;

            for (int i = 0; i < 8; i++) // 퀸이 놓을 수 있는 8가지 방향 확인
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                //체스판을 벗어나지 않고
                if (1 <= nx && nx <= N && 1 <= ny && ny <= N)
                {
                    //아직 퀸을 놓을 수 있는 자리면 
                    if (chess[nx][ny] == 0)
                    {
                        //퀸을 놓는다.
                        chess[nx][ny] = 1;
                        

                        //그리고 놓은 자리를 기준으로 8방향 모두 놓을 수 없게 만든다.

                        int btw = abs(nx - ny);
                        int k = N - btw;
                        for (int j = btw; j <= N; j++) // ↘
                        {
                            chess[j][btw + j] = 1;
                        }

                        for (int j = N; j >= 1; j--, k++) // ↗
                        {
                            chess[j][k] = 1;
                        }

                        for (int j = 1; j <= N; j++) // ㅡ
                        {
                            chess[j][ny] = 1;
                        }

                        for (int j = 1; j <= N; j++) // ㅣ
                        {
                            chess[nx][j] = 1;
                        }

                           

                        s.push(make_pair(x, y));
                        s.push(make_pair(nx, ny));

                    }
                }

            }
               
             

        }
        
    }
    
    
    cout << ans << endl;

    return 0;
	
}
