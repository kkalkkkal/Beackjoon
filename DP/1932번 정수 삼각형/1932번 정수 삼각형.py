
"""
풀이 전략 : 아래에서 위로 올라가며 최대값만 더하기

입력 조건 :
1. 첫 줄 : 삼각형의 크기 n (1 <= n <= 500)
2. 둘째 줄부터 n+1번째 줄까지 정수 삼각형 입력

출력 조건 : 
1. 합의 최대값 출력
"""

n = int(input())

tri = []

for i in range(n):
    tri.append(list(map(int, input().split())))

# 밑에서 부터 시작하기 

tri.reverse()
answer = 0

for i in range(1,n):
    for j in range(n-i) :
        tri[i][j] += max(tri[i-1][j], tri[i-1][j+1])

answer = tri[n-1][0]

print(answer)