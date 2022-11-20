#ifndef YARD_H
#define YARD_H

#include <vector>

#include "pet.h"
#include "dog.h"
#include "cat.h"

class Yard
{
public:
  Yard() = default;

  ~Yard()
  {
    for (Pet *pet : _pets)
    {
      delete pet;
    }
  }

  Yard(const Yard &yard)
  {
    _init(yard);
  }

  Yard operator=(const Yard &yard)
  {

    if (&yard != this)
    {
      // 若原本有指標，先清出記憶空間
      if (_pets.size() != 0)
      {
        for (Pet *pet : _pets)
        {
          delete pet;
        }
        while (_pets.size() != 0)
        {
          _pets.pop_back(); 
        }
      }

      // 要複製的大小不為0，開始deep copy
      _init(yard);
    }
    return *this;
  }

  void addPet(Pet *pet)
  {
    _pets.push_back(pet);
  }

  template <typename Condition>
  std::vector<Pet *> getPetWithCondition(Condition cond)
  {
    std::vector<Pet *> pets_in_cond;
    for (Pet *pet : _pets)
    {
      if (cond(pet))
      {
        pets_in_cond.push_back(pet);
      }
    }
    return pets_in_cond;
  }

private:
  std::vector<Pet *> _pets;
  void _init(const Yard &yard)
  {
    if (yard._pets.size() != 0)
    {
      for (Pet *pet : yard._pets)
      {
        Pet *newPet;
        if (pet->kind() == "DOG")
        {
          newPet = new Dog(pet->name(), pet->weight());
        }
        else if (pet->kind() == "CAT")
        {
          newPet = new Cat(pet->name(), pet->weight());
        }

        _pets.push_back(newPet);
      }
    }
  }
};

#endif /* end of include guard: YARD_H */
