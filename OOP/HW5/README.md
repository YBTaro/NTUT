### Homework 05

### Due: 11:59 p.m., 12 December 2021

**Before HW05, you shuold remove files of your midterm**

1. In the actual git folder, move files of HW00 to backup folder.

2. In bash, go to your git folder and do the following to remove HW04 from both local and remove repositories.

- git pull
- git rm src/*
- git rm test/*
- git rm makefile
- git commit -am "remove HW04"
- git push

3. Download source code of midterm from this reop and put it in your git folder.

**Content of HW05**

A fraction can be positive or negative, and have a numerator and a denominator. \
Also **gcd** is a function that helps to implement calculations of fraction.

For this assignment, you have to write class **Fraction** in "fraction.h" and function **gcd** in "gcd.h".

Also, you shuold use **test fixture** for conduting your testing. (10%)

**Soure tree**

```
├── src
│   ├── fraction.h
│   └── gcd.h
├── test
│   ├── ut_fraction.h
│   ├── ut_gcd.h
│   └── ut_main.cpp
├── .gitignore
└── makefile
```

**Sample code**

`Clone` the folder and files we provided for more descriptions.

Please write tests for constructors and the following member functions:

- `gcd(int a, int b)`
  - a, b are both positive (5%)
  - a or b is negative (5%)
- `Fraction::Fraction`
  - default constructor `Fraction()` works properly (5%)
  - one-parameter constructor `Fraction(int num)`
    - sign of Fraction is correct (5%)
    - value of Fraction is correct (5%)
  - two-parameter constructor`Fraction(int numerator, int denominator)`
    - sign of Fraction is correct (5%)
    - Fraction has been reduced properly (5%)
    - throw exception if denominator is 0 (5%)
- `Fraction::toString`
  - positive sign should omitted (5%) \
  e.g., Fraction(3, 2) converts to string "3/2"
  - if it's an integer, slash and denominator should be omitted (5%) \
  e.g., Fraction(-3, 1) converts to the string "-3"
  - other cases (5%) \
  e.g., Fraction(-3, 2) converts to the string "-3/2"
- `Fraction::operator +` (10%)
- `Fraction::operator -` (10%)
- `Fraction::operator /` (10%)

You have to test`Fraction::numerator`, `Fraction::denominator` and `Fraction::sign` individually (10%)

***Note:***
1. For `gcd()`, write it by yourself. Don't use `std::gcd`, which is provided by the C++ library.
2. For `Fraction::toString`, you might find some useful functions at [cplusplus.com](https://www.cplusplus.com) that helps.
3. To test exception, use **ASSERT_THROW(statement, exception_type)**. \
In this assignment, exception should be in string type.
4. Please implement your test cases reasonably, or you **will get no point** for that sub-problem.
5. You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.
6. If you see segmentation fault, you can use `gdb` cmd to help debug. [Link]{https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/551505/
}
