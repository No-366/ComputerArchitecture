#include<stdio.h>

// 메모리에 프로그램 로드
// Instruction Register에 프로그램의 각 명령어를 로드 -> fetch
// IR에 있는 명령어를 decode
// decode한 명령어를 execute
// execute한 명령어의 결과를 저장 
// pc++


int main(int argc, char* argv[]){

    printf("Test2 Start : \n");

    FILE *fp_in = NULL;
    char* PROGRAM = argv[1];
    char prog_line[1024];
    char Memory[100][1024] = {-1,};
    int PC = 0;

    fp_in = fopen(PROGRAM, "r");
    
    if (fp_in == NULL) {
        printf("program not found\n");
        exit(0);
    }
    
    
    //메모리에 프로그램 로드
    int i = 0;
    while(fgets(prog_line, sizeof(prog_line), fp_in)!=NULL){
        prog_line[strlen(prog_line) - 1] = '\0';
        printf("prog_line : %s\n", prog_line);
        strcpy(Memory[i], prog_line);
        printf("Memory[%d] : %s\n", i, Memory[i]);
        printf("\n");
        i++;
    }

    // close the input.txt
    fclose(fp_in);


//////////////////////////////////////////////////////////////////



    // char IR[1024] = NULL;
    // for(int i = 0; Memory[i] != NULL; i++){
    //     //fetch
    //     strcpy(IR, Memory[i]);
    //     printf("IR %d : %s\n",i, IR);

    //     //decode
    //     //Instruction = decode();

    //     //execute
    //     //execute(Instruction);


    // }



    return 0;

}