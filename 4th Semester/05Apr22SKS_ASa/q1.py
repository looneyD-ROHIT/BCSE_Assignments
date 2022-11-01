# from re import X
# from cv2 import sqrt


x = 0


def isPrime(x):
    if(x == 1):
        return False
    for j in range(2, x):
        if x % j == 0:
            return False
    return True


i = 1

if __name__ == "__main__":

    x = int(input("Enter the number:"))

    if(isPrime(x)):
        i=1
        while(i<=x):
            if(isPrime(i)):
                   
                print(i)
            i+=1

    else:
        print("Entered number not a prime")
