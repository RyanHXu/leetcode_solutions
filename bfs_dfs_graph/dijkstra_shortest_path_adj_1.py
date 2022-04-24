from pprint import pprint
# https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/


# https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/?ref=lbp


# https://www.youtube.com/watch?v=pSqmAO-m7Lk
# A Python program for Dijkstra's shortest
# path algorithm for adjacency
# list representation of graph


# a star
# https://stackabuse.com/basic-ai-concepts-a-search-algorithm/


from collections import defaultdict


class Heap():

    def __init__(self):
        self.array = []
        self.size = 0
        self.pos = []

    def newMinHeapNode(self, v, dist):
        minHeapNode = [v, dist]
        return minHeapNode

    # A utility function to swap two nodes
    # of min heap. Needed for min heapify
    def swapMinHeapNode(self, a, b):
        t = self.array[a]
        self.array[a] = self.array[b]
        self.array[b] = t

    # A standard function to heapify at given idx
    # This function also updates position of nodes
    # when they are swapped.Position is needed
    # for decreaseKey()
    def minHeapify(self, idx):
        smallest = idx
        left = 2*idx + 1
        right = 2*idx + 2

        if (left < self.size and
            self.array[left][1]
                < self.array[smallest][1]):
            smallest = left

        if (right < self.size and
            self.array[right][1]
                < self.array[smallest][1]):
            smallest = right

        # The nodes to be swapped in min
        # heap if idx is not smallest
        if smallest != idx:

            # Swap positions
            self.pos[self.array[smallest][0]] = idx
            self.pos[self.array[idx][0]] = smallest

            # Swap nodes
            self.swapMinHeapNode(smallest, idx)

            self.minHeapify(smallest)

    # Standard function to extract minimum
    # node from heap
    def extractMin(self):

        # Return NULL wif heap is empty
        if self.isEmpty() == True:
            return

        # Store the root node
        root = self.array[0]

        # Replace root node with last node
        lastNode = self.array[self.size - 1]
        self.array[0] = lastNode

        # Update position of last node
        self.pos[lastNode[0]] = 0
        self.pos[root[0]] = self.size - 1

        # Reduce heap size and heapify root
        self.size -= 1
        self.minHeapify(0)
        # customzed operation
        # self.array.pop()
        # self.pos.pop()

        return root

    def isEmpty(self):
        return True if self.size == 0 else False

    # utility function for Dijkstra's algorithm
    def decreaseKey(self, v, dist):

        # Get the index of v in heap array

        i = self.pos[v]

        # Get the node and update its dist value
        self.array[i][1] = dist

        # Travel up while the complete tree is
        # not hepified. This is a O(Logn) loop
        while (i > 0 and self.array[i][1] <
               self.array[(i - 1) // 2][1]):

            # Swap this node with its parent
            self.pos[self.array[i][0]] = (i-1)//2
            self.pos[self.array[(i-1)//2][0]] = i
            self.swapMinHeapNode(i, (i - 1)//2)

            # move to parent index
            i = (i - 1) // 2

    # A utility function to check if a given
    # vertex 'v' is in min heap or not

    def isInMinHeap(self, v):

        if self.pos[v] < self.size:
            return True
        return False


def printArr(dist, n):
    print("Vertex\tDistance from source")
    for i in range(n):
        print("%d\t\t%d" % (i, dist[i]))


class Graph():

    def __init__(self, V):
        self.V = V
        self.graph = defaultdict(list)

    # Adds an edge to an undirected graph
    def addEdge(self, src, dest, weight):

        # Add an edge from src to dest. A new node
        # is added to the adjacency list of src. The
        # node is added at the beginning. The first
        # element of the node has the destination
        # and the second elements has the weight
        newNode = [dest, weight]
        self.graph[src].insert(0, newNode)

        # Since graph is undirected, add an edge
        # from dest to src also
        newNode = [src, weight]
        self.graph[dest].insert(0, newNode)

    # The main function that calculates distances
    # of shortest paths from src to all vertices.
    # It is a O(ELogV) function
    def dijkstra(self, src,dest):
        V = self.V
        dist =[]
        # prev = [None for _ in range(V*2)]
        prev = {}
        minHeap = Heap()
        
        for v in range(V):
            dist.append(1e7)
            minHeap.array.append([v,dist[v]])
            minHeap.pos.append(v)
            
        minHeap.pos[src] = src
        dist[src]=0
        minHeap.decreaseKey(src,dist[src])
        
        minHeap.size = V
        
        while minHeap.isEmpty() == False:
            
            newHeapNode = minHeap.extractMin()
            u = newHeapNode[0]
            
            if u == dest:
                path = []
                # path.append(u)
                t = u
                while len(prev.keys())>0 and prev[t] != src:
                    next = prev[t]
                    path.append(next)
                    prev.pop(t)
                    t = next
                
                if len(path) > 0:
                    path.append(src)
                    path.reverse()
                    path.append(u)
                    pprint(minHeap.array)
                    pprint(dist)
                    print(path)
                    print(f"the weight of from {src} to {dest}: {dist[u]}")
                    return  path
                else:
                    return path
            
             
            for edge in self.graph[u]:
                v = edge[0]
                
                if minHeap.isInMinHeap(v) and dist[u] != 1e7 and \
                    edge[1] + dist[u] < dist[v]:
                        # prev[edge[1]] = u
                        prev[edge[0]]=u
                        dist[v] = edge[1] + dist[u]
                        minHeap.decreaseKey(v,dist[v])

        sorted(prev.items(),key=lambda x:x[0])
        # pprint(prev)
        # printArr(dist, V)

    


# Driver program to test the above functions
graph = Graph(9)
graph.addEdge(0, 1, 4)
graph.addEdge(0, 7, 8)
graph.addEdge(1, 2, 8)
graph.addEdge(1, 7, 11)
graph.addEdge(2, 3, 7)
graph.addEdge(2, 8, 2)
graph.addEdge(2, 5, 4)
graph.addEdge(3, 4, 9)
graph.addEdge(3, 5, 14)
graph.addEdge(4, 5, 10)
graph.addEdge(5, 6, 2)
graph.addEdge(6, 7, 1)
graph.addEdge(6, 8, 6)
graph.addEdge(7, 8, 7)
graph.dijkstra(0,8)


# This code is contributed by Divyanshu Mehta
