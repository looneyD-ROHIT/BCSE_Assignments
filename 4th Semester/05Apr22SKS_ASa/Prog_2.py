from calendar import day_name as day_list
dict = {}
i = 0
for day in day_list:
    dict[day] = round(float(i * 2.4), 2)
    i+=1
print(dict)
