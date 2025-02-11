import heapq

adj_list = {
    "A": [("B", 1), ("C", 4)],
    "B": [("D", 2), ("E", 5)],
    "C": [("B", 1), ("F", 3)],
    "D": [],
    "E": [("F", 2)],
    "F": []
}

def ucs(start, goal):
    priority_queue = []
    heapq.heappush(priority_queue, (0, start))
    visited = set()
    parents = {start: None}
    cost = {start: 0}

    while priority_queue:
        current_cost, current_node = heapq.heappop(priority_queue)

        if current_node == goal:
            path = []
            while current_node:
                path.append(current_node)
                current_node = parents[current_node]
            return path[::-1], current_cost

        if current_node in visited:
            continue

        visited.add(current_node)

        for neighbor, weight in adj_list.get(current_node, []):
            new_cost = current_cost + weight
            if neighbor not in cost or new_cost < cost[neighbor]:
                cost[neighbor] = new_cost
                parents[neighbor] = current_node
                heapq.heappush(priority_queue, (new_cost, neighbor))

    return None, float('inf')

start_node = "A"
goal_node = "F"

path, total_cost = ucs(start_node, goal_node)

print("Path from {} to {}: {}".format(start_node, goal_node, path))
print("Total Cost: {}".format(total_cost))
