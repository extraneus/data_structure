
adj_list = {
    "A": ["B", "C"],
    "B": ["D", "E"],
    "C": ["B", "F"],
    "D": [],
    "E": ["F"],
    "F": []
}

colors = {}  
parents = {}  
travel_time = {} 
dfs_output = [] 

for node in adj_list.keys():
    colors[node] = "W"  
    parents[node] = None 
    travel_time[node] = [-1, -1]  

print("Initial Colors:", colors)
print("Initial Travel Time:", travel_time)
print("Initial Parents:", parents)

time = 0

def dfs_util(u):
    global time
    colors[u] = "G"  
    travel_time[u][0] = time  
    dfs_output.append(u)  
    time += 1 

    # Explore neighbors
    for v in adj_list[u]:
        if colors[v] == "W":  
            parents[v] = u  
            dfs_util(v) 

    colors[u] = "B"  
    travel_time[u][1] = time  
    time += 1  

dfs_util("A")

print("\nFinal Colors:", colors)
print("Final Travel Time:", travel_time)
print("Final Parents:", parents)
print("DFS Output:", dfs_output)
