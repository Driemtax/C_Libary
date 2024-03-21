#include <stdio.h>

char* BinaryAddition(char *summand1, char *summand2, int size){
    int carryBit = 0;

    char *result = (char)malloc(size * sizeof(char));

    //change with  utility function when header files are working
    for (int i = 0; i < size; i++)
    {
        result[i] = '0';
    }

    for (int i = size; i > 0; i--)
    {
        if (summand1[i] == '0' && summand2[i] == '0') //case both bits = 0
        {
            if (carryBit)
            {
                result[i] = '1';
                carryBit = 0;
            }
            else{
                result[i] = '0';
            }
        }
        else if(summand1[i] == '1' && summand2[i] == '0') // case summand 1 = 1 and summand 2 = 0
        {
            result[i] = '1';
        }
        else if(summand1[i] == '0' && summand2[i] == '1')
        {
            result[i] = '1';
        }
        else if (summand1 == '1' && summand2 == '1')
        {
            carryBit = 1;
            result[i] = '0';
        }   
    }
}

int main(){
    char testNumber1[] = "11000011";
    char testNumber2[] = "00000011";
}