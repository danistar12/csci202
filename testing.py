# matrix 
adj_matrix = [
    [0, 1, 1, 0],
    [1, 0, 0, 1],
    [1, 0, 0, 1],
    [0, 1, 1, 0]
]

# Convert 
adj_list = {i: [] for i in range(len(adj_matrix))}

for i in range(len(adj_matrix)):
    for j in range(len(adj_matrix[i])):
        if adj_matrix[i][j] == 1:  # There's an edge between i and j
            adj_list[i].append(j)

# Print 
print(adj_list)