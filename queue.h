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
	bool IsFull() const {return (rear + 1) % MaxSize == front;}
	T Top() const; //返回队头元素
	int Size() const;    // 返回队列长度
	void Push(T x); 
	void Pop(T& x);
private:
	T *Base; //队列的基地址；
	int front,rear; //队列头尾指针
	int MaxSize;  //队列最大元素值
};
template<class T>
CQueue<T>::CQueue(int MaxQueueSize){     //类的构造函数
	Base = new T[MaxQueueSize];
	if(!Base)
		exit(-1);  //队列分配失败
	front = rear = 0;  //队列致空
	MaxSize = MaxQueueSize - 1;
}

template <class T>
T CQueue<T> :: Top () const { //返回队头元素
	if(!IsEmpty())
		return Base[front];
}

template<class T>
void CQueue<T>::Push(const T x){ //队尾添加元素
    if (!IsFull())
    {
        Base[rear] = x;
	rear = (rear + 1) % MaxSize; 
    }
}
template<class T>
void CQueue<T>::Pop(T& x){// 删除栈顶元素，并将其送入x
    if (!IsEmpty())
    {
        x = Base[front];
	front = (front + 1) % MaxSize;
    }
}

template<class T>
int CQueue<T> :: Size() const { 
	return (rear - front + MaxSize) % MaxSize;
}
#endif

