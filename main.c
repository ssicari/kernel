#include<stdio.h>
#include<unistd.h>
#include<err.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	char buf[1024];

	if((getcwd(buf, 1024)) == NULL)
	   {
	      err(1, "Error: getcwd returned NULL\n");
	   }
	printf("[%s]$\n", (getcwd(buf, 1024)));
	exit(0);
}
