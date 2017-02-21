#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    #define MAX_NAME_SZ 1024
    char word[200],*pch;//initialize the array 
	char *filename=argv[1];//filename being dynamically passed assigned to filename
	char temp[200];
	int len;
    FILE *fp;
    fp= fopen(filename,"r");//opening the file
    while(fgets(word,200,fp)!=NULL)
	{
		pch=strtok(word,"\n");//splitting into tokens
		strcpy(temp,"(");
		strcat(temp,pch);
		strcat(temp,",1)\n");
    	write(1,temp,200);//writing to STDOUT 
	}
    fclose(fp);//closing file pointer
    return 0;
}
