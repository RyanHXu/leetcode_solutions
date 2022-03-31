import abc


def find_LCS_length(s1, s2):
    def find_LCS_length_recursive(s1, s2, i1, i2):
        if len(s1) == i1 or len(s2) == i2:
            return 0

        if s1[i1] == s2[i2]:
            return 1 + find_LCS_length_recursive(s1, s2, i1+1, i2+1)

        c1 = find_LCS_length_recursive(s1, s2, i1, i2+1)
        c2 = find_LCS_length_recursive(s1, s2, i1+1, i2)

        return max(c1, c2)
    return find_LCS_length_recursive(s1,s2,0,0)

print(find_LCS_length("abdca", "cbda"))
print(find_LCS_length("passport", "ppsspt"))
print(find_LCS_length("abcdeab", "abcdkab"))
print(find_LCS_length("glllgl", "llllg"))


