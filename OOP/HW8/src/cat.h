#ifndef CAT_H
#define CAT_H
#include <string>
#include <stdexcept>
#include "pet.h"

class Cat : public Pet
{
public:
    Cat()
    {
        ++_amount;
    }
    Cat(std::string name, double weight) : Pet("CAT", name, weight)
    {
        if (weight > 6 || weight < 2)
        {
            throw std::range_error("The range is in error!");
        }
        ++_amount;
    }

    Cat(const Cat &c) : Pet("CAT", c.name(), c.weight())
    {
        if (c.weight() > 6 || c.weight() < 2)
        {
            throw std::range_error("The range is in error!");
        }
        _amount++;
    }
    ~Cat() override
    {
        _amount--;
    }
    void feed() override
    {
        double *_weight;
        _weight = getWeight();
        *_weight += 0.2;
        if (*_weight > 6)
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

int Cat::_amount = 0;
#endif