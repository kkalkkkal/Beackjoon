
"""

입력 조건 
1. 첫 줄 : 테스트케이스 T 입력 (1 <= T <= 1000)
2. 매 테스트케이스 첫 째줄에 n,m입력
3. n x m개의 위치에 매장된 금ㄱ의 개수가 공백으로 구분되어 입력 

출력 조건 
1. 테스트 케이스 마다 채굴자가 얻을 수 있는 금의 최대 크기를 출력.
"""


T = int(input())


for k in range(T):
    n,m = map(int, input().split())
    data = list(map(int, input().split()))
    graph = []

    for _ in range(n) : 
        graph.append(data[:m])
        data = data[m:]

    answer = 0

    for col in range(1,m):
        for row in range(n):
            if row == 0 :
                graph[row][col] += max(graph[row][col-1], graph[row + 1][col - 1]) 
            elif row == n - 1 :
                graph[row][col] += max(graph[row][col-1], graph[row - 1][col - 1])
            else :
                graph[row][col] += max(graph[row][col-1], graph[row + 1][col - 1], graph[row - 1][col - 1])

    for row in range(n) :
        answer = max(answer, graph[row][m-1])


    print( answer)

