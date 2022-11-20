### Homework 04

### Due: 11:59 p.m., 23 November 2021

**In HW04, put all your source code of Toy in src/toy.h, Cat in src/cat.h and test code in test/ut_cat.h and test/ut_toy.h. You shuold carry on this homework based on HW03. And, please remember to update makeilfe.**

**Content of HW04**

The goal of this homework is to practice deep copy constructor/assignment, operator overloadding, and familiar with the desgin of class.

In HW03, you have completed some basic features of *Cat*. In HW04, you are going to extand *Cat* for a cat to compare its weight with others. Also, let ***Toy*** become an object, not just a name, instead of std::string.

**Functions to add or modify:**

```cpp
class Toy {
public:

  // constructor with parameter
  Toy(std::string name) { /* code */ }

  // get the name of the toy
  std::string getName() const { /* code */ }

private:
  // add data meber  
};
```

```cpp
class Cat {
public:

  // copy constructor
  Cat(Cat const & other) { /* code */ }

  // copy assignment
  Cat & operator = (Cat const & other) { /* code */ }

  // add Toy in toy collections
  void addNewToy(Toy const & toyName) { /* code */ }

  // index from 0
  Toy getToy(int index) const { /* code */ }

  // true if heavier than (>) other
  bool isHeavierThan(Cat const & other) const { /* code */ }

private:
  // adjust by yourself
};
```

To test your program, you are required to write **7** test cases in total according to following requirement.

Test the following situations:

- `Toy::getName` (5%)
- `Cat::Cat` *(constructor)*
  - throw exception if Cat have no name (5%)
  - throw exception if weight of Cat is out of range (5%) \
  range: 10 <= weight <= 50
- `Cat::Cat` *(copy constructor)* (10%)
- `Cat::operator=` *(copy assignment)* (10%)
- `Cat::AddNewToy` (5%)
  - allocate dynamically by `new` and `delete` (or std::vector) \
  No point if using fixed size array.
  - *(hint: you may need the default constructor of Toy)*
- `Cat::getToy`
  - get Toy by index in sequential order. Index start from 0 (5%)
  - throw exception if index is out of range (5%)
- `Cat::isHeavierThan` (5%)

Pass TA's test cases to get another 45%

**Watch out!** Lose 10 points if memory leaks.

**Note**
1. In this assignment, exceptions should be in string type.
2. Use `ASSERT_EQ` to test integer, `ASSERT_NEAR` to test floating-point number, `ASSERT_THROW` to test exception.
3. Please implement your test cases reasonably, otherwise you will get no point for that sub-problem.
4. You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.
5. If you see segmentation fault, you can use `gdb` cmd to help debug. [Link]{https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/551505/
}
