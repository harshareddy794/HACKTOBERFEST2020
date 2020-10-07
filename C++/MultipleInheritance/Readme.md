***INHERITANCE

The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important feature of Object Oriented Programming.

***MULTIPLE INHERITANCE

Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes. i.e one sub class is inherited from more than one base classes.



***QUESTION :


You need to modify the class D and implement the function update_val which sets D's val to new_val by manipulating the value by only calling the func defined in classes A, B and C.
It is guaranteed that new_val has only  and  as its prime factors.
Input Format
Implement class D's function update_val. This function should update D's val only by calling A, B and C's func.
Constraints
 new_val 
Note: The new_val only has  and  as its prime factors.
Sample Input
new_val 
Sample Output
A's func will be called once.
B's func will be called once.
C's func will be called once.
Explanation
Initially, val .
A's func is called once:
val = val*2  
val = 2
B's func is called once:
val = val*3
val = 6
C's func is called once:
val = val*5
val = 30
