
# https://www.acmicpc.net/problem/18406


# 입력 받기(문자열로 취급하여 읽기)
n = list(map(int,input()))


# 길이의 절반값 구하기
half = int(len(n) / 2)

left = n[:half]
right = n[half:]

result = 0  
for a, b in zip(left, right):
    result += a
    result -= b


if result == 0 :
    print("LUCKY")
else :
    print("READY")

