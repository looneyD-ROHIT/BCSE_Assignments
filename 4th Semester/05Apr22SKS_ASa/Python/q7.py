
import glob
import os.path as path
root_dir = input("Enter the directory name to search for:")
if path.isfile(root_dir):
    print("The given name is a file")
elif path.isdir(root_dir):
    for filename in glob.iglob(root_dir + '/**', recursive=True):
        print(filename)
else:
    print("The given name doesn't exist in working directory")
