import random
coupons={
    "Monday" : "10%",
    "Tuesday" : "13%",
    "Wednesday" : "20%",
    "Thursday" : "30%",
    "Friday" : " 33%",
    "Saturday" : "50%",
    "Sunday" : "44%",
}
p="Monday Tuesday Wednesday Thursday Friday Saturday Sunday"
s= input("Enter a day to search the discount rate")

if(s!="Monday" and s!="Tuesday" and s!="Wednesday" and s!="Thursday" and s!="Friday" and s!="Saturday" and s!="Sunday"):
    print("error!! Enter a proper day")
else:
    print(s+ "  "+coupons[s])

# keys= list(coupons.keys())
# m=random.choice(keys)

# print(m +"  "+ coupons[m]) 
