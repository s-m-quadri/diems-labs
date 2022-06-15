# /////////////////////////////////////////////////////////////////////////////
# Exception Handling - block 1
# /////////////////////////////////////////////////////////////////////////////
print("/// Try block onwards ///")
try:
    a = int(input("a : "))
    b = int(input("b : "))
    c = a / b
    print("c: " , c)
    with open("sample.txt", "w") as sample_file:
        sample_file.write("Hi")
    with open("sample.txt", "r") as sample_file:
        print(sample_file.read())

# Exception Condition
except ZeroDivisionError:
    print("Sorry! Can't divide by zero.")
except FileNotFoundError:
    print("Sorry! File dosn't exist.")
except Exception as err_massage:
    print("Sorry! Something went wrong,")
    print("error : ", err_massage)

# Non-exception condition
else:
    print("Hmmm! Not a single error...")

# Both condition
finally:
    print("try block is about to exit!")

# /////////////////////////////////////////////////////////////////////////////
# Exception Handling - block 2
# /////////////////////////////////////////////////////////////////////////////
class Aurangabad(Exception):
    def __init__(self, value = 200):
        self.value = value
    def getStatus(self):
        return "a few"

print("/// Try block onwards ///")
try:
    raise(Aurangabad)
except Aurangabad as obj:
    print("Aurangabad is ", obj.value, "km onwards.")
    print("Aurangabad is ", obj.getStatus(), "km onwards.")

class Parbhani(Exception):
    pass
raise(Parbhani)
