def solve_knapsack(profits, weights, capacity):
    n = len(profits)
    
    if capacity<=0 or n ==0 or len(weights) !=n:
        return 0
    
    dp = [[0 for i in range(capacity+1)] for j in range(n)]
    
    for c in range(0,capacity+1):
        if weights[0] <=c:
            dp[0][c] = profits[0]
    
    for i in range(1,n):
        for c in range(1,capacity+1):
            p1,p2 =0,0
            # TODO: review it
            if weights[i] <= c:
                p1 = profits[i] + dp[i-1][c-weights[i]]
            p2 = dp[i-1][c]
            
            dp[i][c] = max(p1,p2)
            
    return dp[n-1][capacity] 


print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 7))
print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 6))

