#include <malloc.h>
#include <stddef.h>

/************************************************************************/
/*  �����ջ�����Է���ջ����СԪ��ֵ���㷨���Ӷ�ΪO��1��                */
/************************************************************************/

typedef struct StackEm 
{
	int e;
	struct StackEm *n;
}tStackEm;

typedef struct 
{
	int t;
	tStackEm s[1000];
	tStackEm *min;
}tStack;

tStack *CreateStack()
{
	tStack *s=malloc(sizeof(tStack));
	s->t=0;
	s->min=NULL;
	return s;
}

void Push(tStack *s,int e)
{
	if(s->min==NULL || e<=s->min->e)
	{
		s->s[s->t].e=e;
		s->s[s->t].n=s->min;
		s->min=s->s+s->t;
		s->t++;
	}
	else
	{
		s->s[s->t].e=e;
		s->s[s->t++].n=NULL;
	}
}

int GetMin(tStack *s)
{
	return s->min->e;
}

int Pop(tStack *s)
{
	tStackEm *e=s->s+--s->t;
	if(e->n!=NULL)
		s->min=e->n;
	return e->e;
}