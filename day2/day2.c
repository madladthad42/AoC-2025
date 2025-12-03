#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>


long int checkRange(long int start, long int end){
    long int total = 0;
    int length;
    for(long int i = start; i <= end; i++){
        length = floor(log10(abs(i))) + 1;  // find number of digits.
        if(length % 2 == 1) continue;       // if it's on an odd length then we bail
        length = pow(10, (length/2));       // lets us split the number in half
        if(i/length == i % length){         // if the first half matches the last half
            total+= i;                      // boost the total by the ID
            //printf("%ld\n", i);
        }
    }
    return total;
}

int main(){

    FILE* hithere = fopen("./d2.txt", "r");

    long int first, last;
    long int total = 0;
    while(fscanf(hithere, "%ld-%ld", &first, &last) == 2){
        printf("%ld-%ld\n", first, last);
        total+= checkRange(first, last);
        //printf("%ld\n", total);
        first = fscanf(hithere, ",");
    }

    fclose(hithere);
    printf("total IDs: %ld", total);    

    return 1;
}