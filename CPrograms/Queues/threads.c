/*
Shankar is a diligent, hardworking IT professional working for a reputed Software concern. He sets clear targets to achieve his tasks and is strongly committed to attain it. Shankar's Boss has assigned him with a new, most vital project of the quarter related to Banking services and it has N processes in it. All the processes have a unique number assigned to them from 1 to N.

 
He is given two things:

The calling order in which all the processes are called.

The ideal order in which all the processes should have been executed.

 
Now, let us demonstrate this by an example. Let's say that there are 3 processes, the calling order of the processes is: 3 - 2 - 1. The ideal order is: 1 - 3 - 2, i.e., process number 3 will only be executed after process number 1 has been completed; process number 2 will only be executed after process number 3 has been executed.

 
Iteration #1: Since the ideal order has process #1 to be executed firstly, the calling ordered is changed, i.e., the first element has to be pushed to the last place. Changing the position of the element takes 1 unit of time. The new calling order is: 2 - 1 - 3. Time taken in step #1: 1.

Iteration #2: Since the ideal order has process #1 to be executed firstly, the calling ordered has to be changed again, i.e., the first element has to be pushed to the last place. The new calling order is: 1 - 3 - 2. Time taken in step #2: 1.

Iteration #3: Since the first element of the calling order is same as the ideal order, that process will be executed. And it will be thus popped out. Time taken in step #3: 1.

Iteration #4: Since the new first element of the calling order is same as the ideal order, that process will be executed. Time taken in step #4: 1.

Iteration #5: Since the last element of the calling order is same as the ideal order, that process will be executed. Time taken in step #5: 1.

 
Total time taken: 5 units.

Note: Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

 
Shankar's initial task in the project is to estimate the total time taken for the entire queue of processes to be executed. Can you help him on the same?

 
Input format:
The first line of the input is an integer N, denoting the number of processes; 1<=N<=100.

The second line contains the calling order of the processes.

The third line contains the ideal order of the processes.

 
Output format:
Print the total time taken for the entire queue of processes to be executed.

Refer sample input and output for formatting specifications.
*/
#include<stdio.h>

int main()
{
	int count, i, f, r;
	scanf("%d", &count);
	int calling[count], ideal[count], time = 0;
	for (i = 0; i < count; i++) scanf("%d", &calling[i]);
	for (i = 0; i < count; i++) scanf("%d", &ideal[i]);
	f = 0; r = count - 1;
	while (f < count) {
	    if (calling[f] == ideal[f]) {
	        time++;
	        f++;
	    }
	    else {
	        r = calling[f];
	        for (i = f + 1; i < count; i++) calling[i - 1] = calling[i];
	        calling[count - 1] = r;
	        time++;
	    }
	}
	printf("%d", time);
	return 0;
}
