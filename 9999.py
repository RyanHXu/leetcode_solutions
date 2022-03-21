

#%%


grid = """
["mobile","mouse","moneypot","monitor","mousepad"]


"""

print(grid.replace('[','{').replace(']','}').replace('"',"'").replace('\n','')+';')






#%% 
str= """
Minimum White Tiles After Covering With Carpets
"""
print(str.lower().replace(' ','_'))

