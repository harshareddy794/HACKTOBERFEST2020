import string
import random

if __name__ == "__main__": 
    set1 = string.ascii_lowercase
    # print(set1) 
    set2 = string.ascii_uppercase
    # print(set2) 
    set3 = string.digits
    # print(set3)
    set4 = string.punctuation
    # print(set4)
    
    pwd_len = int(input("Enter passward length\n"))
    
    s = []
    s.extend(list(set1))
    s.extend(list(set2))
    s.extend(list(set3))
    s.extend(list(set4))
    # print(s)
    
    random.shuffle(s)
    # print(s)
    
    print("Your password is: ")
    print("".join(s[0:pwd_len]))


    # another method 
    # print("".join(random.sample(s,pwd_len)))
