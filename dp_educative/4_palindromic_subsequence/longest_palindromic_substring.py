def find_LPS_length(st):
    n = len(st)

    def find_LPS_length_recursive(st, l, r):
        if l>r:
            return 0
        if l==r:
            return 1
        if st[l] == st[r]:
            length = r-l-1
            if length == find_LPS_length_recursive(st,l+1,r-1):
                return length+2
        
        c1 = find_LPS_length_recursive(st,l+1,r)
        c2 =find_LPS_length_recursive(st,l,r-1)
        
        return max(c1,c2)

    return find_LPS_length_recursive(st, 0, n-1)


# abcdcba
print(find_LPS_length("abcdcba"))
print(find_LPS_length("abdbca"))
print(find_LPS_length("cddpd"))
print(find_LPS_length("pqr"))


