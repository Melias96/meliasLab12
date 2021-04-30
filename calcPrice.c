#include <stdio.h>
int main(){
    int itemnum;
    double unitp;
    int quant;
    char pdate[12];
    printf("Enter item number:");
    scanf("%d", &itemnum);//user enter items
    printf("Enter unit price:");
    scanf("%lf", &unitp);//user inputs price
    printf("Enter quantity:");
    scanf("%d", &quant);//usre inputs quantity
    printf("Enter purchase date(mm/dd/yyyy):");
    scanf("%s", pdate);//user inputs date
    printf("Item\tUnit Price\tQTY\tPurchase Date\tTotal Amount\n");
    printf("%d\t$%9.2lf\t%d\t%s\t$%9.2lf\n\n", itemnum, unitp, quant, pdate, unitp * quant);
    //prints the data in an organized matter
    return 0;
}