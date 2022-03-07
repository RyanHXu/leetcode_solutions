from itertools import count


# https://leetcode.com/discuss/interview-question/873231/docasap-stage-online-group-division
def classGrouping(levels: list[int], k: int):
    levels.sort()
    count =1
    cur = levels[0]
    for val in levels:
        if val > cur + k:
            count +=1
            cur=val
            
            
    return count


levels = [1, 4, 7, 3, 4]
levels = [ 4, 4, 1, 8, 7]
maxSpread = 2


print(classGrouping([1,2,3,4,5],2))

            
    