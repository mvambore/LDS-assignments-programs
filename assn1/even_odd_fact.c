#include <stdio.h>    // printf, scanf              
#include <stdlib.h>   // exit                
#include <unistd.h>   // fork, getpid
#include <sys/wait.h> // wait                

int main() {
  
	int pid, cpid, num, fact=1;
	
	pid = getpid();	  
	printf("Enter a Number: ");
	scanf("%d", &num);
	  
	  
	cpid = fork();
	
	if (cpid == 0) { /* child process is always 0 */
	
		printf("\nCalculation in child process, PPID:%d, PID:%d", getppid(), getpid());
		if(num < 0)
		printf("\nFactorial of %d cannot be found\n", num);
		  
		else {
		  	
			for(int i = 1; i <= num ; i++)
				fact *= i;
			

		  	printf("\nFactorial of %d = %d\n", num, fact);
		} // end else
		//exit(0);
				
	} // end if
	else { /* parent process is non-zero (child's pid) */
	
		printf("\nCalculation in parent process, PID:%d", pid);
		
		if(num % 2 == 0)
			printf("\n%d is even.\n", num);
		else
			printf("\n%d is odd.\n", num);
		wait(NULL);	
		//fork();
	} // end else
	
	return 0;
} // end main
