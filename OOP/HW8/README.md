### Homework 08

### Due: 11:59 p.m., 19 Janurary 2022

**Content of HW08**

Practice using constructor initialization list and lambda function

To keep our cute pets, we put them in our ***Yard***. \
And we add a *kind* label to different kinds of pets, so we can identify them under polymorphism. \
*Dog*s' *kind* label are initially set as `"DOG"`, and *Cat*s are `"CAT"`. \
In this assignment, we keep working on the codes of assignment 07. \

We provide parts of the codes. \
**Clone** or **download** this repository and put them in your homework file.

**Soure tree**

You will have the following folder structure.

```
<student_ID>_HW
├── src
│   ├── cat.h
│   ├── dog.h
│   ├── pet.h
│   └── yard.h
├── test
│   ├── ut_cat.h
│   ├── ut_dog.h
│   ├── ut_main.cpp
│   └── ut_yard.cpp
├── .gitignore
└── makefile
```
#### Pet, Cat and Dog

In *Pet*, three data members: `_kind`, `_name` and `_weight` are set to private. \
Don't change them to protected or public; modify *cat* and *dog* so that they work properly. \
You'll need to use the *constructor initialization list* to initialize those data \
and maybe add a protected member function in *Pet*, \
so function `feed()` of *Cat* and *Dog* can manage their weight growth correctly.

In *Pet*, *Cat* and *Dog*, each of them has a private static data member `_amount`. \
Once the object is created, the amount will increase 1; \
when the object is deleted, the amount will decrease 1. \
For places where the `_amount` should be added or redused,  you can refer to *src/pet.h* in constructor and destructor.
You need to modify `_amount` by yourself since the constructor and destructor that C++ provided won't manipulate the value for you. \
It's your work to change their value correctly. \
The static member function `amount()` is used to check whether all objects are destructed properly. \
All the test codes of this part are already written in *test/ut_\*.h*, you don't have to modify them. \
Your work is to make sure that you manage the memory well and pass the tests.

#### Yard

In *Yard*, there's a template function called `getPetWithCondition()`. \
We pass customized condition function as parameter, and it'll return pets in our yard which match the condtion. \
You are required to pass three kinds of condition functions: \
normal function, class that overloads function-call operator(a.k.a. functor) and lambda function. \
Since *Yard* stores pointer to Pets and handles their lifetime, you'll have to write copy constructor, copy assignment and destructor. \
We encourage you to use refactor technique called [*Extract Method*](https://medium.com/%E5%BD%BC%E5%BE%97%E6%BD%98%E7%9A%84-swift-ios-app-%E9%96%8B%E7%99%BC%E5%95%8F%E9%A1%8C%E8%A7%A3%E7%AD%94%E9%9B%86/%E5%B0%87%E9%87%8D%E8%A6%86%E7%9A%84%E7%A8%8B%E5%BC%8F%E8%AE%8A%E6%88%90-function-%E7%9A%84refactor-extract-method-932875e69610) to copy or delete, the priciple of Don't Repeat Yourself (D.R.Y.).

### Tests

#### Cat

- `Cat::Cat(std::string name, double weight)` (10%)
  - take name and weight as the parameters, and initialize the data members correctly
  - throw exception in type `std::range_error` when having weight under(<) 2 or over(>) 6 (4%)
- `Cat::feed()`
  - weight grows 0.2 every feed (6%)
  - throw exception in type `std::out_of_range` when weight exceeds the limit 6 after feed (2%)

The above 4 tests are the same as assignment 8(except the kind check in the constructor, add it!), \
keep using those tests and they should still pass.

#### Dog

- `Dog::Dog(std::string name, double weight)` (10%)
  - take name and weight as the parameters, and initialize the data members correctly
  - throw exception in type `std::range_error` when having weight under(<) 10 or over(>) 50 (4%)
- `Dog::feed()`
  - weight grows 0.8 every feed (6%)
  - throw exception in type `std::out_of_range` when weight exceeds the limit 50 after feed (2%)

The above 4 tests are the same as assignment 8(except the kind check in the constructor, add it!), \
keep using those tests and they should still pass.

***Attention !*** \
Remember not to change the private data members of Pet to protected or public, \
otherwise you will get no point for that sub-problem.

#### Yard

- `Yard::getPetWithCondition()`
  - condition pass by lambda function (8%)
  - condition pass by function (8%)
  - condition pass by functor (8%)
    - Just for inspiration, you can set a particular weight as the benchmark.
- *copy constructor*
  - deep copy should be used (10%)
- *copy assignment*
  - deep copy should be used (12%)
- *destructor*
  - all pets in the yard should be destructed properly, the way to test is in the test fixture we gave you, just copy them (10%)
    - the test will also fail if you use the constructor/destructor that C++ provided since the update of `_amount` is missing

- Above functions require 6 test cases.

- `Yard::addPet()`

```
void addPet(Pet * pet){
    _pets.push_back(pet);
}
```

***Note:***
1. Please implement your test cases reasonably, or you **will get no point** for that sub-problem.
2. You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.
3. If you see segmentation fault, you can use `gdb` cmd to help debug. [Link]{https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/551505/
}
