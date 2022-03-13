from pprint import pprint


def solve_knapsack(profits, weights, capacity):
    n = len(profits)
    if capacity <= 0 or n == 0 or len(weights) != n:
        return 0

    dp = [0 for i in range(capacity+1)]

    for c in range(0, capacity+1):
        if weights[0] <= c:
            dp[c] = profits[0]

    for i in range(1, n):
        for j in range(capacity, -1, -1):
            if weights[i] <= j:
                dp[j] = max(dp[j], profits[i] + dp[j-weights[i]])
    return dp[capacity]


print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 7))
print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 6))
