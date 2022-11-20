# OOP2021f_exam

### 26 November 2021 09:10 - 12:00

**Before Midterm, you shuold remove HW04**

1. In the actual git folder, move files of HW00 to backup folder.

2. In bash, go to your git folder and do the following to remove HW04 from both local and remove repositories.

- git pull
- git rm src/*
- git rm test/*
- git rm makefile
- git commit -am "remove HW04"
- git push

3. Download source code of midterm from this reop and put it in your git folder.

**After above steps, here are the actual content of HW01**

Computing with binary numbers is an important part in computer science. So in this test, you have a mission to complete, that is, **to implement a class that can help you do some computation on binary data.**

We have provided a few test cases in `test/ut_binary.h` and `test/ut_binary.h` and `makefile`. Your mission is to implement the class, **"Binary"**, in `src/binary.h`, according to the following requirements.

**Requirements:**

1. One of the constructors should take a c-style int array as input. For example **int a[2] = {1, 0}** is the input for creating the binary number **10**.  

2. For the **destructor** and any other methods, you need to make sure that **no memory leaks** appear in your program.

3. Please use **deep copy** to write your **copy constructor**.

4. You need to write **4 test cases** for testing the exceptions.

**Example usages of methods:**

    int bits[4]={1,1,1,0};
    Binary bin(bits,4);
    bin.toString(); // "1101"
    bin.toInt();    // 13
    bin.resize(8);  // 00001101
    bin<<3;         // 01101000
    bin<<2;         // 11100000    
    bin>>4;         // 00001110
    bin.setBit(1,1);// 01001010
    bin.setBit(6,0);// 01001000

**Exception situation:**

1. If the binary number is not initialized with binary digits, calling methods that make use of the binary digits should throw an **Exception**.

2. You can assume that all the binary numbers are positive, so if a method generates a negative binary number, it should throw an **Exception**.

3. Resize a binary number to a size (i.e., number of bits) that is smaller than its original size should throw an **Exception**.

4. You cannot set a bit in any position that is out of bound, or the data you want to set is not **0 or 1**. (throw **Exception**)

**Prototypes of classes and functions:**

    class Binary{
        ...
        Binary(){...}                               // 5%
        Binary(int input[],int s){...}              // 5%
        Binary(const Binary & b){...}               // 10%
        ~Binary(){...}                              // 5%
        Binary & operator=(Binary const &b){...}    // 5%
        Binary operator+(Binary const &b){...}      // 5%
        Binary operator-(Binary const &b){...}      // 5%
        Binary operator>>(int a){...}               // 5%
        Binary operator<<(int a){...}               // 5%
        void resize(int new_size){...}              // 10%
        void setBit(int pos,int data){...}          // 10%
        int toInt() const{...}                      // 5%
        std::string toString() const{...}           // 5%
        ...
    };

**Note:**
1. Make sure your code is writen in the required file.
2. Your test cases are 20 points (5 points each) and pass TA's test cases to get another 80 points.
3. Lose 10 points if memory leaks.

**Resources allowed to use during the exam:**
-  [cplusplus.com](http://www.cplusplus.com/ "cplusplus.com")
-  [Cambridge Dictionary](https://dictionary.cambridge.org/zht/)
- Your own homework commits. (on Gitlab)
- Our class gitlab webpaghe.

**Attention!! You cannot visit any other website, or you will be considered as cheating.**
