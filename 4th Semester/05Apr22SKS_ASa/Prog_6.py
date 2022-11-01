import re
n = int(input("Enter the number of students"))
userData = []
for i in range(0, n):
    temp_Student_name = input("Enter student name: ")
    temp_Student_age = int(input("Enter student age: "))
    temp_Student_email = input("Enter student email: ")
    singleStudentData = (temp_Student_name, temp_Student_email, temp_Student_age)
    userData.insert(i, singleStudentData)


class NotUniqueUsernameException(Exception):
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return "Username (%s) already exists." % self.name


class NegativeAgeException(Exception):
    def __init__(self, age):
        self.age = age

    def __str__(self):
        return "Age (%d) cannot be negative." % self.age


class Under16Exception(Exception):
    def __init__(self, age):
        self.age = age

    def __str__(self):
        return "Age (%d) under 16." % self.age


class NotValidEmailException(Exception):
    def __init__(self, email):
        self.email = email

    def __str__(self):
        return "Email address (%s) is not valid email address" % self.email


userDirectory = {}

for username, email, age in userData:
    try:
        if username in userDirectory:
            raise NotUniqueUsernameException(username)
        if age <= 0:
            raise NegativeAgeException(age)
        if age < 16:
            raise Under16Exception(age)
        x = re.search("^(\w|\.|\_|\-)+[@](\w|\_|\-|\.)+[.]\w{2,3}$", email)
        if x == None:
            raise NotValidEmailException(email)
        userDirectory[username] = email
    except Exception as e:
        print(e, end = " ")
        print("Username (%s) not stored" % username)
    else:
        print("Username:%s stored" % username);
print ("Directory -->")
print (userDirectory)
