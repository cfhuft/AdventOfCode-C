#include <stdio.h>

#define I 100                                   //define  the input data size for a 2d array
#define J 100

int get_numbers(FILE* one, int array[I][J]){    //function to transfer the input data from a file into a 2d array
    int c, i, j, digit;

    for(int i = 0; i<I; i++){
        for(int j = 0; j<J; j++){
            c=fgetc(one);
            if(c=='\n'){                        //if the character is newline, grab the next one
                c=fgetc(one);  
            }
            sscanf(&c,"%d",&digit);             //convert to an integer value
            array[i][j] = digit;                //place in an array
            if(feof(one))return 0;              //return if end of file
        }
    }
}

int main(){

    int array[I][J];
    FILE *one;
    one = fopen("input9.txt","r");
    int risk_level = 0;
    int counter1 = 0;
    int counter2 = 0;

    get_numbers(one, array);
    fclose(one);

    for(int i=0; i<I; i++){                           //go thorugh each integer in the array
        for(int j=0; j<J; j++){
            counter1 = 0;                             //reset the counters
            counter2 = 0;
            if (i+1 < I){                             //if the integer location is not on the bottom edge
                counter1 ++;                          //increase the counter1
                if(array[i][j]<array[i+1][j]){        //if the current integer is smaller than its adjacent one on the bottom
                    counter2 ++;                      //increase the counter2
                }
            }
            if (i-1 >= 0){                            //if the integer location is not on the top edge
                counter1 ++;
                if(array[i][j]<array[i-1][j]){
                    counter2 ++;
                }
            }
            if (j+1 < J){                             //if the integer location is not on the right edge
                counter1 ++;
                if(array[i][j]<array[i][j+1]){
                    counter2 ++;
                }
            }
            if (j-1 >= 0){                           //if the integer location is not on the right edge
                counter1 ++;
                if(array[i][j]<array[i][j-1]){
                counter2 ++;
                }
            }
            if (counter1 == counter2){         //if both counters have the same value it means that all the adjacent integers were smaller than the current one
                risk_level = risk_level + 1 + array[i][j];  //add the value to the risk level + 1
            }
        }
    }

    printf("Risk level is:" "%d", risk_level);
    return 0;
}