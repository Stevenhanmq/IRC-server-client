#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string.h>

template<class T>
class Stack{
 private:
  int size,top;
  T *pt;
 public:
  Stack(int s);
  ~Stack(){
    delete []pt;
  }
  void push(T val);
  T pop();
  void sort(int i);
  bool is_full();
  bool is_empty();
};

template<class T>
Stack<T>::Stack(int maxsize){
  size = maxsize;
  top = -1;
  pt = new T[size];
}

template<class T>
void Stack<T>::push(T val){
  if(!is_full()){
    pt[++top] = val;
  }
}

template<class T>
T Stack<T>::pop(){
  if(1){
    return pt[top--];
  }
}

template<class T>
void Stack<T>::sort(int i){
  if(strcmp(pt[i],pt[i++]) > 0 && pt[i++]!=NULL){
    char *tmp = pt[i];
    pt[i] = pt[i++];
    pt[i++] = tmp;
  }
}

template<class T>
bool Stack<T>::is_empty(){
  return top == size-1;
}

template<class T>
bool Stack<T>::is_full(){
  return top == -1;
}
#endif
