import abc


def find_LCS_length(s1, s2):
    def find_LCS_length_recursive(s1,s2,i1,i2,count=0):
        if i1==len(s1) or i2==len(s2):
            return count

        if s1[i1] == s2[i2]:
            count=find_LCS_length_recursive(s1,s2,i1+1,i2+1,count+1)
            
        c1 = find_LCS_length_recursive(s1,s2,i1,i2+1,0)
        c2 = find_LCS_length_recursive(s1,s2,i1+1,i2,0)
        return max(count,max(c1,c2))
    return find_LCS_length_recursive(s1,s2,0,0)


print(find_LCS_length("abdca", "cbda"))
print(find_LCS_length("passport", "ppsspt"))
print(find_LCS_length("abcdeab", "abcdkab"))
print(find_LCS_length("glllgl", "llllg"))


