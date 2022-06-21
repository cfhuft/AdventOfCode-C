#include <stdio.h>

int main(){

    FILE *one;
    one = fopen("input.txt","r");     //open the file with data for reading
    int current=0;
    int previous = 0;
    int i = -1;

    printf("\nNumbers:\n");


    while (!feof (one))               //while not at the end of file
    {  
      fscanf (one, "%d", &current);   //get the integer and assign it to &current
      if (current > previous){        //if the current number is bigger than previous
        i++;                          //increase the counter
      }
      previous = current;
    }
    printf ("%d ", i);                //how many times the current number was bigger than previous
    printf("\nEnd of file.\n");

    fclose(one);
    return 0;
}