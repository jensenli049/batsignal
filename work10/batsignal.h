#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h> 
#include <unistd.h>
#include <fcntl.h>

static void sighandler( int signo );

