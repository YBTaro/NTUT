#ifndef Binary_H
#define Binary_H
#include <cmath>

class Binary
{
public:
    Binary()
    {
        _n = 0;
        _A = nullptr;
    }
    Binary(int input[], int s)
    {
        this->_n = s;
        this->_A = new int[s];
        for (int i = 0; i < s; i++)
        {
            this->_A[i] = input[i];
        }
    }
    Binary(const Binary &b)
    {
        this->_n = b._n;
        this->_A = new int[this->_n];
        for (int i = 0; i < this->_n; i++)
        {
            this->_A[i] = b._A[i];
        }
    }
    ~Binary()
    {
        if(_A != nullptr){
            delete[] _A;
        }
        
    }
    Binary &operator=(Binary const &b)
    {
        if (this != &b)
        {
            this->_n = b._n;
            this->_A = new int[this->_n];
            for (int i = 0; i < this->_n; i++)
            {
                this->_A[i] = b._A[i];
            }
        }
        return *this;
    }
    Binary operator+(Binary const &b)
    {
        if (_A == nullptr)
        {
            throw std::string("Error");
        }
        Binary A;
        return A;
    }
    Binary operator-(Binary const &b)
    {
        if (_A == nullptr)
        {
            throw std::string("Error");
        }
        Binary A;
        return A;
    }
    Binary operator>>(int a)
    {
        if (_A == nullptr)
        {
            throw std::string("Error");
        }
        int *w = new int[_n];

        for (int i = 0; i < a; i++)
        {
            w[i] = 0;
        }
        for (int i = 0; i + a < _n; i++)
        {
            w[a + i] = _A[i];
        }
        delete[] this->_A;
        this->_A = w;
        return *this;
    }
    Binary operator<<(int a)
    {
        if (_A == nullptr)
        {
            throw std::string("Error");
        }
        int *w = new int[_n];
        for (int i = _n - 1; i >= _n - a; i--)
        {
            w[i] = 0;
        }
        for (int i = 0; _n - 1 - a - i >= 0; i++)
        {
            w[_n - 1 - a - i] = _A[_n - 1 - i];
        }
        delete[] _A;
        _A = w;
        return *this;
    }
    void resize(int new_size)
    {
        if (_A == nullptr)
        {
            throw std::string("Error");
        }
        if (new_size < _n)
        {
            throw std::string("Error");
        }

        int *w = new int[new_size];
        for (int i = 0; i < new_size - _n; i++)
        {
            w[i] = 0;
        }
        for (int i = new_size - _n; i < new_size; i++)
        {
            w[i] = _A[i - new_size + _n];
        }
        delete[] _A;
        _A = w;
    }
    void setBit(int pos, int a)
    {
        if (_A == nullptr)
        {
            throw std::string("Error");
        }
        if (a != 0 & a != 1)
        {
            throw std::string("Error");
        }
        _A[pos] = a;
    }
    int toInt() const
    {
        int result = 0;
        for (int i = 0; i < _n; i++)
        {
            int b = 1;
            for (int j = _n - 1 - i; j >= 0; j--)
                result += _A[i] * pow(2, _n - 1 - i);
        }
        return result;
    }
    std::string toString() const
    {
        if (_A == nullptr)
        {
            throw std::string("Error");
        }
        std::string string = "";
        for (int i = 0; i < this->_n; i++)
        {
            string += std::to_string(_A[i]);
        }
        return string;
    }

private:
    int *_A;
    int _n;
};

#endif
