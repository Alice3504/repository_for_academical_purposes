#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void handler_dividebyzero(int signum);

int main() {
   int result;
   int v1, v2;
   char v3;
   int pid;
   void (*sigHandlerReturn)(int);
   sigHandlerReturn=signal(SIGFPE, handler_dividebyzero);
   if (sigHandlerReturn == SIG_ERR) {
      perror("Signal Error: ");
      return 1;
   }
   v1 = 121;
   v2 = 0;
   v3 = 'Q';
   
   pid = fork();
   if (pid == 0)
   {
	   result = v1/v2;
	   printf("Result of Divide by Zero is %d\n", result);
	   return 0;
   }
   else
   {
	   sleep(1);
	   result = v1/v3;
	   printf("Result of Divide by Char is %d\n", result);
	   return 0;
   }
}

void handler_dividebyzero(int signum) {
   if (signum == SIGFPE) {
      printf("Received SIGFPE, Divide by Zero Exception\n");
      exit (0);
   } 
   else
      printf("Received %d Signal\n", signum);
      return;
}
