#ifndef _CStack
#define _CStack
#include<iostream.h>
template<class T>
class CStack{  // LIFO 对象 、、test
public :
    CStack(int MaxStackSize = 10);
    ~CStack () {delete [] stack;}
    bool IsEmpty() const {return top == -1;}
    bool IsFull() const {return top == MaxTop ; }
T Top() const;   //test
CStack<T>& push(const T& x);
CStack<T>& Delete(T& x);
friend ostream& operator<<(ostream& out, const CStack<T>& w);

private :
    int top; // 栈顶
    int MaxTop; // 最大的栈顶值
    T *stack; // 堆栈元素数组
};

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
CStack<T>& CStack<T>::push(const T& x){ //添加元素x
    if (!IsFull())
    {
        stack[++top] = x;
        return *this;
    }
}

template<class T>
CStack<T>& CStack<T>::pop(T& x){// 删除栈顶元素，并将其送入x
    if (!IsEmpty())
    {
        x = stack[top--];
        return *this;
    }
}
template <class T>
ostream& operator<<(ostream& out, const CStack<T>& w){
     for(int i=w.top;i>-1;i--)
      out<<w.stack[i]<<" ";
      return out;
}
