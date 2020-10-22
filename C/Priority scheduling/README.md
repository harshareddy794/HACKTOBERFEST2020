# Priority based Scheduling (Non - Preemptive) in C

TIME COMPLEXITY : O(n^2)

SPACE COMPLEXITY : O(n)

Description : To calculate the average waiting time using the priority queue algorithm. First sort
the processes in ascending order of their priority time and the process having the shortest priority
time is executed first and so on. Waiting time of the first process is kept zero and the waiting time of the second process is the burst time of the first process and the waiting time of the third process is the sum of the burst time of the first and the second process and so on. After calculating all the waiting times the average waiting time is calculated as the average of all the waiting times.