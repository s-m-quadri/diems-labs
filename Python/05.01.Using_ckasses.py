# sys for Command line interface
import sys

# //////////////////////////////////////////////////////////////////////////////////////////

# Class Massage
class massage:
    # A. Members
    name = ""
    age = 0

    # B. Constructor
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # C. Methods
    def greet(self):
        print("Hello Mr." + self.name + " ( DOB" , 2022-self.age , ") ! nice to meet your.")

# Class ABC as parent
class ABC:
    def __init__(self):
        print("This is constructor of ABC")
    def fun(self):
        print("This is funtion 'fun' of ABC")

# //////////////////////////////////////////////////////////////////////////////////////////

# Class XYZ as child
class XYZ(ABC):
    def __init__(self):
        print("This is constructor of XYZ")
        # whithin CHILD class METHODS:
            # Can call parent class 
            # 1. Constructor 
            # or/and
            # 2. Any method 
            # single/multiple times
            # e.g. super().fun()
            # e.g. super().__init__()
        super().__init__()
        super().fun()
   
    # Parent function will be replaced by this funtion
    def fun(self):
        print("This is funtion 'fun' of XYZ")
        
# //////////////////////////////////////////////////////////////////////////////////////////

# 1. If name and age is passed within command line arguments
if len(sys.argv) == 3:
    name = sys.argv[1]
    age = int(sys.argv[2])
    obj = massage(name, age)
    obj.greet()

# 2. If no argument is not passed in command line
elif len(sys.argv) == 1:  
    name = input("Enter your name: ")
    age = int(input("Enter your age: "))
    obj = massage(name, age)
    obj.greet()

# 3. Other wise exit the program
else:
    print("Error: invalid command line arguments!")
    print("Usage: ***.py name age")
    exit()

# Just for illustration of method overiding, inheritance,
# and parent constructor/method calling
obj = XYZ()
obj.fun()