
# https://www.acmicpc.net/problem/14502

"""
1. 바이러스가 BFS로 확장하는 함수 작성
2. 벽을 3개 설치하는 모든 조합을 찾는 함수 작성 ( 3 <= N, M <= 8 이므로 64C3 < 100000 이라 시간 초과 없이 전수 조사 가능)
3. 안전 구역 수치를 계산하는 함수 작성
4. 벽을 3개 설치한 상태에서 바이러스를 확장하는 동작을 수행하고, 안전 구역 수치 계산 진행

입력 값 :
- 첫 줄 : N , M
- 2번째 줄부터 N x M 크기의 지도 모양을 입력 (0 : 빈칸 , 1 : 벽, 2: 바이러스)

출력 값 : 
안전 영역의 최대 크기

"""
from collections import deque
import copy
import sys
input = sys.stdin.readline

n,m = map(int, input().strip().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().strip().split())))

#temp = copy.deepcopy(graph)

answer = 0

# 안전구역 크기 계산하는 함수
def get_score(temp) : 
    score = 0
    for i in temp:
        score += i.count(0)
    return score
    

    
# 바이러스 퍼지는 함수
def virus () :
    global answer
    temp = copy.deepcopy(graph)

    queue = deque()

    # 바이러스 위치를 큐에 모두 집어 넣기
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 2: 
                queue.append([i,j])

    while queue :
        row, col = queue.popleft()
        for dx, dy in [[0,1],[0,-1],[1,0],[-1,0]]:
            if 0 <= row + dx < n and 0 <= col + dy < m :
                if temp[row+dx][col+dy] == 0 :
                    temp[row+dx][col+dy] = 2
                    queue.append([row+dx, col+dy])

    answer = max(answer, get_score(temp))


# 벽 3개 설치하는 함수
def set_wall3(count) :
    if count == 3 :
        virus()
        return
    for i in range(0):
        for j in range(m) : 
            if graph[i][j] == 0 :
                graph[i][j] = 1
                set_wall3(count+1)
                graph[i][j] = 0
             

answer = 0
set_wall3(0)
print(answer)

# 시간 초과의 원인 참고 자료 : https://fantastichu.tistory.com/27

"""
풀면서 느낀 점. DFS는 계속 재귀를 하면서 for문을 호출하므로 시간상 불리하여 BFS로 문제를 풀었다.
하지만 다양한 조합에서 문제를 푸는게 가장 문제였는데 
조합(combination)을 사용할 때 (i/m, 

"""