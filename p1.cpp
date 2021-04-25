#include <stdlib.h> 
#include <iostream> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
sig_atomic_t sigusr1_count = 0;
void handler (int signal_number) //signal handler
{
++sigusr1_count;
}
int spawn (char* program, char** arg_list) 
{ 
pid_t child_pid1; 
/* Duplicate this process. */ 
child_pid1 = fork (); 
if (child_pid1 != 0) 
/* This is the parent process. */ 
return child_pid1; 
else { 
/* Now execute PROGRAM, searching for it in the path. */ 
for (i=0;i<12;i++)
{
execvp (program, arg_list); 
sleep(1);
}
/* The execvp function returns only if an error occurs. */ 
fprintf (stderr, "an error occurred in execvp\n"); 
abort (); 
} 

pid_t child_pid2; 
/* Duplicate this process. */ 
child_pid2 = fork (); 
if (child_pid2 != 0) 
/* This is the parent process. */ 
return child_pid2; 
else { 
/* Now execute PROGRAM, searching for it in the path. */ 
for(int i=0;i<60;i++)
	sleep(1)
execvp (program, arg_list); 
/* The execvp function returns only if an error occurs. */ 
fprintf (stderr, "an error occurred in execvp\n"); 
abort (); 
} 

pid_t child_pid3; 
/* Duplicate this process. */ 
child_pid3 = fork (); 
if (child_pid3 != 0) 
/* This is the parent process. */ 
return child_pid3; 
else { 
/* Now execute PROGRAM, searching for it in the path. */ 
execvp (program, arg_list); 
/* The execvp function returns only if an error occurs. */ 
fprintf (stderr, "an error occurred in execvp\n"); 
abort (); 
} 
} 

int main () 
{ 
int child_status, i;
char* arg_list[] = {
(char *)"whoami",
NULL
};



spawn ((char *)"whoami", arg_list);

wait (&child_status);
if (WIFEXITED (child_status)) 
printf ("the child process exited normally, with exit code %d\n", 
WEXITSTATUS (child_status)); 
else 
printf ("the child process exited abnormally\n"); 
return 0; 
} 
