

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


'''


formatted_msg= str2.replace(' * ', '').replace('/**', '').replace('*/','')

idx = formatted_msg.find('Definition')

print(formatted_msg[:idx]+'// '+formatted_msg[idx:])










