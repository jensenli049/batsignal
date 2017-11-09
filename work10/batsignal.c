#include "batsignal.h"

int main(){			  
  signal( SIGINT, sighandler );
  signal( SIGUSR1, sighandler );
  while(1){
    printf("Current PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}

static void sighandler( int signo ){
  if( signo == SIGINT){
    printf("READ exit.txt\n");
    int fd = open("exit.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char ans[32];
    sprintf(ans,"I’ve been interrupted by SIGINT, how rude!\n");
    if (write(fd, ans, strlen(ans)) == -1) {
      printf("errno: %d, %s\n", errno, strerror(errno));
      exit(1);
    }
    exit(0);
    close(fd);
  }
  if( signo == SIGUSR1 )
    printf("Parent PID: %d\n", getppid());
}
