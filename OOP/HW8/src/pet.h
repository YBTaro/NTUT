#ifndef PET_H
#define PET_H
#include <string>

class Pet
{
private:
    double _weight;
    std::string _kind;
    std::string _name;
    static int _amount;

protected:
    double *getWeight()
    {
        return &_weight;
    }

public:
    Pet()
    {
        _amount++;
    }
    Pet(std::string const &kind, std::string const &name, double const weight)
        : _kind(kind), _name(name), _weight(weight)
    {
        ++_amount;
    }

    Pet(Pet const &other)
        : _kind(other._kind), _name(other._name), _weight(other._weight)
    {
        ++_amount;
    }
    Pet(std::string name, double weight)
    {
        _name = name;
        _weight = weight;
        ++_amount;
    };
    virtual ~Pet()
    {
        --_amount;
    };
    std::string name() const
    {
        return _name;
    };
    double weight() const
    {
        return _weight;
    };
    static int amount()
    {
        return _amount;
    }
    std::string kind() const
    {
        return _kind;
    }
    virtual void feed() = 0;
};
int Pet::_amount = 0;
#endif