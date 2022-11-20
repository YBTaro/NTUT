#ifndef CAT_H
#define CAT_H
#include <string>
#include <stdexcept>
#include "pet.h"

class Cat : public Pet
{
public:
    Cat(std::string name, double weight) : Pet(name, weight)
    {
        if (weight > 6 || weight < 2)
        {
            throw std::range_error("The range is in error!");
        }
    }
    ~Cat() override {}
    void feed() override
    {
        _weight += 0.2;
        if (_weight > 6)
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