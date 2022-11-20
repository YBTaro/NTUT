#include "../src/gcd.h"
class gcdTest : public::testing::Test {
protected:
    int a, b, c, d, e;
    void SetUp() override {
        a=8;
        b=10;
        c=-15;
        d=20;
    }
};

TEST_F(gcdTest, gcd1){
    ASSERT_EQ(gcd(a,b),2);
}

TEST_F(gcdTest, gcd2){
    ASSERT_EQ(gcd(c,d),5);
}



