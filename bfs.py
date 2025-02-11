from queue import Queue

adj_list = {
    "A": ["B", "D"],
    "B": ["A", "C"],
    "C": ["B"],
    "D": ["A", "E", "F"],
    "E": ["D", "F", "G"],
    "F": ["D", "E", "H"],
    "G": ["E", "H"],
    "H": ["G", "F"]
}

visited={}
level={}
parents={}
bfs_travel_output=[]
que=Queue()

for node in adj_list.keys():
    visited[node]=False
    parents[node]=None
    level[node]=-1

s="A"
visited[s]=True
level[s]=0
que.put(s)

while not que.empty():
    u=que.get()
    bfs_travel_output.append(u)
    
    for v in adj_list[u]:
        if not visited[v]:
            visited[v]=True
            parents[v]=u
            level[v]=level[u]+1
            que.put(v)
                 
print(bfs_travel_output)
print(visited)
print(level)
print(parents)
