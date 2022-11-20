#include <string>
#include "toy.h"

class Cat
{
public:
  Cat()
  {
  }
  Cat(std::string name, double weight)
  {
    if (name == "")
    {
      throw std::string("Name Error.");
    }
    if (weight < 10 || weight > 50)
    {
      throw std::string("Weight Error.");
    }
    this->_name = name;
    this->_weight = weight;
    this->_toyAmount = 0;
    this->_toyCollections = nullptr;
  }

  ~Cat()
  {
    delete[] this->_toyCollections;
  }

  // copy constructor
  Cat(Cat const &other)
  {
    this->_name = other._name;
    this->_weight = other._weight;
    this->_toyAmount = other._toyAmount;
    this->_toyCollections = new Toy[other._toyAmount];
    for (int i = 0; i < other._toyAmount; i++)
    {
      this->_toyCollections[i] = other._toyCollections[i];
    }
    std::cout << "constructor" << std::endl;
  }

  // copy assignment
  Cat &operator=(Cat const &other)
  {
    if (this != &other)
    {
      this->_name = other._name;
      this->_weight = other._weight;
      this->_toyAmount = other._toyAmount;
      this->_toyCollections = new Toy[other._toyAmount];
      for (int i = 0; i < other._toyAmount; i++)
      {
        this->_toyCollections[i] = other._toyCollections[i];
      }
    }
    std::cout << "assignment" << std::endl;
    return *this;
  }

  // add Toy in toy collections
  void addNewToy(Toy const &toyName)
  {
    if (this->_toyAmount == 0)
    {
      this->_toyCollections = new Toy[1];
      this->_toyCollections[0] = toyName;
      this->_toyAmount += 1;
    }
    else
    {
      this->_toyAmount += 1;
      Toy *A = new Toy[this->_toyAmount];
      for (int i = 0; i < this->_toyAmount - 1; i++)
      {
        A[i] = this->_toyCollections[i];
      }
      A[this->_toyAmount - 1] = toyName;
      delete[] this->_toyCollections;
      this->_toyCollections = A;
    }
  }

  // index from 0
  Toy getToy(int index) const
  {
    if (index > this->_toyAmount - 1 || index < 0)
    {
      throw std::string("Index Error.");
    }
    return this->_toyCollections[index];
  }

  // true if heavier than (>) other
  bool isHeavierThan(Cat const &other) const
  {
    return this->_weight > other._weight;
  }

  std::string getName()
  {
    return this->_name;
  }

  double getWeight()
  {
    return this->_weight;
  }

private:
  std::string _name;
  double _weight;
  Toy *_toyCollections;
  int _toyAmount;
};
