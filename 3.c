#include <stdio.h>

int main(){

    FILE *one;
    one = fopen("input3.txt","r");          //open the file with data for reading
    int array [12] = {0};
    int i = -1;
    char current;
    int gamma = 0;

    while(!feof (one)){
        for(i=0; i<12; i++){                //12 numbers in a line      
            current = getc(one);            //get a character   
            if (current=='0'){              //if '0'
                array[i]-=1;                //count down and store the result into an array
            }else if (current=='1'){        
                array[i]+=1;                //if '1' count up and store the result
            }
        }  
        current = getc(one);                // get \n
        i=0;                                // reset the counter for the next line
    }

    for(i=0; i<12; i++){                    //for the 12 numbers stored in an array
        if(array[i]>0){                     //check if a number is positive
            gamma = gamma<<1;               //bit shift to left
            gamma=gamma|1;                  //OR 1 bit
        }else{gamma = gamma<<1;}            //othervise just left shift (0)
        
    }
    int epsilon= ~gamma&4095;               //Bitwise complement and mask to get the epsilon value
    printf("%d", gamma*epsilon);            //power consumption
    fclose(one);
    return 0;
}