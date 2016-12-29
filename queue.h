#ifndef __CQUEUE_H__
#define __CQUEUE_H__
#include <iostream>
#include <stdlib.h>
//循环队列，大小固定。防止溢出
template <class T>
class CQueue{  //创建队列对象
public:
	CQueue(int MaxQueueSize = 10);
	~CQueue() {delete [] Base;}
	bool IsEmpty() const {return front == rear;}
	T Top() const; //返回队头元素
	int Size() const;    // 返回队列长度
	void Push(T x); 
	void Pop(T& x);
private:
	T *Base; //队列的基地址；
	int front,rear; //队列头尾指针
	int MaxSize;  //队列最大元素值
};

#endif

