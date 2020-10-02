import matplotlib.pyplot as plt


over = []
runs = [] 

# number of records which user wants to enter! 
records = int(input("Enter number of records : ")) 
  
# iterating till the range 
for i in range(0, records): 
    print(" Enter the Bowler Name")
    overs = str(input()) 
    over.append(overs) 
    # adding the elements
    
for i in range(0, records): 
    print("Enter the runs given by the bowler")
    run = int(input()) 
    runs.append(run)     


fig = plt.figure(figsize = (10, 5)) 

ax = fig.add_axes([0,0,1,1])
ax.bar(over,runs,color=['red','yellow'])
plt.ylabel("Runs")
plt.xlabel("Bowler")
plt.title("Bowling Scorecard")
plt.savefig("Result.jpeg")
plt.show()
