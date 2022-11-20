#include <gtest/gtest.h>

#include "../src/polynomial.h"
#include "../src/term.h"

class PolynomialTest : public ::testing::Test
{
protected:
    Polynomial P1, P2, P3;
    std::vector<Term> Z;
    const double DELTA = 0.001;
    void SetUp() override
    {
        Term A(1, 0);
        Term B(2, 1);

        Term C(1, 0);
        Term D(2, 1);
        Term E(1, 2);

        Term F(4, 6);

        std::vector<Term> X = {B, A, F};
        std::vector<Term> Y = {E, D, C};
        std::vector<Term> H = {A, B};
        Z = {B, D};

        P1 = Polynomial(X, 6);
        P2 = Polynomial(Y, 2);
        P3 = Polynomial(H, 1);
    }
};

TEST_F(PolynomialTest, Constructor_Ascending)
{
    ASSERT_NEAR(P2.term(0).coefficient(), 1.0, DELTA);
    ASSERT_NEAR(P2.term(1).coefficient(), 2.0, DELTA);
    ASSERT_NEAR(P2.term(2).coefficient(), 1.0, DELTA);
    ASSERT_EQ(P2.term(0).exponent(), 0);
    ASSERT_EQ(P2.term(1).exponent(), 1);
    ASSERT_EQ(P2.term(2).exponent(), 2);
}

TEST_F(PolynomialTest, Constructor_SameExpoError)
{
    ASSERT_THROW(Polynomial(Z, 1), std::string);
}

TEST_F(PolynomialTest, Constructor_NoTermLost)
{
    ASSERT_NEAR(P1.term(0).coefficient(), 1.0, DELTA);
    ASSERT_NEAR(P1.term(1).coefficient(), 2.0, DELTA);
    ASSERT_NEAR(P1.term(2).coefficient(), 0.0, DELTA);
    ASSERT_NEAR(P1.term(3).coefficient(), 0.0, DELTA);
    ASSERT_NEAR(P1.term(4).coefficient(), 0.0, DELTA);
    ASSERT_NEAR(P1.term(5).coefficient(), 0.0, DELTA);
    ASSERT_NEAR(P1.term(6).coefficient(), 4.0, DELTA);
    ASSERT_EQ(P1.term(0).exponent(), 0);
    ASSERT_EQ(P1.term(1).exponent(), 1);
    ASSERT_EQ(P1.term(2).exponent(), 2);
    ASSERT_EQ(P1.term(3).exponent(), 3);
    ASSERT_EQ(P1.term(4).exponent(), 4);
    ASSERT_EQ(P1.term(5).exponent(), 5);
    ASSERT_EQ(P1.term(6).exponent(), 6);
}

TEST_F(PolynomialTest, Term_NotExist)
{
    ASSERT_EQ(P2.term(10), Term(0, 10));
}

TEST_F(PolynomialTest, Operator1)
{
    ASSERT_EQ((P1 + P2).term(0), Term(2, 0));
    ASSERT_EQ((P1 + P2).term(1), Term(4, 1));
    ASSERT_EQ((P1 + P2).term(2), Term(1, 2));
    ASSERT_EQ((P1 + P2).term(3), Term(0, 3));
    ASSERT_EQ((P1 + P2).term(4), Term(0, 4));
    ASSERT_EQ((P1 + P2).term(5), Term(0, 5));
    ASSERT_EQ((P1 + P2).term(6), Term(4, 6));
}

TEST_F(PolynomialTest, Operator2)
{
    Term a(2, 3);
    Polynomial b = P2 * a;
    ASSERT_EQ(b.term(0), Term(0, 0));
    ASSERT_EQ(b.term(1), Term(0, 1));
    ASSERT_EQ(b.term(2), Term(0, 2));
    ASSERT_EQ(b.term(3), Term(2, 3));
    ASSERT_EQ(b.term(4), Term(4, 4));
    ASSERT_EQ(b.term(5), Term(2, 5));
}

TEST_F(PolynomialTest, Operator3)
{

    Polynomial b = P2 * P3;
    ASSERT_EQ(b.term(0), Term(1, 0));
    ASSERT_EQ(b.term(1), Term(4, 1));
    ASSERT_EQ(b.term(2), Term(5, 2));
    ASSERT_EQ(b.term(3), Term(2, 3));
}