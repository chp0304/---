#include<iostream>
#define MAX 100
#define ERROR -1
#define OK 1
using namespace std;

typedef struct
{
	int *top;
	int *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)//初始化栈
{
	S.base = new int[MAX];
	if (!S.base) { cout << "内存分配失败！"; return ERROR; }
	S.top = S.base;
	S.stacksize = MAX;
	return OK;
}

int Push(SqStack &S, int e)//元素入栈
{
	if (S.top - S.base == S.stacksize)
	{
		cout << "栈已满！！！" << endl;
		return ERROR;
	}
	*S.top++ = e;//top指向栈底上面的位置
	return OK;
}

int Pop(SqStack &S)//出栈
{
	if (S.base == S.top)//栈空
	{
		cout << "栈空！！！" << endl;
		return ERROR;
	}
	int e = *--S.top;//先 --，再*
	return e;
}

int GetTop(SqStack S)//取栈底元素
{
	if (S.base == S.top)
	{
		cout << "栈空！！！" << endl;
		return ERROR;
	}
	return *(S.top - 1);
}

int StackEmpty(SqStack S)//判断栈是否为空
{
	if (S.base == S.top)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	SqStack S;

	InitStack(S);
	int n;
	cin >> n;
	while (n)
	{
		Push(S, n % 8);
		n /= 8;
	}
	while (StackEmpty(S))
	{
		cout << Pop(S);
	}
	cout << endl;
	return 0;
}