
# https://www.acmicpc.net/problem/14502

# 벽 3개를 세워서 안전 영역의 크기 최대값을 구하시오
# 시간 초과 원인 : https://www.acmicpc.net/board/view/94122
import time


n, m = map(int, input().split())

data = [] # 입력 받은 맵
temp = [[0] * m for _ in range(n)] # 벽을 설치한 뒤의 맵

for i in range(n):
    data.append(list(map(int,input().split())))

# 4가지 이동 방향에 대한 리스트
dx = [-1, 0 , 1, 0]
dy = [0, 1, 0 ,-1]

result = 0

# 바이러스 전파 함수
def virus(x,y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx >= 0 and nx < n and ny >= 0 and ny < m:
            if temp[nx][ny] == 0 : #빈 곳이면
                temp[nx][ny] = 2 # 바이러스 확장
                virus(nx,ny) # 확장한 곳에서 다시 재귀 실행

# 안전지대 구하는 함수
def get_score():
    score = 0 
    # O(n^2)로 전수 조사해서 안전지대가 있을 때마다 1점 추가
    for i in range(n):
        for j in range(m):
            if temp[i][j] == 0:
                score += 1
    
    return score


# DFS를 이용해 울타리를 설치하면서, 매번 안전 영역의 크기를 계산
def dfs(count):
    global result

    # 울타리가 3개 설치된 경우
    if count == 3:
        for i in range(n):
            for j in range(m):
                temp[i][j] = data[i][j]
            # 각 바이러스의 위치에서 전파 진행
            for i in range(n):
                for j in range(m):
                    if temp[i][j] == 2:
                        virus(i,j)
        # 안전 영역의 최댓값 계산
        result = max(result, get_score())
        return

    # 빈 공간에 울타리 설치
    for i in range(n):
        for j in range(m):
            if data[i][j] == 0 :
                data[i][j] = 1
                count += 1
                dfs(count) # 여기서 리턴 되었다는 것은 울타리 3개가 다 설치 되었어도 return 되지 않았다는 것
                data[i][j] = 0 # 다시 쳤던 울타리를 초기화하는 것
                count -= 1


start_time = time.time()

print(get_score())
#print(result)

end_time = time.time()

print("걸린 시간 : ", end_time - start_time)