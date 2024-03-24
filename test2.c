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
    int PC = -1;
    int top = -1;

    fp_in = fopen(PROGRAM, "r");
    
    if (fp_in == NULL) {
        printf("program not found\n");
        exit(0);
    }
    
    
    //메모리에 프로그램 로드
   
    while(fgets(prog_line, sizeof(prog_line), fp_in)!=NULL){
        top++;
        prog_line[strlen(prog_line) - 1] = '\0';
        printf("prog_line : %s\n", prog_line);
        strcpy(Memory[top], prog_line);
        printf("Memory[%d] : %s\n", top, Memory[top]);
        printf("\n");
        
    }
  

    printf("PC is now in %d\n",PC);
    printf("\n");
    // close the input.txt
    fclose(fp_in);


//////////////////////////////////////////////////////////////////
    char IR[1024];

//메모리에 로드된 프로그램을 한줄 씩 IR에 로드 -> fetch
    while(PC < top){
        PC++;
        strcpy(IR, Memory[PC]);
        printf("IR : %s\n", IR);
        printf("PC is now in %d\n",PC);
        printf("\n");
       
    }





    return 0;

}

/*
연산 종류 : 5가지
사칙연산 : ADD, SUB, MUL, DIV
Move : MOV
instruction 형식 : i형식, r형식 2가지
i형식 : imm,imm 또는 reg,imm
r형식 : reg,reg
*/