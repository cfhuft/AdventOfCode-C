#include <stdio.h>

int main(){

    FILE *one;
    one = fopen("input2.txt","r");          //open the file with data for reading
    char first;
    char space = '1';
    int number = 0;
    int i = 0;
    int j = 0;
    printf("\nNumbers:\n");

    while (1){
        first = getc(one);                  //get the first character
        while(space != ' '){                //search for space before the number and get out of loop when found
            space = getc(one);
            if(feof(one)){break;}           //if end of file, break
        }
        if(feof(one)){break;}               //if end of file, break while(1)
        space = '1';                        //reset the space to '1' for next iteration use
        fscanf (one, " %d", &number);       //get the integer after space and assign it to &number
        if (first == 'd'){                  
            i+=number;                      //calculate the i and j (depth and hrizontal position) depending on the first character
        }else if (first == 'u'){
            i-=number;
        }else{
            j+=number;
        }
        first = getc(one);                  //get the newline character
    }

    printf("\nEnd of file.\n");

    printf("%d\n", i);
    printf("%d\n", j);
    printf("%d\n", i*j);

    fclose(one);
    return 0;
}