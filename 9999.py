

#%%


grid = """
["mobile","mouse","moneypot","monitor","mousepad"]


"""

print(grid.replace('[','{').replace(']','}').replace('"',"'").replace('\n','')+';')






#%% 
str= """
Longest Palindromic Subsequence
Longest Palindromic Substring
Count of Palindromic Substrings
Minimum Deletions in a String to make it a Palindrome
Palindromic Partitioning
"""
print(str.lower().replace(' ','_'))

