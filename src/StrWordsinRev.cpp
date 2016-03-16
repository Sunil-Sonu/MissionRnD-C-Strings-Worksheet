/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
void revstr(char *, int,int);
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	int i = 0, j = 0;
	revstr(input,0, len);
	while (i < len)
	{
		if (input[i] != ' ' && input[i + 1] != ' ' && len!=(i+1))
		{
			i++;
		}
		else if ((input[i] != ' ' && input[i + 1] == ' ')||(input[i+1]=='\0'))
		{
			revstr(input, j, i+1);
			i++;
			j = i; 
		}
		else
		{
			i++; j++;
		}
	}
	
}
void revstr(char *input, int a,int len)
{
	int k=a, m=len-1;
	char temp;
	for (k = a; k < m; k++)
	{
		temp = input[k];
		input[k] = input[m];
		input[m] = temp;
		m--;
	}
}