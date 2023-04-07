from collections import deque

n, l, r = map(int,input().split())

graph = []
for _ in range(n):
    graph.append(list(map(int,input().split())))

dx = [-1,0,1,0]
dy = [0,-1,0,1]
result = 0

# 특정 위치에서 출발하여 모든 연합을 체크한 뒤에 데이터 갱신
def process(x,y,index):
    # (x,y)의 위치와 연결된 나라(연합) 정보를 담는 리스트
    united = []
    united.append((x,y))
    #BFS를 위한 큐 자료구조 정의
    q = deque()
    q.append((x,y))
    union[x][y] = index # 현재 연합의 번호 할당
    summary = graph[x][y] # 현재 연합의 전체 인구수
    count = 1 # 현재 연합의 국가 수

    while q :
        x , y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<= nx < n and 0 <= ny < n and union[nx][ny] == -1:
                if l <= abs(graph[nx][ny] - graph[x][y]) <= r:
                    q.append((nx,ny))
                    union[nx][ny] = index
                    summary += graph[nx][ny]
                    count += 1
                    united.append((nx,ny))
    for i,j in united:
        graph[i][j] = summary // count
    return count

total_count = 0 

while True:
    union = [[-1] * n for _ in range(n)]
    index = 0 
    for i in range(n):
        for j in range(n):
            if union[i][j] == -1 : # 해당 나라가 아직 처리되지 않았다면
                process(i,j,index)
                index +=1 

    if index == n * n:
        break
    total_count +=1
# 인구 이동 횟수 출력
print(total_count)
