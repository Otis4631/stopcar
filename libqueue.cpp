#include "queue.h"
template<class T>
CQueue<T>::CQueue(int MaxQueueSize){     //��Ĺ��캯��
	Base = new T[MaxQueueSize];
	if(!Base)
		exit(-1);  //���з���ʧ��
	front = rear = 0;  //�����¿�
	MaxSize = MaxQueueSize - 1;
}

template <class T>
T CQueue<T> :: Top () const { //���ض�ͷԪ��
	if(!IsEmpty())
		return Base[front];
}

template<class T>
void CQueue<T>::Push(const T x){ //��β���Ԫ��
        Base[rear] = x;
	rear = (rear + 1) % MaxSize; 
}
template<class T>
void CQueue<T>::Pop(T& x){// ɾ��ջ��Ԫ�أ�����������x
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
