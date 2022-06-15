# Task
x = int(input("Enter the number: "))
for i in range(x):
    print("* " * (i+1))
print()
for i in range(x):
    print("* " * (x-i))