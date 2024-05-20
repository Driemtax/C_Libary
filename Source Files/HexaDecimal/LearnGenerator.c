#include <stdio.h>
#include <stdlib.h>
#include "../BinaryDecimal/DecimalBinaryConverter.h"
#include "HexaConverter.h"

int GenerateDecimal(){
    return rand()% 256;
}

int main(){
    while (1)
    {
        char hexa[3]; char binary[9];
        int n = GenerateDecimal();
        printf("Calculate Binary and Hexa number of: %d \n", n);

        printf("Binary Number: ");
        scanf("%s", &binary);
        printf("Hexa Number: ");
        scanf("%s", &hexa);

        int binCheck = BinaryToDecimal_Unsigned(binary);
        int hexaCheck = HexaToDecimal(hexa);
        if (binCheck == n && hexaCheck == n)
        {
            printf("Congratulations! Both answers were correct.\n");
        }
        else if (binCheck != n && hexaCheck == n)
        {
            printf("Sorry, your binary Number was wrong!\n");
        }
        else if (hexaCheck != n && binCheck == n){
            printf("Sorry, your hexa Number was wrong!\n");
        }
        else
        {
            printf("Sorry, both answers were wrong!\n");
        }
    }
}