#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int count1 = 0;
int count2 = 0;

int getChange(char* input){
    char first = input[0];
    input[0] = '0';
    int change = atoi(input);
    if(first == 'L')
        change *= -1;
    return change;
}
int main(int argc, char* argv[]){

    int rotation = 50;
    int change = 0;
    FILE* hithere = fopen("./d1.txt", "r");

    char leng[6];
    while(fgets(leng, 6, hithere)){
        change= getChange(leng);
        if(!change)
            continue;
        rotation+= change;
        if(rotation == 0)
            count2++;
        else if((rotation-change > 0 && rotation < 0) || (rotation-change < 0 && rotation > 0))
            count2++;
        while(rotation > 99){
            rotation-=100;
            count2++;
        }
        while(rotation < -99){
            rotation+=100;
            count2++;
        }
        if(rotation == 0)
            count1++;
        
        //printf("%s %d %d\n", leng, rotation, count);
    }
    fclose(hithere);

    printf("total count p1: %d\ntotal count p2: %d", count1, count2);

    return 0;
}