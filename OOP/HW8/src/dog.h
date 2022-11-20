#ifndef DOG_H
#define DOG_H
#include <string>
#include <stdexcept>
#include "pet.h"
class Dog : public Pet
{
public:
    Dog()
    {
        _amount++;
    }
    Dog(std::string name, double weight) : Pet("DOG", name, weight)
    {
        if (weight > 50 || weight < 10)
        {
            throw std::range_error("The range is in error!");
        }
        ++_amount;
    }
    Dog(const Dog &d) : Pet("DOG", d.name(), d.weight())
    {
        if (d.weight() > 50 || d.weight() < 10)
        {
            throw std::range_error("The range is in error!");
        }
        _amount++;
    }

    ~Dog() override
    {
        _amount--;
    }

    void feed() override
    {
        double *_weight;
        _weight = getWeight();
        *_weight += 0.8;
        if (*_weight > 50)
        {
            throw std::out_of_range("too fat!");
        }
    }

    static int amount()
    {
        return _amount;
    }

private:
    static int _amount;
};
int Dog::_amount = 0;
#endif