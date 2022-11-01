# Print first 10 odd and even numbers using iterators and compress. You can use duck typing.

def printOddEven(x):
    for i in range(x, x+11):
        if(i%2==0):
            print(i,"even")
        else:
            print(i,"odd")

if __name__=='__main__':
    x=int(input("Enter the number:"))
    printOddEven(x)