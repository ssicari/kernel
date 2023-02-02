#include<stdio.h>
#include<unistd.h>
#include<err.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int manipulate_input(char* buf, char new_buf[][1024]);
void exit_handle(char new_buf[][1024], int arg_counter);
void cd_handle(char new_buf[][1024], int arg_counter);
void exec_handle(char new_buf[][1024]);

int main(int argc, char* argv[])
{
	char cwd[1024];
	char* buf = NULL;
	char new_buf[1024][1024];
	size_t buf_size = 1024;
	size_t line;
	int arg_counter = 0;

	if((getcwd(cwd, 1024)) == NULL)
	   {
	      err(1, "Error: getcwd returned NULL\n");
	   }
	printf("[%s]$ ", (getcwd(buf, 1024)));

	while((line = getline(&buf, &buf_size, stdin) != EOF))
	   {
	      //printf("You typed: %s", buf);
	      arg_counter = manipulate_input(buf, new_buf);
	      if(!(strcmp(new_buf[0], "exit")))
		{
		   exit_handle(new_buf, arg_counter);
		}
	      else if(!(strcmp(new_buf[0], "cd")))
		{
		   cd_handle(new_buf, arg_counter);
		}
	      else if(!(strcmp(new_buf[0], "exec")))
		{
		   exec_handle(new_buf);
		}
	      else if(buf[0] != '\n')
	         {
		    printf("Unrecognized Command: %s\n", new_buf[0]);
		 }
	      printf("[%s]$ ", (getcwd(buf, 1024)));
	   }


	free(buf);
	printf("\n");
	exit(0);
}

int manipulate_input(char* buf, char new_buf[][1024])
{
	int j =0;
	int word = 0;

	for(int i = 0; i < strlen(buf); i++)
	   {
	      if(isspace(buf[i]))
		{
		   new_buf[word][j] = '\0';
		   word++;
		   j = 0;
		}
	      else
		{
		   new_buf[word][j] = buf[i];
		   j++;
		}
	   }
	return word;
}
void exit_handle(char new_buf[][1024], int arg_counter)
{
	if(arg_counter > 1)
	 {
	   err(1, "Exit takes no arguments\n");
	 }
	exit(0);
}
void cd_handle(char new_buf[][1024], int arg_counter)
{
	if(arg_counter != 2)
	 {
	   err(1, "cd: too many arguements\n");
	 }
	if((chdir(new_buf[1])))
	 {
	   err(1, "cd: No such file or directory\n");
	 }
}
void exec_handle(char new_buf[][1024])
{
	/*char* args[1024*1024];
	int k = 0;
	for(int i = 0; i < 1024; i++)
	 {
	   for(int j = 0; j < 1024; j++)
	    {
	      *(args[k]) = new_buf[i][j];
	      k++;
	    }
	 }
	if((execv(args[0], args)))
	 {
	   err(1, "Exec has failed\n");
	 }*/
	printf("Exec\n");
}
/*
	figure out how to exec with paths
*/
