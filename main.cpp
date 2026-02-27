#include <iostream>
#include "BiList.h"
#define NULL 0

int main() {
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int amn = 10;

  BiList<int>* head = new BiList<int>{NULL, nullptr, nullptr};
  BiList<int>* ths = head;

  for (size_t i = 0; i < amn; ++i) {
    ths = insert(ths, nums[i]);
  }

  BiList<int>* tail = ths;
  sum s;
  proizved p;
  s = traverse(s, head->next, tail->next);
  p = traverse(p, head->next, tail->next);

  std::cout << s.result << " " << p.result << "\n";
  head = clear(head, tail->next);
  return 0;
}