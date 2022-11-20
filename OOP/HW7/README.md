### Homework 07

### Due: 11:59 p.m., 10 Janurary 2022

**Content of HW07**

Practice inheritance and polymorphism

***Cat*** and ***Dog*** can be kept as ***Pet***, and all pets have their own *name* and *weight*. \
Also to take care of the pets, we are able to *feed* them. \
In this assignment, please write a base class called *Pet* and let *Cat* and *Dog* inherit from it.

**Soure tree**

You will have the following folder structure.

```
<student_ID>_HW
├── src
│   ├── algo.h
│   ├── cat.h
│   ├── dog.h
│   └── pet.h
├── test
│   ├── ut_algo.h
│   ├── ut_cat.h
│   ├── ut_dog.h
│   └── ut_main.cpp
├── .gitignore
└── makefile
```

Though you've seen *Dog* in the previous assignments, to focus on the topic inheritance and polymorphism, \
you don't have to get your code from history.

#### 1. Inheritance

*Pet* should have three member functions
  - `std::string name()`: all pets have their name, and can get by this function
  - `double weight()`: all pets have their weight, and can get by this function
  - `void feed()`: this is a ***pure virtual function***, \
  since different pets have different reactions after *feed*

*Cat* and *Dog* should implement the `feed()` function.

#### 2. Polymorphism

There is a template function in *src/algo.h* called `maxPet()`. \
We want you to read and understand what it does, and write tests for it.

To test *maxPet*, you'll need to prepare the corresponding comparison functions, \
please put them in *src/algo.h*.

### Tests

#### 1. Object class

Please write tests for the following constructors and member functions
- `Cat::Cat(std::string name, double weight)`
  - take name and weight as the parameters, and initialize the data members correctly (8%)
  - throw exception in type `std::range_error` when having weight under(<) 2 or over(>) 6 (4%)
- `Cat::feed()`
  - weight grows 0.2 every feed (8%)
  - throw exception in type `std::out_of_range` when weight exceeds the limit 6 after feed (4%)
- `Dog::Dog(std::string name, double weight)`
  - take name and weight as the parameters, and initialize the data members correctly (8%)
  - throw exception in type `std::range_error` when having weight under(<) 10 or over(>) 50 (4%)
- `Dog::feed()`
  - weight grows 0.8 every feed (8%)
  - throw exception in type `std::out_of_range` when weight exceeds the limit 50 after feed (4%)

You don't have to test `name()`and `weight()` individually, but get 10% each if they are implemented correctly under the base class. \
Also the base class *Pet* should be an *abstract class*, 8% for the *pure virtual function* `Pet::feed()`, \
8% for the destructor `Pet::~Pet()`. You should avoid potential memory leaks.

#### 2. Template function

Please write tests in *test/ut_algo.h*, by using `maxPet()` to find the largest weight or the longest name of pets.
- Get the pet which has the largest weight from a std::vector of pets (8%)
- Get the pet which has the longest name from a std::vector of pets (8%)

***Note:***
1. Please implement your test cases reasonably, or you **will get no point** for that sub-problem.
2. You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.
3. If you see segmentation fault, you can use `gdb` cmd to help debug. [Link]{https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/551505/
}
