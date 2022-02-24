
from functools import cache, lru_cache
from typing import List
import time
from typing_extensions import Self


def solve_knapsack(profits, weights, capacity):
    def knapsack_recursive(profits: List[int], weights: List[int], capacity: int, currentIndex: int):
        if capacity <= 0 or currentIndex > len(profits)-1:
            return 0

        profit1 = profit2 = 0
        if weights[currentIndex] <= capacity:
            profit1 = profits[currentIndex] + \
                knapsack_recursive(profits, weights,
                                capacity - weights[currentIndex], currentIndex+1)

        profit2 = knapsack_recursive(profits, weights, capacity, currentIndex+1)

        return max(profit1, profit2)
    return knapsack_recursive(profits, weights, capacity, 0)


def main():
    print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 7))
    print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 6))


main()

