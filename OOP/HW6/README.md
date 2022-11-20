### Homework 06

### Due: 11:59 p.m., 26 December 2021

**Content of HW06**

Practice object composition, operator overloading and comparator customization.

The following are examples of the polynomial with single variable $`x`$ (一元多項式):

```math
x^2 − 4x + 7 \text{ ... (Polynomial 1)} \\
0            \qquad\qquad\text{ ... (Polynomial 2)}
```
$`\text{Polynomial 1}`$ has three terms(項): $`x^2`$, $`-4x`$ and $`7`$; \
$`\text{Polynomial 2}`$ has one term $`0`$.

As can be seen, each term is represented by a pair of numbers: the coefficient (係數) of the variable and the exponent (冪次) of the variable. \
For example, the term $`-3x^2`$ is represented by Term(-3, 2) because it has coefficient $`-3`$ and exponent $`2`$.

**Soure tree**

```
├── src
│   ├── polynomial.h
│   └── term.h
├── test
│   ├── ut_polynomial.h
│   ├── ut_term.h
│   └── ut_main.cpp
├── .gitignore
└── makefile
```

**Sample code**

For this assignment you need to write class **Polynomial** in "src/polynomial.h" and **unit tests** in "test/ut_polynomial.h".
Class **Term** is written for you, please clone the folder and files we provide.

Class **Term** has the following functions:
- `Term(double coef, int exp)`
    - constructor
- `Term::coefficient`
    - get the coefficient (read-only)
- `Term::exponent`
    - get the exponent (read-only)
- `Term::operator==`
    - return true when two Terms have the same coefficient and exponent
- `Term::operator*`
    - multiply two Terms using `*`
- `Term::operator+`
    - add two Terms using `+`
- `Term::isZero`
    - check if it is zero (coefficient is zero)

Please write tests for consturctors and the following member functions:
- `Polynomial::Polynomial()`
  - constructor
      - Terms should be packed in ascending order with respect to their exponent. \
      Please use [std::stable_sort](http://www.cplusplus.com/reference/algorithm/stable_sort/) to sort and write the comparison function by yourself. (15%)
      - Throw exception when there're duplicate terms (with same exponent). (10%)
      - If the Term does not exist, fill *Term(0,  exponent)* in it, no Terms with exponent lower than degree can be lost. (15%) \
      For example, a cubic polynomial $`6x^3-3x^2+3`$

        ```c++
        std::vector<Term> terms = {Term(-3, 2), Term(3, 0), Term(6, 3)};
        Polynomial p(terms, 3);
        ```
        should have the Terms in the following form, conceptually:
        ```
        // in concept, not real C++ code
        Polynomial p {
            _terms = {Term(3, 0), Term(0, 1), Term(-3, 2), Term(6, 3) },
            _degree = 3
        }
        ```
- `Polynomial::term`
  - get the term by exponent (you don't have to test it, but get 5% if it's implemented correctly) 
  - If the term does not exist, please return *Term(0, exponent)* (5%)
- `Polynomial Polynomial::operator+ (Polynomial const & q)`
  - add two polynomials (15%)
- `Polynomial Polynomial::operator* (Term t)`
  - multiply by a Term (15%)
- `Polynomial Polynomial::operator* (Polynomial const & q)`
  - multiply by another Polynomial (15%)

You don't have to test `Polynomial::degree`, but get 5% if it is implemented correctly.

***Note:***
1. To test exception, use **ASSERT_THROW(statement, exception_type)**. \
In this assignment, exception should be in string type.
2. Please implement your test cases reasonably, or you **will get no point** for that sub-problem.
3. You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.
4. If you see segmentation fault, you can use `gdb` cmd to help debug. [Link]{https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/551505/
}
