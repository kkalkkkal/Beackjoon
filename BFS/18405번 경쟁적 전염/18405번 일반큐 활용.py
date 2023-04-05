from collections import deque

n, k = map(int, input().split())

graph = []
data = []

for i in range(n):
    graph.append(list(map(int,input().split())))
    for j in range(n):
        if graph[i][j] != 0 :
            data.append((graph[i][j], 0 , i ,j))
            
data.sort()
q = deque(data)

target_s, target_x, target_y = map(int,input().split())


while q :
    virus, s, x, y = q.popleft()
    if s == target_s:
        break
    for dx, dy in [[-1,0],[1,0],[0,-1],[0,1]]:
        if 0 <= x +dx and x + dx < n and 0 <= y + dy and y + dy < n :
            if graph[x+dx][y+dy] == 0 :
                graph[x+dx][y+dy] = virus
                q.append((virus, s+1, x+dx, y+dy))
                
print(graph[target_x - 1][target_y-1])
        
    
