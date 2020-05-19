#include "stack.h"

/**
 * [CreateStack 创建一个栈结构]
 * @param  nSize [栈大小]
 * @return       [返回创建的栈指针]
 */
p_stack CreateStack(int nSize)
{
	p_stack ps = malloc(sizeof(struct SStack));
    ps->m_pData = malloc(sizeof(DATA) * nSize);
    ps->m_nCount = nSize;
    ps->m_nTop = -1;
	return ps;
}

/**
 * [DeleteStack 删除一个栈结构]
 * @param p [已经创建好的栈指针]
 */
void DeleteStack(p_stack p)
{
	ASSERT_ERROR(p != NULL);
	p->m_nTop = -1;
	p->m_nCount = 0;
	free(p->m_pData);
    free(p);
}

/**
 * [IsFull 判断是否满栈]
 * @param  p [栈指针]
 * @return   [满则返回1，否则返回0]
 */
int IsFull(p_stack p)
{
	ASSERT_ERROR(p != NULL);
	return p->m_nCount == (p->m_nTop + 1);
}

/**
 * [IsEmpty 判断栈是否为空]
 * @param  p [栈指针]
 * @return   [空则返回1，非空则返回0]
 */
int IsEmpty(p_stack p)
{
	ASSERT_ERROR(p != NULL);
	return p->m_nTop == -1;
}

/**
 * [Push 压入一个元素]
 * @param  p     [栈指针]
 * @param  pdata [需要压入的数据的地址，使用指针便于传递结构体类型数据]
 * @return       [成功压入返回TRUE,否则返回FALSE]
 */
int Push(p_stack p, const DATA *pdata)
{
    ASSERT_ERROR(p != NULL);
	if(IsFull(p))
		return FALSE;
	p->m_pData[++(p->m_nTop)] = *pdata;
	return TRUE;
}

/**
 * [PushByValue 压入一个元素]
 * @param  p    [栈指针]
 * @param  data [需要压入的数据]
 * @return      [成功压入返回TRUE,否则返回FALSE]
 */
int PushByValue(p_stack p, const DATA data)
{
    ASSERT_ERROR(p != NULL);
	if (IsFull(p))
		return FALSE;
	p->m_pData[++(p->m_nTop)] = data;
	return TRUE;
}

/**
 * [Pop 弹出一个元素]
 * @param  p     [栈指针]
 * @param  pdata [接收需要弹出的数据，如果不需要接收可以传入NULL]
 * @return       [成功弹出返回TRUE,否则返回FALSE]
 */
int Pop(p_stack p, DATA *pdata)
{
    ASSERT_ERROR(p != NULL);
	if(IsEmpty(p))
		return FALSE;
	if(pdata != NULL)
		*pdata = p->m_pData[p->m_nTop];
	--(p->m_nTop);
	return TRUE;
}

/**
 * [GetSize 获取栈中元素个数]
 * @param  p [栈指针]
 * @return   [栈元素个数]
 */
int GetSize(p_stack p)
{
    ASSERT_ERROR(p != NULL);
	return (p->m_nTop + 1);
}
