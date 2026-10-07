#include <stdio.h>
 
int main(){
    int x;
    scanf("%d",&x);
    for(int i=0; i < x;i++){
        if(i%2 == 0 && (x-i)%2 == 0 && i != 0){
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}
