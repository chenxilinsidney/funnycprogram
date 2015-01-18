/**
 * @file accurate_float_expression.c
 * @brief accurate expression of of floating point number including
 * the repeating decimal numbers.
 * Ex: 0.3 -> 3 / 10 ; 0.3(3) -> 1 / 3
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-18
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef long TYPE;

/**
 * @brief get greatest common divisor(gcd) for value m and n.
 *
 * @param[in]      m  first value
 * @param[in]      n  second value
 *
 * @return gcd value
 */
TYPE gcd(TYPE m, TYPE n)
{
    /// m and n range limits
    assert(m >= 0 && n >= 0);
    if (m < n)
        return gcd(n, m);
    else if (n == 0)
        return m;
    if (m & 1) {
        if (n & 1)
            return gcd(n, (m - n) >> 1);
        else
            return gcd(m, n >> 1);
    } else {
        if (n & 1)
            return gcd(m >> 1, n);
        else
            return gcd(m >> 1, n >> 1) << 1;
    }
}

/**
 * @brief count the decimal number digit
 *
 * @param[in]     decimal_number input number
 *
 * @return digit count
 */
TYPE count_decimal_digit(TYPE decimal_number)
{
    TYPE digit = 1;
    while((decimal_number /= 10) != 0)
        digit++;
    return digit;
}

/**
 * @brief accurate expression for floating point numbers.
 *
 * @param[in]      value_integer integer part of floating number
 * @param[in]      value_decimal decimal part of floating number
 * @param[in]      value_repeating repeating part of floating number
 * @param[out]     numerator numerator of the output fractional number
 * @param[out]     denominator denominator of the output fractional number
 */
void accurate_float_expression(TYPE value_integer, TYPE value_decimal,
        TYPE value_repeating, TYPE* numerator, TYPE* denominator)
{
    /// reasonable input range
    assert(value_repeating >= 0 && value_decimal >= 0 && numerator != NULL &&
            denominator != NULL);
    /// get the decimal digit 
    TYPE digit_decimal = count_decimal_digit(value_decimal);
    TYPE digit_repeating = count_decimal_digit(value_repeating);
    /// detect if integer part is positive
    TYPE flag_positive = 1;
    /// get absolute integer part
    if (value_integer < 0) {
        value_integer *= -1;
        flag_positive = -1;
    }
    /// get denominator and numerator
    if (value_repeating == 0) {
        *denominator = pow(10, digit_decimal);
        *numerator = value_integer * *denominator + value_decimal;
    } else {
        *denominator = pow(10, digit_decimal) * (pow(10, digit_repeating) - 1);
        *numerator = value_integer * *denominator + value_repeating +
            value_decimal * (pow(10, digit_repeating) - 1);
    }
    /// get gcd of denominator and numerator
    TYPE value_gcd = gcd(*denominator, *numerator);
    /// get final value of numerator and denominator
    *numerator = flag_positive * *numerator / value_gcd;
    *denominator /= value_gcd;
}

int main(void) {
    /// get floating point number
    TYPE value_integer;
    TYPE value_decimal;
    TYPE value_repeating = 0;
    TYPE value_count;
    printf("input the floating point number integer(Ex:0.3 / 0.3(3)): \n");
    if(((value_count = scanf("%ld.%ld(%ld)", &value_integer,
                    &value_decimal, &value_repeating)) != 2 &&
                value_count != 3) || value_decimal < 0 ||
                value_repeating < 0) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right value.\n");
        DEBUG_PRINT_VALUE("%ld", value_integer);
        DEBUG_PRINT_VALUE("%ld", value_decimal);
        DEBUG_PRINT_VALUE("%ld", value_repeating);
        DEBUG_PRINT_VALUE("%ld", value_count);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// get accurate expression
    TYPE numerator;
    TYPE denominator;
    accurate_float_expression(value_integer, value_decimal, value_repeating,
            &numerator, &denominator);
    /// output result
    printf("accurate expression for floating point number is: \n%ld / %ld\n",
            numerator, denominator);
    return EXIT_SUCCESS;
}
