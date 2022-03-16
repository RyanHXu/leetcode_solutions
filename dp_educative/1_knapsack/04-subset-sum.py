from typing import List

# TODO: 
def can_partition(num:List[int], sum:int):
    n = len(num)
    table = [False for i in range(sum+1)]
    table[0] = True
    for j in range(1,sum+1):
        table[j] = num[0] == j
    print(table)
    

print("Can partition: " + str(can_partition([1, 2, 3, 7], 6)))
print("Can partition: " + str(can_partition([1, 2, 7, 1, 5], 10)))
print("Can partition: " + str(can_partition([1, 3, 4, 8], 6)))
