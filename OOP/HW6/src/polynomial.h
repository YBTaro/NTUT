#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>

#include "term.h"

class Polynomial
{
public:
  Polynomial()
  {
    _degree = 0;
    _terms.push_back(Term(0, 0));
  }

  Polynomial(std::vector<Term> terms, int degree)
  {
    // 複製degree，並排序terms
    _degree = degree;
    std::stable_sort(terms.begin(), terms.end(), [](Term a, Term b)
                     { return a.exponent() <= b.exponent(); });

    // 相同exponent Error
    for (int i = 0; i < terms.size() - 1; i++)
    {
      if (terms.at(i).exponent() == terms.at(i + 1).exponent())
      {
        throw std::string("Same Exponent Error");
      }
    }

    // 複製到_terms，且補充中間空的exponent
    int j = 0;
    for (int i = 0; i < terms.size(); i++)
    {
      if (terms.at(i).exponent() != j)
      {
        _terms.push_back(Term(0, j));
        j++;
        i--;
      }
      else
      {
        _terms.push_back(terms.at(i));
        j++;
      }
    }
  }

  // get a term by exponent
  // If the term does not exist, return the term (0, exponent)
  Term term(int exponent) const
  {
    if (exponent > _degree)
    {
      return Term(0, exponent);
    }
    else
    {
      return _terms.at(exponent);
    }
  }

  // get the degree
  int degree() const
  {
    return _degree;
  }

  // add two polynomials
  Polynomial operator+(const Polynomial &q) const
  {
    std::vector<Term> v;
    int d;
    if (_degree < q._degree)
    {
      v = q._terms;
      d = _degree;
    }
    else
    {
      v = _terms;
      d = q._degree;
    }

    for (int i = 0; i <= d; i++)
    {
      v.at(i) = Term(_terms.at(i).coefficient() + q._terms.at(i).coefficient(), i);
    }

    int de = v.size() - 1;
    while (de > 0)
    {
      if (v.at(de).coefficient() != 0)
      {
        break;
      }
      else
      {
        v.pop_back();
        de -= 1;
      }
    }
    return Polynomial(v, de);
  }

  // multiply by a term
  Polynomial operator*(Term t) const
  {
    std::vector<Term> v;

    for (int i = 0; i < t.exponent(); i++)
    {
      v.push_back(Term(0, i));
    }

    for (int i = 0; i <= _degree; i++)
    {
      v.push_back(Term(_terms.at(i).coefficient() * t.coefficient(), _terms.at(i).exponent() + t.exponent()));
    }

    return Polynomial(v, v.size() - 1);
  }

  // multiply by another Polynomial
  Polynomial operator*(const Polynomial &q) const
  {
    Polynomial P;
    for (int i = 0; i <= _degree; i++)
    {
      for (int j = 0; j <= q._degree; j++)
      {
        Term a = _terms.at(i) * q._terms.at(j);
        std::vector<Term> v;
        v.push_back(a);
        P = P + Polynomial(v, a.exponent());
      }
    }
    return P;
  }

private:
  std::vector<Term> _terms;
  int _degree;
};

#endif
