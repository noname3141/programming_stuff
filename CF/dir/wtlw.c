#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main(){
    int a;
    scanf("%d",&a);
    char x[SIZE];
    char out[a][11];
    for(int i=0;i<a;i++){
        scanf("%s", x);
        int j=0;
        while(x[j] != '\0'){
            j++;
        }
        if(j > 10){
            snprintf(out[i], sizeof(out[i]), "%c%d%c", x[0], j-2, x[j-1]); 
        }
        else{
            int k = 0;
            for(k = 0; k<j;k++){
                out[i][k] = x[k];
            }
            out[i][k] = '\0';
        }
    }
    for(int i=0;i<a;i++){
        for(int j = 0;j<strlen(out[i]); j++){
            printf("%c", out[i][j]);
        }
        printf("\n");
    }

}
