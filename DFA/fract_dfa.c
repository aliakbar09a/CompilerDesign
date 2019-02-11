#include<stdbool.h>
#include<stdio.h>
#include<string.h>
bool isNum1(char a)
{
	if(a >= '0' && a <= '9')
		return true;
	else
		return false;
}
bool isPoint(char a)
{
	if(a == '.')
		return true;
	else
		return false;
}
int parseFract(char* str)
{
	int len = strlen(str);
	int i = 0;
	char result[20];
	bool point = false;
	bool num = false;
	while(i < len)
	{
		if(isNum1(str[i]))
		{
			num=true;
			while(isNum1(str[i]))
				i++;	
		}
		else if(isPoint(str[i]))
		{
			if(point)
			{
				printf("Dead state\n");
				return 0;
			}
			if(!num)
			{
				printf("Dead State\n");
				return 0;
			}
			else
			{
				strcpy(result, "<Fraction>");
			}
			point=true;
			i++;
		}
		
	}
	if(strcmp(result,"<Fraction>")!=0)
	{
		printf("<Integer>\n");
		return 2;
	}
	printf("%s\n", result);
	return 1;
}
/*int main()
{
	char str[20];
	scanf("%s", str);
	parseFract(str);
}*/
