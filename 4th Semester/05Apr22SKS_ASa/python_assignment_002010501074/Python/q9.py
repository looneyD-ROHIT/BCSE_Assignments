
actual_list = [("hello", "maths", 67), ("world", "english", 45),
               ("hi", "science", 89), ("there", "commerce", 79)]

# print(zip(*actual_list))
max_list = list(map(max, zip(*actual_list)))
print(max_list)
min_list = list(map(min, zip(*actual_list)))
print(min_list)
