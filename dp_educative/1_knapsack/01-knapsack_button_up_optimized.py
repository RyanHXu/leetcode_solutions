from pprint import pprint


def solve_knapsack(profits, weights, capacity):
    n = len(profits)
    if capacity <= 0 or n == 0 or len(weights) != n:
        return 0

    dp =[0 for i in range(capacity+1)]
    # if we have only one weight, we will take it if it is not more than the capacity
    for c in range(0, capacity+1):
        if weights[0] <=c:
            dp[c] = profits[0]
    pprint(dp)

    for i in range(1, n):
        for j in range(capacity,-1,-1):
            p1, p2 = 0, 0
            # include the item, if it is not more the capacity
            if weights[i] <= j:
                p1 = profits[i] + dp[j-weights[i]]
            # exclude the item
            p2 = dp[j]
            # take the maximum
            dp[j] = max(p1, p2)
    return dp[capacity]


print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 7))
print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 6))
