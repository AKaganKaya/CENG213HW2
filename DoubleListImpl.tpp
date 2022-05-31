#pragma once

#include "DoubleList.tpp"

template <typename T>
DoubleList<T>::DoubleList(T *a, unsigned n) 
{
  Node* head = new Node();
  head->mValue = a[0];
  this->mHead[Red] = head;
  this->mHead[Blue] = head;
  Node* tmp_red = head;
  Node* tmp_blue = head;

  for(unsigned i = 1; i < n; i++)
  {
    Node* node = new Node();
    node->mValue = a[i];
    tmp_red->mNext[Red] = node;
    tmp_blue->mNext[Blue] = node;
    tmp_red = tmp_red->next(Red);
    tmp_blue = tmp_blue->next(Blue);
  }
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList<T> &dl) {}

template <typename T>
typename DoubleList<T>::Node *DoubleList<T>::get(unsigned index, Color color) const {
  Node* tmp = this->mHead[color];
  for(unsigned i = 0; i < index; i++)
  {
    tmp = tmp->next(color);
  }                        
  return tmp;
}

template <typename T>
typename DoubleList<T>::Node *DoubleList<T>::insert(T value, unsigned redIndex, unsigned blueIndex) {

  Node* node = new Node();
  node->mValue = value;
  if(redIndex == 0)
  {
    node->mNext[Red] = mHead[Red]->mNext[Red];
    mHead[Red] = node;
  }
  else
  {
    Node* tmp_red = this->head(Red);
    for(unsigned i = 0; i < redIndex - 1; i++)
    {
      if(tmp_red != nullptr)
      {
        tmp_red = tmp_red->next(Red);
      }
      else
      {
        throw InvalidIndexException();
      }
    }
    node->mNext[Red] = tmp_red->mNext[Red];
    tmp_red->mNext[Red] = node;
  }

  if(blueIndex == 0)
  {
    node->mNext[Blue] = mHead[Blue]->mNext[Blue];
    mHead[Blue] = node;
  }
  else
  {
    Node* tmp_blue = this->head(Blue);
    for(unsigned i = 0; i < blueIndex - 1; i++)
    {
      if(tmp_blue != nullptr)
      {
        tmp_blue = tmp_blue->next(Blue);
      }
      else
      {
        throw InvalidIndexException();
      }
    }
    node->mNext[Blue] = tmp_blue->mNext[Blue];
    tmp_blue->mNext[Blue] = node;
  }
  return node;
}

template <typename T>
void DoubleList<T>::remove(unsigned index, Color color) {}

template <typename T>
void DoubleList<T>::append(DoubleList<T> &dl) {}

template <typename T>
DoubleList<T>::~DoubleList() {}