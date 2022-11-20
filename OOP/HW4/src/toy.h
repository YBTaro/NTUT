#ifndef TOY_H
#define TOY_H
#include <string>

class Toy
{
public:
    Toy()
    {
    }
    // constructor with parameter
    Toy(std::string name)
    {
        this->_toy = name;
    }

    // get the name of the toy
    std::string getName() const
    {   
        return this->_toy;
    }

private:
    std::string _toy;
};

#endif