# https://www.geeksforgeeks.org/union-find/


from collections import defaultdict

#This class represents a undirected graph using adjacency list representation
class Graph:

	def __init__(self,vertices):
		self.V= vertices #No. of vertices
		self.graph = defaultdict(list) # default dictionary to store graph


	# function to add an edge to graph
	def addEdge(self,u,v):
		self.graph[u].append(v)

	# A utility function to find the subset of an element i
	def find(self, parent,i):
		if parent[i] == -1:
			return i
		return self.find(parent,parent[i])

	# A utility function to do union of two subsets
	def union(self,parent,x,y):
		parent[x] = y

	def print_graph(self,parent):
		s = set()
		for key in self.graph:
			s.add(key)
			for value in self.graph[key]:
				s.add(value)
    
  
		for sub in s:
			print(f"{sub:>4}" ,end=" ")
		print()
   
		for sub in s:
			print(f"{parent[sub]:>4}",end=' ')
		print('\n')


	# The main function to check whether a given graph
	# contains cycle or not
	def isCyclic(self):
		
		# Allocate memory for creating V subsets and
		# Initialize all subsets as single element sets
		parent = [-1]*(self.V)
  

		# Iterate through all edges of graph, find subset of both
		# vertices of every edge, if both subsets are same, then
		# there is cycle in graph.
		# self.graph is key
  		# self.graph[key] is value - list
		for u in self.graph:
			for v in self.graph[u]: # traverse the value(list) of key(u)
				x = self.find(parent, u)
				y = self.find(parent, v)
    
				if x == y:
					return True
				self.union(parent,x,y)
				self.print_graph(parent)

# Create a graph given in the above diagram
g = Graph(100)

g.addEdge(0, 1)
g.addEdge(2, 3)
g.addEdge(3, 4)
g.addEdge(10,11)
g.addEdge(11,12)
g.addEdge(0,10)
print(g.graph)



if g.isCyclic():
	print ("Graph contains cycle")
else :
	print ("Graph does not contain cycle ")

#This code is contributed by Neelam Yadav
