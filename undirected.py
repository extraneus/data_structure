def dfs(u, color, parent):
    color[u] = 'G'
    for v in adj_list[u]:
        if color[v] == 'W':
            parent[v] = u
            cycle = dfs(v, color, parent)
            if cycle:
                return True
        elif color[v] == 'G' and parent[u] != v:  # Check for non-parent visited node
            print("Cycle found", u, v)
            return True
    color[u] = 'B'
    return False
