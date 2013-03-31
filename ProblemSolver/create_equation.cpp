/*
 Question:
 
 Given an array with positive integers and another integer for example{7 2 4} 9, you are required to generate an equation, by inserting operator add ("+") and minus ("-") among the array . The left side of equation are consist of the array and the right side of equation is the integer. here the result is 7-2+4=9
 
 
 
 Rules:
 
 Don't include any space in the generated equation.
 In case there is no way to create the equation, please output "Invalid". For example {1 1} 10, output is "Invalid"
 The length of the integer array is from 1 to 15( include 1 and 15). If the length is 1, for example the input  {7} 7, the output is 7=7
 There is no operator "+" or "-" in front of the first number:
 Don't change the order of the numbers. For example:  {7 2 4}  9. 7-2+4=9 is correct answer, 4-2+7=9 is wrong answer.
 There could be multiple input, meaning your function could be called multiple times. Do remember print a new line after the call.
 
 Sample Input and Output:
 
 Input:
 
 1 2 3 4 10
 
 1 2 3 4 5
 
 Output:
 
 1+2+3+4=10
 
 Invalid
 
 ---------------------------
 */

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

/************************************************************************/
/**
 Args:
 array[]: the inputted array
 final: the target value
 length: the element length
 */

void createEquationAndPrint(int array[], int length, int final){
    //Your Code is here
    unsigned short permutation = 0;
    unsigned short num_of_permutation = 0;
    
    if (length > 1)
    {
        num_of_permutation = 1;
        for (int i=0; i<length-1; i++)
        {
            num_of_permutation *= 2;
        }
    }
    
    unsigned short mask = 1;
    
    while(permutation < num_of_permutation)
    {
        mask = 1;
        int temp_final = final;
        
        for (int j=length-1; j > 0; j--)
        {
            if ((permutation & mask) == 0)
            {
                temp_final = temp_final - array[j];
            }
            else
            {
                temp_final = temp_final + array[j];
            }
            
            mask <<= 1;
        }
        
        if (array[0] == temp_final)
        {
            //found answer
            break;
        }
        permutation++;
    }
    
    if (permutation < num_of_permutation)
    {
        mask = mask >> 1;
        for (int i=0; i<length-1; i++)
        {
            printf("%d", array[i]);
            if ((permutation & mask) == mask)
            {
                printf("%c", '-');
            }
            else
            {
                printf("%c", '+');
            }
            mask >>= 1;
        }
        printf("%d=%d", array[length-1], final);
    }
    else
    {
        cout<<"Invalid";
    }
    
}

int splitAndConvert(char* strings,int array[]){
    char*tokenPtr = strtok(strings," ");
    int i=0;
    while(tokenPtr!=NULL){
        array[i] = atoi(tokenPtr);
        i++;
        tokenPtr=strtok(NULL," ");
    }
    return i;
}

int solve_create_equation(){
    char line[1000] = {0} ;
    while(gets(line)){
        int array[30] = {0};
        int length = splitAndConvert(line,array);
        if(length==0){
            break;
        }
        createEquationAndPrint(array, length-1, array[length-1]);
        cout<<endl;
    }
    return 0; 
}