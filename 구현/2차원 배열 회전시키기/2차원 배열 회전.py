import copy

arr = [[1,2,3],
	   [4,5,6],
	   [7,8,9]]

arr2 = [[1,2,3,4],
		[5,6,7,8],
		[9,10,11,12],
		[13,14,15,16]]

arr3 = [[1,2,3,4,5],
		[6,7,8,9,10],
		[11,12,13,14,15],
		[16,17,18,19,20],
		[21,22,23,24,25]]


# 시계 방향 90도 회전 
def rotate_90(arr):
	temp = copy.deepcopy(arr)
	N = len(arr)
	for i in range(N):
		for j in range(N):
			temp[i][j] = arr[N-1-j][i]

	return temp
answer = []
answer = rotate_90(arr2)

print(answer)

def rotate_90_another(arr):
	return list(zip(*arr[::-1]))

def rotate_90_the_other(arr):
	return [[row[i] for row in original[::-1]] for i in range(len(original[0]))]

answer = rotate_90_another(arr2)

print(answer)