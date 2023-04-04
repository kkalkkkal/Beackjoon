
"""
입력 조건 : 
1. 첫줄에 도시의 개수 N, 도로 개수 M, 거리 정보 K, 출발 도시의 번호 X가 주어집니다.
( 2<=N <= 300000, 1 <= M <= 1000000 , 1 <= K <= 300000 , 1 <= X <= N ) 
2. 각 줄마다 자연수 A, B가 주어지며 
A번 도시에서 B번 도시로 이동하는 단반향 도로가 존재한다는 의미

출력 조건 : X로 부터 출발하여 도달할 수 있는 도시 중에서 최단 거리가 K인 모든 도시의 번호를 
한 줄에 하나씩 오름차순으로 출력
만약 출력할 수 있는 도시가 없으면 -1 출력

"""

from collections import deque

n, m , k , x  = map(int, input().split())

# 각 노드에 연결된 리스트 표현
city = [[] for _ in range(n+1)]

for i in range(m):
    a,b = map(int,input().split())
    city[a].append(b)   # 팁 : extend는 +=보다 느리고, +=는 append보다 느리다.
    

distance = [-1] * (n+1)
distance[x] = 0

def bfs(city, start, distance) :
    queue = deque([start])
    
    #큐가 빌 때까지 반복
    while queue :
        # 큐에서 하나의 원소를 뽑아 출력
        v = queue.popleft()

        #해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for i in city[v]:
            if distance[i] == -1:
                distance[i] = distance[v] + 1
                queue.append(i)
        
    return 0



bfs(city, x, distance)

distance.sort()
check = 0 
for i in range(1,n+1) : 
    if distance[i] == k : 
        print(i)
        check = 1

if check == 0 :
    print("-1")