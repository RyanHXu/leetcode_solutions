class Solution:
    def countEven(self, num: int) -> int:
        count = 0

        def digitSum(n: int):
            if n >= 10:
                res = 0
                while n > 0:
                    res += n % 10
                    n //= 10
                return res
            else:
                return n
        
        for i in range(2, num+1):
            if digitSum(i)%2 ==0:
                count +=1
                
        return count


s = Solution()
print(s.countEven(4))
print(s.countEven(30))

print(s.countEven(2))
