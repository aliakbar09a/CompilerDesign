#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include"great_dfa.c"
#include"fract_dfa.c"
int newParse(char* str)
{
	int len = strlen(str);
	int i = 0;
	char result[20];
	bool greater = false;
	bool sec_greater = false;
	bool equal = false;
	bool alpha = false;
	while(i < len)
	{
		if(isGreater(str[i]))
		{
			if(!alpha)
			{
				printf("Dead_state\n");
				return 0;
			}
			else if (greater)
			{
				sec_greater = true;
				strcpy(result, "<Right_shift>");
				i++;
			}
			else
			{
				greater = true;
				strcpy(result, "<GT>");
				i++;
			}
		}
		else if (isEqual(str[i]))
		{
			if(!alpha)
			{
				printf("Dead_state\n");
				return 0;
			}
			if(greater)
			{
				strcpy(result, "<GE>");
				if (sec_greater)
					strcpy(result, "<Right_shift_ass>");
				i++;
			}
			else 
			{
				strcpy(result, "Dead State");
			}
		}	
		else if(isAlpha(str[i]))
		{
			alpha = true;
			while(isAlpha(str[i+1]))
				i++;
			if(greater || equal)
			{
				printf("%s\n", result);
				greater=false;
				sec_greater=false;
				equal=false;
			}
			i++;
		}
		else if(isNum(str[i], true))
		{
			alpha = true;
			char numString[20];
			int k=0;
			while(isNum(str[i+1], true))
			{
				numString[k++]=str[i];
				i++;
			}
			numString[k]='\0';
			if(parseFract(numString)==0)
				return 0;
			if(greater || equal)
			{
				printf("%s\n", result);
				greater=false;
				sec_greater=false;
				equal=false;
			}
			i++;
		}
		
	}
}
int main()
{
	char str[20];
	scanf("%s", str);
	newParse(str);
	
}
