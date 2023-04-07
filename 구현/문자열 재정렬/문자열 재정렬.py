
S = input()
sum = 0 
a = []

for i in S :
    if i.isdigit() :
        sum += int(i)
    else : 
        a.append(i)

a.sort()
answer = "".join(a) + str(sum)
print(answer)