#include <stdio.h>

int main(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int nor = (z*x*y)/100;
    for(int i = 0; i<x; i++){
        if(nor > y){
            printf("%d ", y);
            nor -= y;
        }
        else{
            printf("%d ", nor);
            nor = 0;
        }
    }
    printf("\n");
}
