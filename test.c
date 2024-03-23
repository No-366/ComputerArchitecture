#include<stdio.h>

int main(int argc, char* argv[]){

    printf("Title : \n");

    FILE *fp_in = NULL;
    char* PROGRAM = argv[1];
    int line_size = 1024;
    int program_size = 0x8000;
    int i = 0;
    char line[line_size];
    char Memory[program_size][line_size];

    // check if there is input.txt 
    fp_in = fopen(PROGRAM, "r");
    if (fp_in == NULL) {
        printf("program not found\n");
        exit(0);
    }
    fgets(line, sizeof(line), fp_in);
    strcpy(Memory[i], line);
    printf("FET: %s\n", Memory[i]);

    
    //close the input.txt
    fclose(fp_in);





    return 0;

}