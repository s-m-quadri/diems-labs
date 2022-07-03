# By 5MQuadr! (s-m-quadri@github , CSE-SY@diems2020-24)
# Last Updated on : 15th April 2022


# Variables in Python
'''
RULES:
1. Must consists of only alpha-numeric (including underscore).
2. Must not start with numeric.
'''
_Var = 10
_ = 20
Var = 30
print("_Var = " + str(_Var))
print("_ = " + str(_))
print("Var = " + str(Var))

""" Type of data and range"""
a = 9999999999999999999999999999999999999999999999999999999999999999
print(a)
print(a + 1)
print(type(a))

"""
Standard data types

1. Immutable data type
  * Numeric
  * String
  * Tuples - collection of ordered set of elements
  
2. Mutable data type
  * List
  * Dictionary
  * Set - list of unique elements
"""

'''
Illutration: Numbers are immutable
'''
# Assign a to 5
a = 5
print(a)
print(id(a))

# Assign a to 10
a = 10
print(a)
print(id(a))

# Assign a to "DIEMS"
a = "DIEMS"
print(a)
print(id(a))

"""
Illutration: Using diffrent data types
"""

# Using tuples
my_tuple = ("Ubaid" , 34 , 99.00 , 45 + 3j)
print(my_tuple)


# Using List
my_list = ["Vaibhav" , 56 , 99.00 , 43 + 34j]
print(my_list)

# Using Dictionary
my_dict = {"Name" : "Xyz",
           "Roll" : 34,
           "Collage" : "DIEMS"}
print(type(my_dict))
print(my_dict)

# Using Sets
my_set = {"Abcd", "Abcd" , 1 , 2 , 4 , 2 , 3 , 1}
print(my_set)

"""
Getting Keyword and help
"""

# Display keywords in python
import keyword
print(keyword.kwlist)

# Get Help (uncomment below)
# help(print)
# print?
