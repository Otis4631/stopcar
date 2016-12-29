#include "queue.h"
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
        Base[rear] = x;
	rear = (rear + 1) % MaxSize; 
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
