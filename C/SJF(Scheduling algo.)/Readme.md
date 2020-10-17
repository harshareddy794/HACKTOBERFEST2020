## **Shortest Job First Scheduling Algorithm (SJF - Non-Preemptive) in C**

Time Complexity : O(n^2)

Space Complexity : O(n)

Description : To calculate the average waiting time using the SJF(Non- Preemption)
algorithm. First sort the processes in ascending order of their burst time and the process having
the shortest burst time is executed first and so on. Second waiting time of the first process is kept
zero and the waiting time of the second process is the burst time of the first process and the
waiting time of the third process is the sum of the burst time of the first and the second process
and so on. After calculating all the waiting times the average waiting time is calculated as the
average of all the waiting times. SJF mainly says shortest job first the algorithm. 