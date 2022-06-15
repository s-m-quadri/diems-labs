def get_sum(a, b):
    """function will sum the element"""
    # 1. Ensure the type and id's
    print("  a is of", type(a), "having id", id(a), ".")
    print("  b is of", type(b), "having id", id(b), ".")

    # 2. Perform sum after swaping
    c = a
    a = b
    b = c
    sum = a + b

    # 3. Ensure the type and id's
    print("  a is of", type(a), "having id", id(a), ".")
    print("  b is of", type(b), "having id", id(b), ".")

    # 4. Ensure the type and id's
    return sum
    
# 1. Get the input
x = int(input("x : "))
y = int(input("y : "))

# 2. Ensure the type and id's
print("x is of", type(x), "having id", id(x), ".")
print("y is of", type(y), "having id", id(y), ".")

# 3. Calculation sum
print("Sum is :", get_sum(x,y))

# 4. Ensure for changes (but aren't!)
print("still x:", x, "and y:", y)