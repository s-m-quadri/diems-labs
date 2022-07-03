# Demo: Using nested for loop
for i in range(10):             # 1st loop
    print(i, " *** (", end=" ") # i of 1st loop or reverted to it!
    for i in range(3):          # i is converted with 2nd loop 
        print(i, end=" ")       # i of second loop
    print(") *** ", i)          # i of second loop only