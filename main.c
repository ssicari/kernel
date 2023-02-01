#include<stdio.h>
#include<unistd.h>
#include<err.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	char cwd[1024];
	char* buf = NULL;
	size_t buf_size = 1024;
	size_t line;

	if((getcwd(cwd, 1024)) == NULL)
	   {
	      err(1, "Error: getcwd returned NULL\n");
	   }
	printf("[%s]$ ", (getcwd(buf, 1024)));

	while((line = getline(&buf, &buf_size, stdin) != EOF))
	   {
	      //printf("You typed: %s", buf);
	      if(buf[0] != '\n')
	         {
		    printf("Unrecognized Command\n");
		 }
	      printf("[%s]$ ", (getcwd(buf, 1024)));
	   }


	free(buf);
	printf("\n");
	exit(0);
}
