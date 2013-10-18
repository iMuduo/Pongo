#include "lib.h"
#ifdef PERFECT_STRING
/*
*
*	����Ҫ��ÿ����ĸ��һ��1-26֮���������������ô�����������������ͬ��ĸ�������Ȳ�ͬ��
*	��һ���ַ����������ȵ���������������ĸ��������֮�ͣ��Ҳ��ں���ĸ��Сд��Ҳ����˵��ĸF��f����������һ���ġ�
*
*	���ڸ���һ���ַ�����������������ܵ������ȡ�
*	���磺dad������Խ�26�����d��25�����a�����������ַ��������ܵ�������Ϊ77��
*
*/
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int perfect(const char *s)
{
	int len=strlen(s);
	int i,j,mark[256],cost[256];
	int max_cost=26,sum=0,max,max_pos=0;
	for (i=0;i<256;i++)
		mark[i]=cost[i]=0;
	for (i=0;i<len;i++)
		mark[tolower(s[i])]++;
	while(max_cost>0)
	{
		max=0;
		for (j=0;j<256;j++)
		{
			if(mark[j]>max)
			{
				max=mark[j];
				max_pos=j;
			}
		}
		cost[max_pos]=max_cost--;
		mark[max_pos]=0;
	}
	for (i=0;i<len;i++)
		sum+=cost[tolower(s[i])];
	return sum;
}

#endif