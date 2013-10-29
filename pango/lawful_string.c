#include "lib.h"
#ifdef LAWFUL_STRING
/*
*	��n����ͬ���ַ������1 - n�������һ���ַ�����������2��Ҫ��
*	1�����ڱ��Ϊi ���ַ������2 * i > n������ַ�������Ϊ���һ���ַ�����������ַ�������Ϊ���һ���ַ��Ļ�������ַ�������Խ������ַ���
*	2�����ڱ��Ϊi���ַ������2 * i <= n������ַ���������Ϊ���һ���ַ����Ҹ��ַ������������ŵ���һ���ַ��ı��һ��Ҫ >= 2 * i��
*	���ж��ٳ���ΪM�ҷ����������ַ�����
*	���磺N = 2��M = 3����abb, bab, bbb�Ƿ����������ַ�����ʣ�µľ�Ϊ�������������ַ�����
*
*	���룺n,m  (2<=n,m<=1000000000)��
*	����������������ַ����ĸ������������ݺܴ��������Mod 10^9 + 7�Ľ����
*		
*
*/
#define M 1000000009

int f(int l,int e,int n)
{
	int c=0,i;
	if(l==1)
		return 1;
	else if((e<<(l-1))>n>>1)
		return 0;
	else if(l==2)
		return n-e<<1+1;
	else
		for (i=n-(e<<l-1)+1;i>0;i=i-2)
			c+=i;
	return c;
}

int powx(int n,int k) 
{ 
	int r = 1 ; 
	while(k) 
	{ 
		if(k & 1 ) 
			r *= n; 
		k >>= 1; 
		n *= n; 
	} 
	return r; 
}


int validstring(int n,int m) 
{
	int r=1,c=0,l=1,i,j;
	while((1<<l-1)<n)
	{
		for (i=1;i<n && r;i++)
		{
			r=f(l,i,n);
			for(j=0;j<m-l;j++)
				c=c+r*powx(n>>1,j)*powx(n>>1,m-l-j);
		}
		l++;
	}
	c+=powx(n>>1,m);
}

#endif
