#include<stdio.h>
#include <sys/types.h>
#include <regex.h>


#define IP_REG "([0-9]{1,3})\\.[0-9]{1,3}\\.[0-9]{1,3}\\.([0-9]{1,3})"

int main()
{
	char str[1024] = {"abcdefg123.234.11c192.168.3.2xx192.168.3.3ssss"};
	
	regex_t reg; //regex_t 类型的变量
	regex_t *preg = &reg;//preg指向一段可用的空间
	char errstr[1024] = {0};
	int r = regcomp(preg,IP_REG,REG_EXTENDED | REG_ICASE);
	if(r != 0)
	{
		printf("regcomp error:");
		regerror(r, preg,errstr,1024);
		printf("%s\n",errstr);
		return -1;
	}
	
	regmatch_t match[3] = {0};//保存匹配到的结果
	int i,n=0;
	while(1)
	{
		r = regexec(preg, str+n,3,match, 0);
		if(r == 0)
		{
			printf("------\n");
			for(i=0;i<3;i++)
			{
				printf("[%d,%d)\n",match[i].rm_so+n,match[i].rm_eo+n);
			}
			n = n+match[0].rm_eo;
		}else
		{
			break;
		}
	}
	
	regfree(preg);
	
	return 0;
}

