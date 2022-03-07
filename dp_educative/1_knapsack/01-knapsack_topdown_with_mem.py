

from pprint import pprint

def solve_knapsack(profits, weights, capacity):
    n = len(profits)
    dp = [[-1 for i in range(capacity+1)] for j in range(n)]
    
    def knapsackTopDown(profits, weights, capacity, currIndex=0):
        if currIndex > n-1 or capacity<=0:
            return 0
        
        # if you cal it before
        if dp[currIndex][capacity] != -1:
            return dp[currIndex][capacity]
        
        profit1=profit2=0
        if weights[currIndex] <= capacity:
            profit1 = profits[currIndex] + knapsackTopDown(profits,weights,capacity-weights[currIndex],currIndex+1)
        profit2 = knapsackTopDown(profits,weights,capacity,currIndex+1)
        
        dp[currIndex][capacity] = max(profit1,profit2)
        
        return dp[currIndex][capacity]
        
    return knapsackTopDown(profits,weights,capacity)
    
print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 7))
print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 6))
