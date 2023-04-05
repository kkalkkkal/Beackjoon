
from queue import PriorityQueue
from collections import deque
import time 

pq = PriorityQueue()
q = deque()



n, k = map(int, input().split())

graph = []
data = []

for i in range(n):
    graph.append(list(map(int,input().split())))
    for j in range(n):
        if graph[i][j] != 0 :
            data.append((graph[i][j], 0 , i ,j))

start_time = time.time()            
data.sort()
q = deque(data)

target_s, target_x, target_y = map(int,input().split())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

while q :
    virus, s, x, y = q.popleft()
    if s == target_s:
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx and nx < n and 0 <= ny and ny < n :
            if graph[nx][ny] == 0 :
                graph[nx][ny] = virus
                q.append((virus, s+1, nx, ny))
                
print(graph[target_x - 1][target_y-1])
end_time = time.time()

print("소팅한 일반 큐 :", end_time - start_time )



from queue import PriorityQueue
from collections import deque
import copy
import sys
input = sys.stdin.readline

n,k = map(int,input().strip().split())
graph = []
q = PriorityQueue() # 증식할 위치를 저장하는 우선순위 큐
q2 = PriorityQueue()

for i in range(n):
    graph.append(list(map(int,input().strip().split())))
    for j in range(n):
        if graph[i][j] != 0:
            q.put([graph[i][j],i,j]) # 바이러스 번호와 위치 정보를 적재

s, x, y = map(int, input().strip().split())

start_time = time.time()            


def check(queue, queue2):
    global graph
    while queue.empty() == False :
        v, row, col = queue.get()
        for dx, dy in [[-1,0],[1,0],[0,-1],[0,1]]:
            if 0 <= row + dy < n and 0 <= col + dx < n :
                if graph[row+dy][col+dx] == 0 :
                    graph[row+dy][col+dx] = v
                    queue2.put([v,row+dy,col+dx])


# 바이러스가 증식하는 함수 
def virus(s) :
    for _ in range(s):
        if q.empty() : 
            check(q2,q)
        else :
            check(q,q2)

    print(graph[x-1][y-1])
    return 0

# S초 동안 바이러스 확산시키기
virus(s)
end_time = time.time()
print("우선 순위 큐 :", end_time - start_time)


