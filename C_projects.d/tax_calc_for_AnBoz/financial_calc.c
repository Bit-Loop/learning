#include <stdio.h>
#include <stdlib.h>
#define INNUM_MAX_LEN 9


int main(void) {

    char inChar;
    char* errChar;
    double hrPerWk;
    char numIn[INNUM_MAX_LEN;
    double misc, hourlyPay, annualSalary;
    double netYearly, federalTax, stateTax;
    annualSalary = netYearly = federalTax = 0; // bot sure if you can init an array like that
    //A
    puts("Please enter your hourly pay\n");
    fgets(numIn, INNUM_MAX_LEN, stdin);
    hourlyPay = strtod(numIn, &errChar);
    printf("hourlyPay:\t %.2f \n"), hourlyPay;
    //
    puts("Please enter your average hours worked");
    numIn[INNUM_MAX_LEN - 1] = '\n';
    fgets(numIn, INNUM_MAX_LEN, stdin);
    printf("hourlyPay:\t %.2f \n"), hrPerWk;
    // printf("hoursPerWeek:\t %lf\n"), hrPerWk;


////////////////////////////////////////////    $987.50 plus 12% of the amount over $9,875 I think your tax calc was wrong could do if tax brack += tax percent if 9875
// math should be like 987.5 + .12 * (annualSal - 9875) instead?

    stateTax = annualSalary * .05;
    misc = annualSalary * .08;
    //print tax % too
   //printf("Federal taxes: $%f\t"), federalTax;
   //printf("State taxes: %f\t$"), stateTax;
   //printf("Misc. deductions: %f\t$"), misc;

    return 0;
}