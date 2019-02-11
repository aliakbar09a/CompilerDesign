#include<stdbool.h>
#include<stdio.h>
#include<string.h>
bool isAlphaNum(char a)
{
	if((a >= 'A' && a <= 'Z')||(a >= 'a' && a <= 'z')||(a >= '0' && a <= '9'))
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
char* parse(char* str)
{
	printf("hello\n");
	int len = strlen(str);
	int i = 0;
	char result[20] = "0";
	bool greater = false;
	bool sec_greater = false;
	bool equal = false;
	bool alpha = false;
	while(i < len)
	{
		printf("\n%d\n", len);
		if(isSpace(str[i]))
		{
			i++;
			continue;
		}
		if(isGreater(str[i]))
		{
			if(!alpha)
			{
				strcpy(result, "Dead_state");
				printf("\nDead\n");
				return result;
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
				strcpy(result, "Dead_state");
				return result;
			}
			else if(greater)
			{
				strcpy(result, "<GE>");
				if (sec_greater)
					strcpy(result, "<Right_shift_ass>");
				i++;
			}
		}	
		else if(isAlphaNum(str[i]))
		{
			alpha = true;
			i++;
		}
		
	}
}
int main()
{
	char str[20] = ">hello";
	printf("%s",parse(str));
}
