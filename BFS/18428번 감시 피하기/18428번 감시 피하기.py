
"""
1. 선생은 상하좌우 모든 거리에 있는 학생을 볼 수 있다.
2. 선생은 장애물 뒤에 있는 학생을 볼 수 없다. 
3. 학생은 벽 3개를 설치하여 모든 선생의 시야에서 벗어나야한다. 



"""
from collections import deque

n = int(input())

graph = [] # 복도 
teachers = []
space = []

for i in range(n):
    graph.append(list(input().split()))
    for j in range(n):
        # 선생 위치 저장
        if graph[i][j] == 'T' :
            teachers.append([i,j])
        # 벽 설치 가능 위치 저장
        elif graph[i][j] == 'X' :
            space.append([i,j])

# 선생의 시야에 학생들이 들어오는지 확인 함수
def check_teachers_watch(x,y,direction) : # x,y는 선생의 위치

    # 왼쪽
    if direction == 0 :
        while y >= 0 :
            if graph[x][y] == 'S':
                return True
            if graph[x][y] == 'O':
                return False
            y -= 1
    # 오른쪽
    if direction == 1 :
        while y < n : 
            if graph[x][y] == 'S':
                return True
            if graph[x][y] == 'O':
                return False 
            y += 1
    #위쪽
    if direction == 2:
        while x >= 0 :
            if graph[x][y] == 'S':
                return True
            if graph[x][y] == 'O':
                return False 
            x -= 1
    #아래쪽
    if direction == 3:
        while x < n :
            if graph[x][y] == 'S':
                return True
            if graph[x][y] == 'O':
                return False 
            x += 1
    return False 

# 선생님 감시 동작 진행
def process() :
    for x, y in teachers :
        for i in range(4):
            if check_teachers_watch(x,y,i): # 감시되는 학생이 있으면
                return True
    return False # 없으면 

find = False 

# 벽 3개 설치하는 함수 (DFS)
def set_wall3(count) :
    global find
    if count == 3 :
        if not process(): # 감시했을 때 걸리는 학생이 없으면 
            find = True
        return
    for i, j in space :
        if graph[i][j] == 'X' : 
            graph[i][j] = 'O'
            set_wall3(count+1)
            graph[i][j] = 'X'


set_wall3(0)

if find :
    print("YES")
else :
    print("NO")
