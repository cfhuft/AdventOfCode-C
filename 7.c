#include <stdio.h>
#include <math.h>
#include <ctype.h>

int calcualte_fuel(FILE *one, int reference_crab){                      //calcualte the fuel for a reference crab on a certain position 
    int secondary_crab=0, fuel=0, c, digit;
    fseek(one, 0, 0);                                                   //reset the file stream to 0

    while(!feof(one)){
        c=fgetc(one);
        if (isdigit(c)){
            sscanf(&c,"%d",&digit);
            secondary_crab = secondary_crab*10 + digit;
        }else if (c==','|| c==-1){                                      //if comma or EOF
            fuel = fuel + abs(reference_crab-secondary_crab);           //summate the fuel required for the distance between crabs
            secondary_crab=0;                                           //reset the number for the new secondary crab
        }
    }

    return fuel; 
}

int main(){

    FILE *one;
    one = fopen("input7.txt","r");
    int c=0, reference_crab=0, digit=0, file_stream=0, fuel, lowest_fuel=0;

    while(1){
        c=fgetc(one);                                               //get a character from file
        if (isdigit(c)){                                            //if it is a digit
            sscanf(&c,"%d",&digit);                                 //change to an integer
            reference_crab = reference_crab*10 + digit;             //multiple digits position
            file_stream=ftell(one);                                 //save the file stream number
        }else if (c==',' || c==-1){                                 //else if comma or EOF
            file_stream=ftell(one);                                 //save the file stream number
            fuel = calcualte_fuel(one, reference_crab);             //calculate fuel requirements for a reference crab
            reference_crab=0;
            if (lowest_fuel>fuel || lowest_fuel == 0){              //keep updating the lowest fuel number
                lowest_fuel = fuel;
            }    
        }
        fseek(one, file_stream, SEEK_SET);                          //set the file stream to the saved number to set the next reference crab
        if(c==-1)break;                                             //break if EOF
    }

    printf("\n%d ", lowest_fuel);
    fclose(one);
}