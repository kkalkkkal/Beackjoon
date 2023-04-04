from collections import deque


n,m = map(int, input().split())

graph = []
for i in range(n):
    graph.append(list(map(int, input())))

visited = [[0] * m for _ in range(n)]

def bfs(graph, start_row, start_col, visited):

    if graph[start_row][start_col] == 0 and visited[start_row][start_col] == 0: # 구멍인 경우
        queue = deque([[start_row, start_col]])

        # 방문 지점 표시
        visited[start_row][start_col] = 1

        # 큐가 다 할 때까지 진행
        while queue:
            row, col = queue.popleft() # 현재 위치 뽑고
            # 거기서 상하좌우를 살피고 인접한 구멍이 있으면 큐에 집어 넣기
            for dx, dy in [[-1,0], [1,0], [0,-1],[0,1]]:
                # 유효한 인덱스가 존재하면 (범위에서 벗어나지 않으면)
                if row + dx >= 0 and row + dx < n and col + dy >= 0 and col + dy < m:
                    # 연결된 구멍이 있고 방문한 적도 없으면
                    if graph[row+dx][col+dy] == 0  and visited[row+dx][col+dy] == 0 :
                        queue.append([row+dx, col+dy]) # 큐에 추가
                        # 방문 지점 표시
                        visited[row+dx][col+dy] = 1


        return 1
    else :
        return 0


answer = 0 
for row in range(n):
    for col in range(m):
        answer += bfs(graph, row, col, visited)

print(answer)