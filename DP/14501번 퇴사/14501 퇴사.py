
#https://www.acmicpc.net/problem/14501

n = int(input())

data = []
answer = 0

for i in range(n):
    data.append(list(map(int,input().split())))

dp = [0] * n


for i in range(n) : 
    t = data[i][0]
    p = data[i][1]
    
    if i + t - 1 >= n : # 상담 불가
        dp[i] = 0
    else :
        dp[i] += p
        if i+t < n :
            for j in range(i+t,n):
                dp[j] = max(dp[j], dp[i])

answer = max(dp)

print(answer)