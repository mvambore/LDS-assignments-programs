#include <stdio.h>    // printf, scanf              
#include <stdlib.h>   // exit                
#include <unistd.h>   // fork, getpid
#include <sys/wait.h> // wait                
#include<dirent.h>

int main() {
  	  	  
  	int pid, cpid;
  	
	cpid = fork(); // child process creation
	
	if (cpid == 0) { /* child process is always 0 */
	
		printf("\nChild process, PPID:%d, PID:%d\n", getppid(), getpid());
		printf("Calling exec()\n");
		
		char *args[]={"./exec",NULL};
        	execvp(args[0],args);
	    
	} // end if
	
	else { /* parent process is non-zero (child's pid) */
	
		printf("\nParent process, PID:%d", pid);
		
		FILE *file;
    
	    	if (file = fopen("file.txt", "r")) {
	    	
			fclose(file);
			printf("file exists");
	    	} // end if
	    	else
	    		printf("file doesn't exist");
	} // end else
	
	return 0;
} // end main
