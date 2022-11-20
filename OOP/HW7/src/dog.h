#ifndef DOG_H
#define DOG_H
#include <string>
#include <stdexcept>
#include "pet.h"
class Dog : public Pet
{
public:
    Dog(std::string name, double weight) : Pet(name, weight)
    {
        if (weight > 50 || weight < 10)
        {
            throw std::range_error("The range is in error!");
        }
    }

    ~Dog() override {}

    void feed() override
    {
        _weight += 0.8;
        if (_weight > 50)
        {
            throw std::out_of_range("too fat!");
        }
    }
    std::string name() const override
    {
        return _name;
    }

    double weight() const override
    {
        return _weight;
    }

private:
};

#endif