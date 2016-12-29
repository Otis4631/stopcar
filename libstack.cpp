#include "stack.h"
template<class T>
CStack<T>::CStack(int MaxStackSize){  //类的构造函数
    MaxTop = MaxStackSize - 1;
    stack = new T[MaxStackSize];
    top = -1;
}

template<class T>
T CStack<T>::Top() const{    // 返回栈顶元素
    if (!IsEmpty())
        return stack[top];
}

template<class T>
void CStack<T>::Push(const T& x){ //添加元素x
    if (!IsFull())
    {
        stack[++top] = x;
    }
}

template<class T>
void CStack<T>::Pop(T& x){// 删除栈顶元素，并将其送入x
    if (!IsEmpty())
        x = stack[top--];
}
