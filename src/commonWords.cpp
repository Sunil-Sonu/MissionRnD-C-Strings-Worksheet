/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/
int comp(char **, char *,int);
#include <stdio.h>

#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	int i = 0, j = 0, k = 0, x, m, count1 = 0, count2 = 0,count3=0; char **str = NULL;
	if (str1 == '\0' || str2 == '\0')
		return NULL;
	else
	{
		str = (char **)malloc(sizeof(char *)*SIZE);
		for (m = 0; m < SIZE; m++){
			str[m] = (char *)malloc(sizeof(char)*SIZE);
		}
		while (str1[i] != '\0')
		{
			if (str1[i] != ' ')
			{
				count1++;
				str[j][k] = str1[i];
				i++; k++;
			}
			else if ((str1[i] == ' ' && str1[i + 1] != ' ') || (str1[i + 1] == '\0'))
			{
				count2++; str[j][k] = '\0';
				x = comp(str, str2, j);
				if (x == k)
				{
					count3++;
					j++; k = 0;
				}
				else
				{
					k = 0;
					str[j][k] = '\0';
				}
				i++;
			}
			else
			{
				i++;
			}
		}
		if (count1>0 && count2>0 &&count3>0)
		{
			return str;
		}
		else
		{
			return NULL;
		}
		
	}
}
int comp(char **str, char *str2,int n)
{
	int i = n, c = 0, count = 0, l = 0;
	while (str2[l] != '\0' && str[n][c]!='\0')
	{
		if (str2[l] != ' ')
		{ 
			if (str[n][c] == str2[l])
			{
				count++;
				c++;
				if (str[n][c] == '\0' && str2[i+1]==' '){
					break;
				}
			}
			else
			{
				count = 0;
			}
		}
		l++;
	}
	return count;
}