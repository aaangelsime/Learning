import os
import keyboard

## clears terminal function YAY!
def clear_terminal():
    os.system('cls' if os.name == 'nt' else 'clear')

def clear_ah(e):
    # checks if the pressed key is space
    if e.name == 'space':
        os.system('clear')

clear_terminal()

# Opens and prints welcome file!
with open("welcome.txt", "r") as file:
    content = file.read()
    print(content)

## end="" prevents a new line, Yay!
print("Enter First Name: ", end="")
first_name = (input())

print("Enter Last Name: ", end="")
last_name = (input())

full_name = first_name + " " + last_name

print("First Name: ", first_name, )
print("Last Name: ", last_name)
print("Full Name: ", full_name)
print()

print(type(full_name))
print("Length of name: ", end="")
print((len(full_name)) - 1)
