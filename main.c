#include<stdio.h>
#include<unistd.h>
#include<err.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int manipulate_input(char* buf);

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
	      manipulate_input(buf);
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

int manipulate_input(char* buf)
{
	int j =0;
	int word = 0;
	char new_buf[strlen(buf)][strlen(buf)]; //figure out if we should use sizeof over strlen

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
	for(int i = 0; i < word; i++)
	   {
	      printf("%s\n", new_buf[i]);
	   }
	return 0;
}
/*
	figure out how to return array and finish level 3
	git commit merge after DO NOT MAKE ANOTHER COMMIT FOR LEVEL 3
*/
