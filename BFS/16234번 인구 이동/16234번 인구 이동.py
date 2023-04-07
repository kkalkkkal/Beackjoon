
# https://www.acmicpc.net/problem/16234

"""
인구수 차가 L~R명이면 인접한 나라끼리 이동이 가능하다.
인접한 칸으로 이동가능한 나라를 묶어 '연합'이라 한다.
연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수)/(연합을 이루고 있는 칸의 개수)가 된다.

입력 조건 : 
1. 첫째 줄 : N, L, R ( 1<=N<=50, 1 <= L <= R <= 100)
2. 줄째 줄부터 N줄에 걸쳐 각 나라의 인구수를 입력, A에는 각 나라의 인구수를 입력, 0 <= A[r][c] <=100

출력 조건 : 인구 이동이 몇 번 일어나는 지 출력
"""

from collections import deque

n, l, r = map(int, input().split())

A = []

for i in range(n):
    A.append(list(map(int,input().split())))

# 시작 위치에서 연결된 나라가 정보를 담는 함수 (연합 도출) 
def bfs(start_row, start_col, index):
    united = [] # 연합 정보
    united.append([start_row,start_col])
    q = deque([[start_row,start_col]]) # 연합 탐색큐 
    summary = A[start_row][start_col] # 현재 연합 인구수
    union[start_row][start_col] = index # 연합 번호 (방문정보) 저장
    count = 1 # 현재 연합 구성 수
    while q :
        row, col = q.popleft()
        for dx, dy in [[-1,0], [1,0],[0,1],[0,-1]]:
            if 0 <= row + dy < n and 0 <= col + dx < n and union[row+dy][col+dx] == -1:
                if l <= abs(A[row][col] - A[row+dy][col+dx]) <= r:
                    # 연합에 해당 위치 추가
                    q.append([row+dy,col+dx])
                    # 연합 인구수 추가
                    union[row+dy][col+dx] = index
                    summary += A[row+dy][col+dx]
                    count += 1
                    united.append([row+dy, col+dx])

    people = summary // count
    for i, j in united:
        A[i][j] = people
    return count

total_count = 0 


while True :
    union = [[-1] * n for _ in range(n)]
    index  = 0 
    for i in range(n):
        for j in range(n):
            if union[i][j] == -1 :
                bfs(i,j,index)
                index += 1

    if index == n*n:
        break
    total_count += 1

print(total_count)