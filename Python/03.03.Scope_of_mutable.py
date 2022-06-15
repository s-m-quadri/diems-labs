def change(a):
    """function will sum the element"""
    # 1. Ensure the type and id's
    print("  a is of", type(a), "having id", id(a), ".")

    # 2. Perform change
    a[0]=100

    # 3. Ensure the type and id's
    print("  a is of", type(a), "having id", id(a), ".")
    
# 1. Get the input
sample_list = [int(input("x : "))]
sample_list += [int(input("next : "))]
sample_list += [int(input("next : "))]

# 2. Ensure the type and id's and list
print("sample_list is of", type(sample_list), "having id", id(sample_list), ".")
print("sample_list is :", sample_list)

# 3. Make changes
change(sample_list)

# 4. Ensure the type and id's and list
print("sample_list is :", sample_list)
print("sample_list is of", type(sample_list), "having id", id(sample_list), ".")