maze = [
    "SOOXX",
    "XXOOO",
    "XOOXO",
    "OOOXX",
    "OOFOO"
]

# 모든 행에 대해 한 칸씩 오른쪽으로 이동해 미로를 만들어봄
for i in range(len(maze)):
    shifted_maze = []
    for row in maze:
        # 한 칸씩 오른쪽으로 이동한 행 만들기
        shifted_row = row[-1] + row[:-1]
        # 만약 i번째 행이면 첫번째 열이 X가 됨
        if maze.index(row) == i:
            shifted_row = "X" + shifted_row[:-1]
        shifted_maze.append(shifted_row)
    
    # 각각의 미로에 대해 최단 거리 구하기
    distances = []
    for row in shifted_maze:
        distance_row = []
        for char in row:
            if char == "S":
                # 시작점은 거리가 0임
                distance_row.append(0)
            elif char == "X":
                # 통행 불가능한 지점은 거리가 무한대임
                distance_row.append(float("inf"))
            else:
                # 통행 가능한 지점은 거리를 계산함
                distance_row.append(None)
        distances.append(distance_row)

    # 각 지점에서의 최단 거리를 계산함
    def find_distance(row, col, distance):
        # 현재 지점의 최단 거리
        current_distance = distance[row][col]
        # 위, 아래, 왼쪽, 오른쪽 지점에서의 최단 거리
        distances = []
        if row > 0:
            distances.append(distance[row-1][col])
        if row < len(distance)-1:
            distances.append(distance[row+1][col])
        if col > 0:
            distances.append(distance[row][col-1])
        if col < len(distance[0])-1:
            distances.append(distance[row][col+1])
        # 최단 거리 = 현재 지점의 최단 거리 + 1
        shortest_distance = min(distances) + 1
        if shortest_distance < current_distance:
            # 최단 거리를 업데이트 함
            distance[row][col] = shortest_distance
            # 주변 지점에 대해서도 최단 거리를 계산함
            if row > 0:
                find_distance(row-1, col, distance)
            if row < len(distance)-1:
                find_distance(row+1, col, distance)
            if col > 0:
                find_distance(row, col-1, distance)
            if col < len(distance[0])-1:
                find_distance(row, col+1, distance)

    # 시작점부터 각 지점까지의 최단 거리를 계산함
    start_row, start_col = None, None
    end_row, end_col = None, None
    for i, row in enumerate(shifted_maze):
        if "S" in row:
            start_row, start_col = i, row.index("S")
        if "F" in row:
            end_row, end_col = i