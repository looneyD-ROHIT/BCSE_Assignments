import re

phone_number = input("Enter phone number: ")
x = re.search("^((\+91|0)?[6-9]{1}\d{9}){1}$", phone_number)
if x == None:
    print("Not a valid phone number.")
else:
    print("Is a valid phone number")
