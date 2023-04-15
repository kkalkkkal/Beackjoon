
"""
미로를 탈출해야 한다. 
시작 위치: (1,1) 도착 위치 : (N,M)
첫 입력: N,M (4<= N,M <= 200)
이후 입력 : 맵 정보

괴물이 있는 곳 : 0
괴물이 없는 곳 : 1

출력 : 탈출을 위해 움직여야 하는 최소 칸 수 입력
"""


from collections import deque

n,m = map(int, input().split())

graph = []

for i in range(n):
    graph.append(list(map(int,input())))

visited = [[0] * m for _ in range(n)]


def bfs(graph, start_row, start_col, visited):
    count = 1 
    ## 괴물이 없으면서 방문한 적이 없으면, 
    if graph[start_row][start_col] == 1 and visited[start_row][start_col] == 0 :
        queue = deque([[start_row, start_col]])
        visited[start_row][start_col] = 1
        
        while queue : 
            row, col = queue.popleft()
            # 만약 출구에 도착했으면 리턴
            if len(queue) == 0 : # 큐가 비어져 있단 것은 한 분기가 끝났다는 것을 의미한다.
                count += 1
            for dx, dy in [[-1,0], [1,0],[0,-1],[0,1]]:
                if row + dx >= 0 and row + dx < n and col + dy >=0 and col + dy < m:
                    if graph[row+dx][col+dy] == 1 and visited[row+dx][col+dy] == 0 :
                        queue.append([row+dx,col+dy])
                        visited[row+dx][col+dy] = 1
                    # (n,m)에 도달하면 리턴
                    if row + dx == n - 1 and col + dy == m - 1 :
                        return count
                # Todo : 분기점마다 count가 늘어나는 것을 고쳐야한다. 
            
    return 0

answer = bfs(graph, 0, 0, visited)

print(answer)

