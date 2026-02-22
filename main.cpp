#include<iostream>
#include "BiList.h"

int main() {
  int nums[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int amn = 10;

  BiList<int>* head = new BiList<int>(nums[0], nullptr, nullptr);
  BiList<int>* ths = head;

  for (size_t i = 1; i < amn; ++i) {
    ths = insert(ths, nums[i]);
    ths = ths->next;
  }
  BiList<int>* tail = ths->prev;

  sum s;
  proizved p;
  s = traverse(s, head, tail);
  p = traverse(p, head, tail);

  tail = clear(head, tail);
  delete head;

  std::cout << s.result << " " << p.result << "\n";

  return 0;
}
