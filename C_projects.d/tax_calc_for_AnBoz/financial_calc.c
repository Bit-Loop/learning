#include <stdio.h>
#include <stdlib.h>
#define INNUM_MAX_LEN 9
#define TAX10_MIN 0 
#define TAX10_MAX 9875
#define TAX12_MAX 40125
#define TAX22_MAX 85525
#define TAX24_MAX 163300
#define TAX32_MAX 207350
#define TAX35_MAX 518400
#define TAX10J_MAX 19750 // could do a basic and algo /w math but not worth the effort
#define TAX12J_MAX 80250
#define TAX22J_MAX 171050
#define TAX24J_MAX 326600
#define TAX32J_MAX 414700
#define TAX35J_MAX 622050 // != tax35 * 2

int main(void) {
  char inChar = 0;
  char* errChar;
  double hrPerWk = 0.0;
  char numIn[INNUM_MAX_LEN];
  double netYearly = 0.0, hourlyPay, annualSalary;
  double taxableYearly = 0.0, stateTax;
  double taxCounter = 0.0;
  double federalTax = 0.0;
  
   // bot sure if you can init an array like that
  // A
  puts("Please enter your hourly pay");
  fgets(numIn, INNUM_MAX_LEN, stdin);
  hourlyPay = strtod(numIn, &errChar);
  printf("hourlyPay:\t %5.2f \n"), hourlyPay;
  //
  puts("Please enter your average hours worked");
  fgets(numIn, INNUM_MAX_LEN, stdin);
  hrPerWk = strtod(numIn, &errChar);
  printf("hrPerWk:\t %3.2f \n"), hrPerWk;
  // printf("hoursPerWeek:\t %lf\n"), hrPerWk;

  taxableYearly = 56 * hrPerWk * hourlyPay;
  printf("taxableYearly income $%f\n", taxableYearly);
  ////////////////////////////////////////////    $987.50 plus 12% of the amount
  ///over $9,875 I think your tax calc was wrong could do if tax brack += tax
  ///percent if 9875
  // math should be like 987.5 + .12 * (annualSal - 9875) instead?


  /* Numbers used to dynamically calculate tax
     taxOwed% is used to calculate federalTax (the tax total)
     EG: tax rate <12%> [ $19,751 to $80,250 ] : tax owed "$987.50 plus 12% of the amount over $9,875"
       = tax owed from 10% plus 12% of the amount over $9,875 ( tax bracket below)
       = taxOwedFrom10 + .12 * (taxableYearly - TAX10_MAX)
  */
  const double taxOwedFrom10 = TAX10_MAX * .1; //These are double checked (s)   
  const double taxOwedFrom12 = taxOwedFrom10 + .12 * (TAX12_MAX - TAX10_MAX); 
  const double taxOwedFrom22 = taxOwedFrom12 + .22 * (TAX22_MAX - TAX12_MAX); 
  const double taxOwedFrom24 = taxOwedFrom22 + .24 * (TAX24_MAX - TAX22_MAX); 
  const double taxOwedFrom32 = taxOwedFrom24 + .32 * (TAX32_MAX - TAX24_MAX); 
  const double taxOwedFrom35 = taxOwedFrom32 + .35 * (TAX35_MAX - TAX32_MAX); 
  printf("Tax Rate : Min Tax Owed\n"
         "10%% : %f\t12%% : %f\t22%% : %f\n"
         "24%% : %f\t32%% : %f\t35%% : %f\n",
         taxOwedFrom10, taxOwedFrom12, taxOwedFrom22, 
         taxOwedFrom24, taxOwedFrom32, taxOwedFrom35);

  // This is gross but, not sure what would be better / simpler
    if ((TAX10_MIN < taxableYearly) && (taxableYearly <= TAX10_MAX)) { // tax bracket SEL @ 10%
    federalTax = taxableYearly * .10;
    puts("no\n\n\n");
    } else if ((TAX10_MAX < taxableYearly) && (taxableYearly <= TAX12_MAX)) { // Tax Brackcket @ 12%
      federalTax = (taxOwedFrom10 + .12 * (taxableYearly - TAX10_MAX));
    } else if ((TAX12_MAX < taxableYearly) && (taxableYearly <= TAX22_MAX)) { // T[22] 
      federalTax = taxOwedFrom12 + .22 * (taxableYearly - TAX12_MAX);
    } else if ((TAX22_MAX < taxableYearly) && (taxableYearly <= TAX24_MAX)) { // T[24]
      federalTax = taxOwedFrom22 + .22 * (taxableYearly - TAX22_MAX);
    } else if ((TAX24_MAX < taxableYearly) && (taxableYearly <= TAX32_MAX)) { // T[32]
      federalTax = taxOwedFrom24 + .22 * (taxableYearly - TAX24_MAX);
    } else if ((TAX32_MAX < taxableYearly) && (taxableYearly <= TAX35_MAX)) { // T[35]
      federalTax = taxOwedFrom32 + .22 * (taxableYearly - TAX32_MAX);
    } else if (TAX35_MAX < taxableYearly) { // T[37] to inf
      federalTax = taxOwedFrom35 + .37 * (taxableYearly - TAX35_MAX);
    } else {
      puts("An error has occured. Maybe a number is negative.");
      return -1;
    }
 
    
    //stateTax = annualSalary * .05;
   // misc = annualSalary * .08;
    //print tax % too

   printf("Federal Taxes: $ %f \t"), federalTax;
   //printf("State taxes: %f\t$"), stateTax;
   //printf("Misc. deductions: %f\t$"), misc;

    return 0;
}