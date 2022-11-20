#ifndef GCD_H
#define GCD_H

// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
int gcd(int a, int b)
{
    // 暴力法
    // int c;

    // a=abs(a);
    // b=abs(b);

    // if (a < b)
    // {
    //     c = a;
    // }
    // else
    // {
    //     c = b;
    // }

    // for (int i = c; i >= 1; i--)
    // {
    //     if (a % i == 0 & b % i == 0)
    //     {
    //         return i;
    //     }
    // }


    // 輾轉相除法
    a = abs(a);
    b = abs(b);

    while (a != 0 and b != 0)
    {
        if (a >= b)
        {
            a = a % b;
        }
        else if (b > a)
        {
            b = b % a;
        }
    }

    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

#endif