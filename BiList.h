#ifndef BILIST_H
#define BILIST_H

template< class T >
struct BiList {
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};

template< class T >
BiList<T>* add(BiList<T>* prev, BiList<T>* next, const T& d);
template< class T >
BiList<T>* insert(BiList<T> *ths, const T &d);

template< class T >
BiList<T>* cut(BiList<T>* ths) noexcept;
template< class T >
BiList<T>* erase(BiList<T>* ths) noexcept;
template< class T >
BiList<T>* clear(BiList<T>* ths, BiList<T>* end) noexcept;

#endif
