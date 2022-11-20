#include <string>
#include "gcd.h"

class Fraction {
public:

  // default value is +0/1
  // i.e., _sign='+', _numerator=0, _denominator=1
  Fraction() {
    _sign='+';
    _numerator=0;
    _denominator=1;
  }

  // default value is an integer (denominator=1)
  // e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
  Fraction(int num) {
    if (num < 0){
      _sign='-';
      _denominator=1;
      _numerator=-num;
    }
    else{
      _sign='+';
      _denominator=1;
      _numerator=num;
    }

  }

  // hint: use gcd
  // throw exception when the denominator is 0
  Fraction(int numerator, int denominator) {
    if (denominator==0){
      throw std::string("undefined.");
    }

    if (numerator==0){
      _sign='+';
      _numerator=0;
      _denominator=1;
    }
    else{
      // 判斷正負
      if(numerator*denominator<0){
        _sign='-';
      }
      else{
        _sign='+';
      }

      numerator=abs(numerator);
      denominator=abs(denominator);
      int c=gcd(numerator,denominator);
      _numerator=numerator/c;
      _denominator=denominator/c;
    }
  }

  // get the numerator of the fraction
  int numerator() const {
    return _numerator;
  }

  // get the denominator of the fraction
  int denominator() const {
    return _denominator;
  }

  // get positive or negative sign of the fraction
  char sign() const {
    return _sign;
  }

  // display the fraction by string
  std::string toString() const {
    std::string string="";
    if (_sign == '-'){
      string+=_sign;
    }

    if(_denominator==1){
      string+=std::to_string(_numerator);
      return string;
    }
    else{
      string+=std::to_string(_numerator);
      string+="/";
      string+=std::to_string(_denominator);
      return string;
    }   
  }

  // addition of two Fractions
  Fraction operator + (Fraction const & f) const {

    int a=1, b=1;
    if(this->_sign=='-'){
      a=-1;
    }
    if(f._sign=='-'){
      b=-1;
    }

    int num=this->_numerator*f._denominator*a+f._numerator*this->_denominator*b;
    int de=this->_denominator*f._denominator;
    return Fraction(num,de);
  }

  // subtraction of two Fractions
  Fraction operator - (Fraction const & f) const {
    int a=1, b=1;
    if(this->_sign=='-'){
      a=-1;
    }
    if(f._sign=='-'){
      b=-1;
    }

    int num=this->_numerator*f._denominator*a-f._numerator*this->_denominator*b;
    int de=this->_denominator*f._denominator;
    return Fraction(num,de);
  }

  // division of two Fractions
  Fraction operator / (Fraction const & f) const {
    int a=1;
    if(this->_sign != f._sign){
      a=-1;
    }
    int num=this->_numerator*f._denominator*a;
    int de=this->_denominator*f._numerator;
    return Fraction(num,de);
  }

private:
  // both numerator and denominator should be positive
  int _numerator;
  int _denominator;
  char _sign;
};
