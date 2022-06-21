#include <stdio.h>
#include <ctype.h>

int count_the_fish(int age, int days, int* count){
    
    for(int i=0; i<=age; i++){                          //count down the expiration age of the fish by days
       days++;                                          //day +1
       if (days>80){return 0;}                          //if there is 80 or more days total, return from the function
    }
    count_the_fish(6, days, count);                     //when the fish age expires reset the expiration age for the same fish and continue counting the days from where it left off
    *count+=1;                                          // +1 fish
    return (count_the_fish(8, days, count));            //spawn new fish with expiration age 8
}


int main(){

    FILE *one;
    one = fopen("input6.txt","r");
    int count=0, c=0, age=0, days=0;

    while(!feof(one)){
        c=fgetc(one);
        if (isdigit(c)){
            sscanf(&c,"%d",&age);                       //convert to integer number
            count+=1;                                   //+1 fish from the input list
            count_the_fish(age, days, &count);          //count the fish
        }
    }
    printf("\n%d ", count);
    fclose(one);
}