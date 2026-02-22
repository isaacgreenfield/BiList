#ifndef BILIST_H
#define BILIST_H

template<class T>
struct BiList {
    T val;
    BiList<T>* next;
    BiList<T>* prev;
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
BiList<T>* add(BiList<T>* prev, BiList<T>* next, const T& d) {
    return new BiList<T>{d, next, prev};
}
template<class T>
BiList<T>* insert(BiList<T>* ths, const T& d) {
    BiList<T>* nxt = add(ths, ths->next, d);
    if (ths->next != nullptr)
        ths->next->prev = nxt;
    ths->next = nxt;
    return nxt;
}

template<class T>
BiList<T>* cut(BiList<T>* ths) noexcept {
    BiList<T>* prv = ths->prev;
    BiList<T>* nxt = ths->next;

    if (prv != nullptr)
        prv->next = nxt;
    if (nxt != nullptr)
        nxt->prev = prv;

    delete ths;
    return nxt;
}
template<class T>
BiList<T>* erase(BiList<T>* ths) noexcept {
    if (ths == nullptr || ths->next == nullptr) return nullptr;
    ths->next = cut(ths->next);
    return ths->next;
}
template<class T>
BiList<T>* clear(BiList<T>* ths, BiList<T>* end) noexcept {
    while (ths != end) {
        ths = cut(ths);
    }
    return ths;
}

template<class T, class F>
F traverse(F f, BiList<T>* ths, BiList<T>* end) {
    for (BiList<T>* curr = ths; curr != end; curr = curr->next) {
        f(curr->val);
    }
    return f;
}

#endif