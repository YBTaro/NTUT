#include "../src/fraction.h"
class FractionTest : public::testing::Test {
protected:
    Fraction A, B, C, D, E;
    void SetUp() override {
        A=Fraction(1,3);
        B=Fraction(-8,10);
        C=Fraction(-6);
        E=Fraction(2);
    }
};

TEST_F(FractionTest, DefaultConstructor){
    ASSERT_EQ(D.numerator(),0);
    ASSERT_EQ(D.denominator(),1);
    ASSERT_EQ(D.sign(),'+');
    
}

TEST_F(FractionTest, OneParameterConstructor){
    ASSERT_EQ(C.numerator(),6);
    ASSERT_EQ(C.denominator(),1);
    ASSERT_EQ(C.sign(),'-');
}

TEST_F(FractionTest, TwoParameterConstructor){
    ASSERT_EQ(A.numerator(),1);
    ASSERT_EQ(A.denominator(),3);
    ASSERT_EQ(A.sign(),'+');
    ASSERT_EQ(B.numerator(),4);
    ASSERT_EQ(B.denominator(),5);
    ASSERT_EQ(B.sign(),'-');
    ASSERT_THROW(Fraction(4,0),std::string);
    // std::cout<<A.numerator()<<std::endl;
    // std::cout<<A.denominator()<<std::endl;
    // std::cout<<A.sign()<<std::endl;
}

TEST_F(FractionTest, ToString){
    ASSERT_EQ(A.toString(),"1/3");
    ASSERT_EQ(C.toString(),"-6");
    ASSERT_EQ(B.toString(),"-4/5");

}

TEST_F(FractionTest, Operator1){
    ASSERT_EQ((A+B).toString(),"-7/15");
}

TEST_F(FractionTest, Operator2){
    ASSERT_EQ((A-B).toString(),"17/15");
    
}

TEST_F(FractionTest, Operator3){
   ASSERT_EQ((A/C).toString(),"-1/18");
}

TEST_F(FractionTest, numerator){
   ASSERT_EQ(A.numerator(),1);
}

TEST_F(FractionTest, denominator){
   ASSERT_EQ(A.denominator(),3);
}

TEST_F(FractionTest, sign){
   ASSERT_EQ(A.sign(),'+');
}