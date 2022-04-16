# Python3 implementation to build a
# graph using Dictionaries

from collections import defaultdict
from pprint import pprint

# Function to build the graph
def build_graph():
	edges = [
		["A", "B"], ["A", "E"],
		["A", "C"], ["B", "D"],
		["B", "E"], ["C", "F"],
		["C", "G"], ["D", "E"]
	]
	graph = defaultdict(list)
	
	# Loop to iterate over every
	# edge of the graph
	for edge in edges:
		a, b = edge[0], edge[1]
		
		# Creating the graph
		# as adjacency list
		graph[a].append(b)
		graph[b].append(a)
	return graph

graph = build_graph()

pprint(graph)


# Function to build the graph
def build_graph_2():
	graph = {}

	def append_helper(key, value):
		if graph.get(key) is not None:
			graph[key].append(value)
		else:
			graph[key] = [value]
   
	edges = [
		["A", "B"], ["A", "E"],
		["A", "C"], ["B", "D"],
		["B", "E"], ["C", "F"],
		["C", "G"], ["D", "E"]
	]
	
	# Loop to iterate over every
	# edge of the graph
	for edge in edges:
		a, b = edge[0], edge[1]
		
		# Creating the graph
		# as adjacency list
		append_helper(a,b)
		append_helper(b,a)
	return graph

graph2 = build_graph_2()

pprint(graph2)