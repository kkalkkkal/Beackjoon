
# https://www.acmicpc.net/problem/18405

"""
1. 모든 바이러스는 1초마다 상하좌우 방향으로 증식
2. 매초 번호가 낮은 종류의 바이러스 부터 증식
3. 이미 바이러스가 있는 칸으로 증식 불가


입력 조건:
- 첫째줄 : N, K ( 1 <= N <= 200, 1 <= K <= 1000) / N : 시험관 크기, K : 바이러스 종류 수
- 둘째줄 이하 : N개의 줄에 걸쳐서 시험관 정보 입력, 해당 위치에 존재하는 바이러스 번호와 빈 칸 
   ㄴ 빈칸 : 0, 나머지 바이러스 : 자연수
- 마지막 줄 (N+2번째 줄) : S , X , Y ( 0<= S <= 10000, 1 <= x, y <= N)

출력 조건 : S 초 뒤에 (x,y)에 존재하는 바이러스 종류 출력, 해당 위치에 바이러스가 없으면 0 출력
"""

from queue import PriorityQueue
from collections import deque
import copy
import sys
input = sys.stdin.readline

n,k = map(int,input().strip().split())
graph = []

for _ in range(n):
    graph.append(list(map(int,input().strip().split())))

s, x, y = map(int, input().strip().split())

temp = []

"""
풀이 전략 
1. 상하좌우로 증식하는 함수 작성
1-1. 1번 바이러스 부터 순서대로 증식하므로 우선순위 큐를 사용하여 적재함.
1-2. 우선순위 큐에 적재된 순서로 증식하면서 일반 큐에 증식 정보를 적재함
1-3. 우선 순위 큐가 전부 비었을 때 다시 일반 큐에 적재된 내용을 빼서 우선순위 큐에 적재함
1-4. 반복
2. S초 만큼 증식 함수 작동
3. (x,y)에 있는 값 출력
"""


# 바이러스가 증식하는 함수 
def virus(s) :
    q = PriorityQueue() # 증식할 위치를 저장하는 우선순위 큐
    queue = deque() # 증식한 위치를 저장하는 일반 큐
    temp = copy.deepcopy(graph)

    for _ in range(s):
        for i in range(n):
            for j in range(n):
                if 0 < temp[i][j] <= k:
                    q.put([temp[i][j],i,j]) # 바이러스 번호와 위치 정보를 적재

        while q.empty() == False :
            v, row, col = q.get()

            for dx, dy in [[-1,0],[1,0],[0,-1],[0,1]]:
                if 0 <= row + dy < n and 0 <= col + dx < n :
                    if temp[row+dy][col+dx] == 0 :
                        temp[row+dy][col+dx] = v
                        queue.append([v,row+dy,col+dx])

        # 우선순위 큐가 다 끝나면 queue에 적재된 내용을 다 우선순위 큐에 옮기기
        while queue:
            v, row, col = queue.popleft()
            q.put([v,row, col])

    print(temp[x-1][y-1])
    return 0

# S초 동안 바이러스 확산시키기
virus(s)


