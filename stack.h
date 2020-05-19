#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h> 

#define DEBUG_ASSERT

#ifndef NULL
#define NULL (void *)0
#endif 

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

// 定义校验宏
#ifdef DEBUG_ASSERT
#define ASSERT_ERROR(x) do{if(!x){printf("[ERROR]:file[%s] line[%d] function[%s]\r\n", __FILE__, __LINE__, __func__);while(1);}}while(0)
#else
#define ASSERT_ERROR(x)
#endif


// 作为栈中核心数据成员
// 需要根据实际情况定义DATA
typedef int DATA;

typedef struct SStack // 栈结构
{
	DATA *m_pData;
	int m_nTop;
	int m_nCount;
} stack, *p_stack;

p_stack CreateStack(int nSize); // 创建一个栈
void DeleteStack(p_stack p); // 删除栈
int IsFull(p_stack p); // 满栈判断
int IsEmpty(p_stack p); // 空栈判断
int Push(p_stack p, const DATA *pdata); // 入栈
int PushByValue(p_stack p, const DATA data); // 入栈
int Pop(p_stack p, DATA *pdata); // 出栈
int GetSize(p_stack p); // 获取栈元素个数

#endif
