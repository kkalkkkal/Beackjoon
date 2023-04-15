
# https://www.acmicpc.net/problem/14888
"""
Q. 숫자의 순서를 바꾸지 않고, 사이에 사칙연산 기호를 삽입하여 나올 수 있는 모든 경우에서 최대, 최소값 구하기

입력 조건
1. 첫째 줄 : 수의 개수 N (2 <= N <= 11)
2. 둘째 줄 : A1 ~ An ( 1 < = A <= 100)
3. 셋째 줄 : 합이 N-1인 4개의 정수, 차례대로 +, - , * , / 의 수이다. 

출력 조건 :
1. 첫째 줄 : 나올 수 있는 식의 결과의 최댓값 출력
2. 줄째 줄 : 최솟값 출력
"""

n = int(input())


a = list(map(int, input().split()))

p_num, m_num, x_num, d_num = map(int, input().split()) 


# DFS

max_value = -1e9
min_value = 1e9

def dfs(i, now) :
    global max_value, min_value, p_num, m_num, x_num, d_num
    if i == n : 
        max_value = max(now, max_value)
        min_value = min(now, min_value)
    else :
        if p_num > 0 : 
            p_num -= 1
            dfs(i+1, now + a[i])
            p_num += 1
        if m_num > 0 :
            m_num -= 1
            dfs(i+1, now - a[i])
            m_num += 1
        if x_num > 0 :
            x_num -= 1
            dfs(i+1, now * a[i])
            x_num += 1
        if d_num > 0 :
            d_num -= 1
            dfs(i+1, int(now / a[i]))
            d_num += 1
    
    return

dfs(1, a[0])
print(int(max_value))
print(int(min_value))

