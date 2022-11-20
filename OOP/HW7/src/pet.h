#ifndef PET_H
#define PET_H
#include <string>

class Pet
{
protected:
    std::string _name;
    double _weight;
public:
    Pet(std::string name, double weight){
        _name=name;
        _weight=weight;
    };
    virtual ~Pet(){};
    virtual std::string name() const {
        return _name;
    };
    virtual double weight() const {
        return _weight;
    };
    virtual void feed() = 0;
};

#endif