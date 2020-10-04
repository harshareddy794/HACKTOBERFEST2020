#The below program is an optimized method for converting the integers to their English representations.
''' For example:
>>>Enter a number34
   thirty four
   For this conversion ,a package named n2w is used.If the package is not installed in your local machine,install it using the command :
   >>>pip install n2w
'''
def int2word(integer):    # A function is defined that will take integer value as an argument and will return the String output 
    return n2w.convert(num)
if __name__ == "__main__":
    import n2w   # the package n2w is imported for performing the number to word calculation
    num=input("Enter a number:")   # A number is taken as input from the user
    print(int2word(num))
