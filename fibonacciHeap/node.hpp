//fibonacci heap implementation
//creating node class
#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
using namespace std;

template <class t=int,class v=int>
class Node{
  public:
  t key;
  v value;
  Node<t,v> *prev;
  Node<t,v> *next;
  Node<t,v> *parent;
  Node<t,v> *child;
  int degree;
  bool mark;

  Node(t key,v value){
    this->key = key;
    this->value = value;
    this->prev = this->next=this->parent =this->child = nullptr;
    this->degree = 0;
    this->mark = false;
  }  
};

#endif