
from functools import cache, lru_cache


def solve_knapsack(profits, weights, capacity):
    def knapsack_recursive(profits, weights, capacity, currIndex=0):
        if capacity <= 0 or currIndex > len(profits)-1:
            return 0

        profit1 = profit2 = 0
        if weights[currIndex] <= capacity:
            profit1 = profits[currIndex] + knapsack_recursive(
                profits, weights, capacity-weights[currIndex], currIndex+1)

        profit2 = knapsack_recursive(profits, weights, capacity, currIndex+1)

        return max(profit1, profit2)

    return knapsack_recursive(profits, weights, capacity)


print(solve_knapsack([15, 20, 50], [1, 2, 3], 5))
print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 8))
print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 6))
