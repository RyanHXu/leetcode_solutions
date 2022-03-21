

#%%


grid = """
["mobile","mouse","moneypot","monitor","mousepad"]


"""

print(grid.replace('[','{').replace(']','}').replace('"',"'").replace('\n','')+';')






#%% 
str= """
Minimum Deletions & Insertions to Transform a String into another
"""
print(str.lower().replace(' ','_'))

