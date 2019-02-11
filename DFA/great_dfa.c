#include<stdbool.h>
#include<stdio.h>
#include<string.h>
bool isAlpha(char a)
{
	if((a >= 'A' && a <= 'Z')||(a >= 'a' && a <= 'z'))
		return true;
	else
		return false;
}
bool isNum(char a, bool checkpoint)
{
	if(a == '.' && checkpoint)
		return true;
	if(a >= '0' && a <= '9')
		return true;
	else
		return false;
}
bool isGreater(char a)
{
	if(a == '>')
		return true;
	else
		return false;
}
bool isEqual(char a)
{
	if(a == '=')
		return true;
	else
		return false;
}
bool isSpace(char a)
{
	if(a==' ')
		return true;
	else
		return false;
}
int parse(char* str)
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
		else if(isNum(str[i], false))
		{
			alpha = true;
			while(isNum(str[i+1], false))
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
		
	}
}
/*int main()
{
	char str[20];
	scanf("%s", str);
	parse(str);
}*/

