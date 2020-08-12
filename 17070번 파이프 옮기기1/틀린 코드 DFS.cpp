#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>


int pipe[17][17] = { 0, };
int dp[3][17][17] = { 0, };

int dx[] = { 1, 0 ,1 };
int dy[] = { 0 ,1 ,1 };
int N;


int DFS(int x, int y, int dir)
{
    if (dp[dir][y][x]) { // 벽이 있는지 확인
        return dp[dir][y][x]; // 벽이 있으면 반환
    }

    int nx = 0, ny = 0; // 미리 이동해볼 좌표

    if (dir == 2) // 대각선 상태일때
    {
        for (int i = 0; i < 3; i++) // 갈 수 있나 검사하기
        {
            // nx,ny 는 파이프의 오른쪽 끝의 좌표를 기준으로 한다.
            // (1,1), (1,2) 이렇게 두 공간을 파이프가 차지한다고 치면
            // (nx, ny) = (1,2) 임.
            nx = x + dx[i]; // 각 방향별로 이동
            ny = y + dy[i];
            if (nx >= N || ny >= N || pipe[ny][nx] == 1) // 만일 벽이거나 바깥으로 빠지면?
            {
                return 0; // 길이 없으니 0 리턴
            }
            else if (ny == N - 1 && nx == N - 1)
            {
                return 1;
            }
        }

        // return 되지 않았으므로 갈 곳이 있단 소리다. 
        // 대각선으로 이동한다.
        nx = x + dx[dir];
        ny = y + dy[dir];
    }
    else { // 가로 혹은 세로 상태일때
        nx = x + dx[dir];//이동하고
        ny = y + dy[dir];

        if (nx >= N || ny >= N || pipe[ny][nx] == 1) // 만일 벽이거나 바깥으로 빠지면?
        {
            return 0; // 길이 없으니 0 리턴
        }
        else if (ny == N - 1 && nx == N - 1) 
        {
            return 1;
        }
    }

    // 위 조건문을 빠져나왔다는 것은 이동 가능한 모든 경우의 수에서 계속 진행 가능하단 것이다.

    
    if (dir == 0) // 가로 상태일 경우
    {
        dp[dir][y][x] += DFS(x + dx[dir], y + dy[dir], 0); // 가로 이동
        dp[dir][y][x] += DFS(x + dx[dir], y + dy[dir], 2); // 대각선 이동
    }
    else if (dir == 1) // 세로 상태일 경우
    {
        dp[dir][y][x] += DFS(x + dx[dir], y + dy[dir], 1); // 세로 이동
        dp[dir][y][x] += DFS(x + dx[dir], y + dy[dir], 2); // 대각선 이동
    }
    else {
        dp[dir][y][x] += DFS(x + dx[dir], y + dy[dir], 0); // 가로 이동
        dp[dir][y][x] += DFS(x + dx[dir], y + dy[dir], 1); // 세로 이동
        dp[dir][y][x] += DFS(x + dx[dir], y + dy[dir], 2); // 대각선 이동
    }

    return dp[dir][y][x];


}


int main(void)
{
    std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0); // 느려터진 ios, cin, cout 의 속도 가속시킴 
                // (이게 있어야 정답 처리됨. c++은 느려서 printf나 scanf를 써야하지만 굳이 쓰고 싶으면 이걸 써야한다고 함.)

    std::cin >> N;


    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            std::cin >> pipe[i][j];
        }
        
    }

    // (1,1), (1,2)는 항상 빈칸




    int ans = DFS(1,2,0);


    printf("%d\n", ans);


    return 0;
}
