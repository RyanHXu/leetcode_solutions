


from collections import defaultdict




dic = {'name': 'Reintro', 'age': '21', 'country': 'Korea'}

print(dic)

for key,value in dic.items():
    print(key,value)
    
    
    
default_dic = defaultdict()
default_dic ={'name': 'Reintro', 'age': '21', 'country': 'Korea'}

# equal to 
# for key in default_dic.keys():
for key in default_dic:
    print(key)