def calculator(*elements, action="sum"):
    """function will perform calculation on the elements"""
    # 1. Perform sum by default
    if action == "sum":
        sum = 0
        for i in elements:
            sum += i
        return sum

    # 2. Perform product on demand
    elif action == "product":
        product = 1
        for i in elements:
            product *= i
        return product

    # 3. Else display error massage
    else:
        print("Invalid operation!")

# Make calculation
print("sum :", calculator(4, 2, 3))
print("product :", calculator(4, 2, 3, action="product"))
