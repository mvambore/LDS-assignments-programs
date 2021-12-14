#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <string.h>

int main(void) {

  int pid, cpid;

  char string1[20];
  int i, length;
  int flag = 0;

  int pipefds[2];
  char buffer[3];

  char * pal = "30\0";
  char * npal = "43\0";

  printf("Enter a string:");
  scanf("%s", string1);

  if (pipe(pipefds) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid = fork();

  if (pid == 0) { // in child process
    printf("\nChild process, PPID:%d, PID:%d\n", getppid(), getpid());

    length = strlen(string1);

    for (i = 0; i < length; i++) {
      if (string1[i] != string1[length - i - 1]) {
        flag = 1;
        break;
      } // end if
    } // end for

    if (flag) {
      printf("%s is not a palindrome\n", string1);
      write(pipefds[1], npal, 3);

      //exit(EXIT_SUCCESS);
    } else {
      printf("%s is a palindrome\n", string1);
      write(pipefds[1], pal, 3);

      //exit(EXIT_SUCCESS);
    }

  } else { // in main process

    close(pipefds[1]); // close write fd
    read(pipefds[0], buffer, 5); // read PIN from pipe
    printf("\nParent process, PID:%d\n", getpid());
    printf("Parent received status as %s\n", buffer);
    close(pipefds[0]); // close read fd
  }

  return EXIT_SUCCESS;
}
