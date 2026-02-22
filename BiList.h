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

template<class T>
BiList<T> * add(BiList<T> *prev, BiList<T> *next, const T &d) {
  return new BiList<T>(d, next, prev);
}

template< class T >
BiList<T>* insert(BiList<T>* ths, const T& d) {
  return ths->next = add(ths, ths->next, d);
}

template<class T>
BiList<T> * cut(BiList<T> *ths) noexcept {
  ths->next->prev = ths->prev;
  BiList<T>* tmp = ths->next;
  delete ths;
  return tmp;
}
template<class T>
BiList<T> * erase(BiList<T> *ths) noexcept {
  return ths->next = cut(ths->next);
}
template<class T>
BiList<T> * clear(BiList<T> *ths, BiList<T> * end) noexcept {
  while (ths != end) {
    ths = cut(ths);
  }
  return ths;
}

template<class T, class F>
F traverse(F f, BiList<T>* ths, BiList<T>* end) {
  for (; ths != end; ths = ths->next) {
    f(ths->next);
  }
  return f;
}

#endif
