#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int init(char *fileName){

    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        file = fopen(fileName, "w");
        fclose(file);
        file = fopen(fileName, "r");
        fclose(file);
        return -100;
    }


}

void inputEditor(char *fileName){
    char c;
    while(1){
        c = _getch();

        //debug
        // printf("Key: %d\n", c);

        if(c == 17){ //Save
            printf("keluar...\n");
            break;
        }else{

            printf("%c", c);

        }
    }
}

int main(){

    int hasil = init("file baru.txt");
    printf("%d\n", hasil);

    inputEditor("file.txt");

    return 0;
}