#ifndef ALGO_H
#define ALGO_H

#include "pet.h"

namespace pet_comp
{
  bool largerWeight(Pet const *const largest, Pet const *const curr)
  {
    return largest->weight() < curr->weight();
  }
  bool longerName(Pet const *const largest, Pet const *const curr)
  {
    return largest->name().size() < curr->name().size();
  }
}

// algo is used to practice polymorphism and see more usages of templates

// The meaning of "max" can be the weight or the length of name.
// @params
//  first, last:
//   Input iterators to the initial and final positions of the sequence to compare.
//   The range used is [first,last), which contains all the elements between first and last,
//   including the element pointed by first but not the element pointed by last.
//  comp:
//   Binary function that accepts two elements in the range as arguments,
//   and returns a value convertible to bool.
//   The value returned indicates whether the element passed as first argument
//   is considered less than the second.
// @return
//  Iterator to the greatest element in the range [first, last).
//  If several elements in the range are equivalent to the largerst element,
//  returns the iterator to the first such element.
//  Returns last if the range is empty.
template <typename ForwardIterator, typename Compare>
ForwardIterator maxPet(ForwardIterator first, ForwardIterator last, Compare comp)
{
  ForwardIterator largest = first;
  while (first != last)
  {
    if (comp(*largest, *first))
    {
      largest = first;
    }
    ++first;
  }
  return largest;
}

#endif /* end of include guard: ALGO_H */
