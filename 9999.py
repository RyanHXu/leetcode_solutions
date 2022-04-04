

#%%


grid = """
[[0,1,2,0],[3,4,5,2],[1,3,1,5]]



"""

print(grid.replace('[','{').replace(']','}').replace('"',"'").replace('\n','')+';')






#%% 
str= """
Closest Points to the Origin 
"""
print(str.lower().replace(' ','_'))





# %%
str2 = '''
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

'''


formatted_msg= str2.replace(' * ', '').replace('/**', '').replace('*/','')

idx = formatted_msg.find('Definition')

print(formatted_msg[:idx]+'// '+formatted_msg[idx:])





