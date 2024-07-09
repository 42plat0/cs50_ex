// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{

    float n = (tax / 100) * bill;
    float m = (tip / 100.00) * (bill + n);
    float sum = (m + n + bill) / 2;
    return sum;
}
/*
25.145
in money:
    tax = (tax percentage / 100) * bill
    tip = (tip percentage / 100) * bill + tax
    full amount = tip + tax + bill
    each = full amount / 2;
*/
