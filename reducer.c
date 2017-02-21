#include  <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

struct count_value//defining structure to hold o/p values
{
   int count;
   char value[200];
}cv;

int main()
{
	char buf[200];
    size_t nbytes;
    char words[200];
    int fd;
    nbytes = sizeof(buf);
	char str[200];
	char temp[200];
    int i=0,j,flag=0,found;
    FILE *fp;
    char *token;
    struct count_value cv1[200];
    i = 0;
	j = 0;
    flag= 0;
    found = 0;
	token = &temp[0];
	while(read(0, buf, nbytes)>0)//reading while EOF is not reached
	{
		token = strtok(buf,"(,1)\n");//tokenizing the input 
		found=0;

		if (flag==0)//will execute only once when first word is encountered
      	{
			strcpy(cv1[i].value,token);//assigning word as first element in list
			cv1[i].count=1;//with count 1
			i++;
			flag=1;
			found=1;
      	}
      	else
      	{
			j = 0;
			while(j<i)
			{
				if(strcmp(token,cv1[j].value) == 0)//comparing the word with existing elements
				{
					cv1[j].count += 1;
					found=1;
					break;
				}
				j++;
			}
		}
      	if(found==0)//adding the word to list if not previously present in the list
      	{
		     strcpy(cv1[i].value,token);
		     cv1[i].count=1;//with count 1
		     i++;
      	}
    }


    int listcount=i;
	printf("\n");
    for (i=0;i<listcount;i++)
    {
        printf("(%s,%i)\n",cv1[i].value,cv1[i].count);//printing the output on screen
    }
	fclose(fp);

    return 0;
}