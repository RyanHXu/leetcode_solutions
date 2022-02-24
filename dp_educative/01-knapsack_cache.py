

from functools import cache


def solve_knapsack(profits, weights, capacity):

    @cache
    def knapsack(profits, weights, capacity, index=0):
        if capacity <= 0 or index > len(profits)-1:
            return 0
        profit1 = profit2 = 0
        if weights[index] <= capacity:
            profit1 = profits[index] + \
                knapsack(profits, weights, capacity-weights[index], index+1)

        profit2 = knapsack(profits, weights, capacity, index+1)

        return max(profit1, profit2)
    return knapsack(profits, weights, capacity, 0)


print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 7))
print(solve_knapsack(tuple([1, 6, 10, 16]), tuple([1, 2, 3, 5]), 6))

# test cache performance
profits = (804, 982, 475, 766, 715, 101, 552, 835, 476, 821, 707, 459, 2, 800, 500, 526, 33, 988, 922, 688, 249, 561, 544, 131, 484, 431, 91, 936, 676, 527, 985, 491, 314, 989, 238, 12, 174, 757, 18, 649, 268, 455, 22, 796, 30, 431, 465, 581, 479, 949, 785,
           934, 826, 36, 708, 350, 203, 966, 464, 569, 825, 536, 592, 729, 131, 33, 92, 963, 734, 556, 556, 966, 872, 956, 908, 229, 300, 4, 791, 681, 284, 795, 190, 157, 366, 217, 76, 708, 602, 535, 463, 811, 62, 943, 87, 613, 226, 978, 122, 549)

weights = (419, 351, 873, 141, 564, 494, 662, 912, 532, 573, 700, 22, 716, 592, 743, 753, 847, 680, 925, 230, 782, 843, 412, 133, 764, 461, 843, 768, 123, 525, 159, 2, 877, 570, 814, 157, 381, 919, 203, 980, 988, 990, 371, 773, 435, 332, 918, 973, 294,
           955, 126, 988, 505, 319, 592, 256, 396, 544, 133, 304, 110, 891, 8, 525, 811, 946, 771, 669, 37, 474, 947, 486, 103, 300, 967, 854, 992, 68, 580, 692, 929, 836, 743, 120, 134, 602, 469, 101, 842, 135, 810, 225, 819, 546, 206, 157, 503, 265, 697, 194)

capacity = 20000
# capacity = 200
print(solve_knapsack(profits, weights, capacity))
