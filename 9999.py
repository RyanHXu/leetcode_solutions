

#%%


grid = """
[[1,4],[2,4],[3,1],[3,2]]



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
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


'''

res = ''''
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

'''

formatted_msg= str2.replace(' * ', '').replace('/**', '').replace('*/','')

idx = formatted_msg.find('Definition')

print(formatted_msg[:idx]+'// '+formatted_msg[idx:])











