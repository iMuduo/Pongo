#include "lib.h"
#ifdef PALINDROME
/*
*
*	�����ַ�����ָ�����Һʹ��ҵ�����ͬ���ַ������ָ���һ������Сд��ĸ��ɵ��ַ���������԰�������ĸ�������У����γɲ�ͬ�Ļ����ַ�����
*
*	���룺�ǿս���Сд��ĸ��ɵ��ַ��������Ȳ�����100��
*	���������ɵ����л��Ĵ��ĸ�������Ϊ������ܷǳ��������1000000007ȡ�����Ľ������
*
*	���磺����"aabb" ���Ϊ2����Ϊ��aabb����Ӧ�����л����ַ�����2����abba��baab��
*
*/
#include <stdio.h>
#include <string.h>
#define MOD 1000000007

void discompose(int n,int *a,int step)
{
	int i;
	for (i=2;i<n+1;i++)
	{
		if(n%i==0)
		{
			a[i]+=step;
			n=n/i;
			i=1;
		}
	}
}

int palindrome(const char *s)
{
	int len=strlen(s);
	int i,t=0;
	long long count=1;
	int mark[200]={0},factorial[51]={0};

	for (i=0;i<len;i++)
		mark[s[i]]++;

	for (i=0;i<200;i++)
		t+=mark[i] & 1;
	if(t>1) return 0;

	for (i=2;i<((len>>1)+1);i++)
		discompose(i,factorial,1);

	for (i=0;i<200;i++)
		if((mark[i]/=2)>1)
			for(t=2;t<mark[i]+1;t++)
				discompose(t,factorial,-1);

	for (i=2;i<51;i++)
		for (t=0;t<factorial[i];t++)
			count=(count*i)%MOD;

	return (int)count;
}
#endif