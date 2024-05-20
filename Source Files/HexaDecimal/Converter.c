#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateHexaSize(int number){ //32
    int size = 0;
    while (number > 0)
    {
        size ++;
        number /= 16;
    }

    return size;
    
}

void initializeArray(char *binNumber, int size){
    for (int i = 0; i < size; i++)
    {
        binNumber[i] = '0';
    }
    binNumber[size] = '\0';
}

char* DecimalToHexa(int number){
    int size = calculateHexaSize(number);

    char* hexaNum = (char*)malloc((size+1) * sizeof(char));
    if (hexaNum == NULL)
    {
        printf("Critical Error! Memory Allocation has failed.");
        return "00";
    }
    initializeArray(hexaNum, size);

    for (int i = size-1; i >= 0; i--)
    {
        int calc = number % 16;
        switch (calc)
        {
        case 0:
            hexaNum[i] = '0';
            break;
        case 1:
            hexaNum[i] = '1';
            break;
        case 2:
            hexaNum[i] = '2';
            break;
        case 3:
            hexaNum[i] = '3';
            break;
        case 4:
            hexaNum[i] = '4';
            break;
        case 5:
            hexaNum[i] = '5';
            break;
        case 6:
            hexaNum[i] = '6';
            break;
        case 7:
            hexaNum[i] = '7';
            break;
        case 8:
            hexaNum[i] = '8';
            break;
        case 9:
            hexaNum[i] = '9';
            break;
        case 10:
            hexaNum[i] = 'A';
            break;
        case 11:
            hexaNum[i] = 'B';
            break;
        case 12:
            hexaNum[i] = 'C';
            break;
        case 13:
            hexaNum[i] = 'D';
            break;
        case 14:
            hexaNum[i] = 'E';
            break;
        case 15:
            hexaNum[i] = 'F';
            break;
        default:
            break;
        }    
        number /= 16;
    }
    
    return hexaNum;
}

int HexaToDecimal(char* hexaNum){
    int size = strlen(hexaNum);
    int result = 0;
    int valency = 1;

    for (int i = size-1; i >= 0; i--)
    {
        switch (hexaNum[i])
        {
        case '0':
            valency *= 16;
            break;
        case '1':
            result += (1*valency);
            valency *= 16;
            break;
        case '2':
            result += (2*valency);
            valency *= 16;
            break;
        case '3':
            result += (3*valency);
            valency *= 16;
            break;
        case '4':
            result += (4*valency);
            valency *= 16;
            break;
        case '5':
            result += (5*valency);
            valency *= 16;
            break;
        case '6':
            result += (6*valency);
            valency *= 16;
            break;
        case '7':
            result += (7*valency);
            valency *= 16;
            break;
        case '8':
            result += (8*valency);
            valency *= 16;
            break;
        case '9':
            result += (9*valency);
            valency *= 16;
            break;
        case 'A':
            result += (10*valency);
            valency *= 16;
            break;
        case 'B':
            result += (11*valency);
            valency *= 16;
            break;
        case 'C':
            result += (12*valency);
            valency *= 16;
            break;
        case 'D':
            result += (13*valency);
            valency *= 16;
            break;
        case 'E':
            result += (14*valency);
            valency *= 16;
            break;
        case 'F':
            result += (15*valency);
            valency *= 16;
            break;
        default:
            break;
        }
    }

    return result;
}

int main(){
    char input; int inputNumber;

    printf("#################################################\n");
    printf("Willkommen! Wie möchten Sie umwandeln?\n");
    printf("#################################################\n");
    printf("a: Decimal to Hexa \n");
    printf("b: Hexa to Decimal\n");
    scanf("%c", &input);

    switch (input)
    {
    case 'a':
        printf("Please enter the number: ");
        scanf("%d", &inputNumber);
        int size = calculateHexaSize(inputNumber);
        if(!size){
            printf("binary Number: 0000");
        }
        else {
            char *binNumber = DecimalToHexa(inputNumber);
            printf("Hexa: %s \n", binNumber);
            free(binNumber);
        }
        break;
    case 'b':
        printf("Please enter your hexa Number (max 1 Byte): ");
        char binNumber[3];
        initializeArray(binNumber, 2);
        scanf("%s", binNumber);
        
        int result = HexaToDecimal(binNumber);
        printf("Decimal Result: %d", result);
        break;
    default:
        break;
    }
}