

from pprint import pprint


def solve_knapsack(profits, weights, capacity):
    dp =[[-1 for i in range(capacity+1)] for j in range(len(profits))]
    # pprint(dp)

    def knapsack(profits, weights, capacity, index=0):
        if capacity <= 0 or index > len(profits)-1:
            return 0
        # NOTE: 
        # check if we calculated it before
        if dp[index][capacity] != -1:
            return dp[index][capacity]
        
        profit1 = profit2 = 0
        if weights[index] <= capacity:
            profit1 = profits[index] + \
                knapsack(profits, weights, capacity-weights[index], index+1)

        profit2 = knapsack(profits, weights, capacity, index+1)
        dp[index][capacity] =max(profit1,profit2)

        return dp[index][capacity]
    return knapsack(profits, weights, capacity, 0)


print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 7))
print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 6))
