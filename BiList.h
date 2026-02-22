#ifndef BILIST_H
#define BILIST_H

template< class T >
struct BiList {
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};

struct proizved {
  int result = 1;
  void operator()(int a) {
    result *= a;
  }
};
struct sum {
  int result = 0;
  void operator()(int a) {
    result += a;
  }
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

template < class T, class F >
F traverse(F f, BiList<T> ths, BiList<T> end);

#endif
