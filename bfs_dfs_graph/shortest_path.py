# https://stackoverflow.com/questions/8922060/how-to-trace-the-path-in-a-breadth-first-search


# NOTE: The following codes are based on the assumption that there's NO cycles.

# graph is in adjacent list representation
graph = {
    '1': ['2', '3', '4'],
    '2': ['5', '6'],
    '5': ['9', '10'],
    '4': ['7', '8'],
    '7': ['11', '12']
}


def bfs_list(graph, start, end):
    # maintain a queue of paths
    queue = []
    # push the first path into the queue
    queue.append([start])
    while queue:
        # get the first path from the queue
        path = queue.pop(0)
        # get the last node from the path
        node = path[-1]
        # path found
        if node == end:
            return path
        # enumerate all adjacent nodes, construct a
        # new path and push it into the queue
        for adjacent in graph.get(node, []):
            new_path = list(path)
            new_path.append(adjacent)
            queue.append(new_path)
    


        
def backtrace(parent, start, end):
    path = [end]
    while path[-1] != start:
        path.append(parent[path[-1]])
    path.reverse()
    return path
    
def bfs_map(graph, start, end):
    
    parent = {}
    queue = []
    queue.append(start)
    while queue:
        node = queue.pop(0)
        if node == end:
            return backtrace(parent, start, end)
        for adjacent in graph.get(node, []):
            if node not in queue :
                parent[adjacent] = node # <<<<< record its parent 
                queue.append(adjacent)


print(bfs_list(graph, '1', '11'))
print(bfs_map(graph, '1', '11'))


