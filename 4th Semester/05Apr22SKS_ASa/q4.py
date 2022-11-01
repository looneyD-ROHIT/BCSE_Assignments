import re
  
def isValid(s):
      
    # 1) Begins with 0 or 91
    # 2) Then contains 7 or 8 or 9.
    # 3) Then contains 10 digits after 91 or 0
    Pattern = re.compile("^(0|91)?[6-9][0-9]{9}$")
    return Pattern.match(s)
  
# Driver Code
s=input("Enter a number")

if (isValid(s)): 
    print ("Valid Number")     
else :
    print ("Invalid Number") 