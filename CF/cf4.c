#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    int sec[t];
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int x1;
        scanf("%d", &x1);
        int x2;
        scanf("%d", &x2);
        int k;
        scanf("%d", &k);
        if(x1 > x2){
            if(k > x2){
                sec[i] = x1;
            }
            else{
                sec[i] = k + x1 - x2;
            }
        }
        else if(x1 < x2){
            if(k > n - x2){
                sec[i] = n - x1;
            }
            else{
                sec[i] = k + x2 - x1;
            }
        }
        else{
            sec[i] = 0;
        }
    }
    for(int j = 0; j < t; j++){
        printf("%d\n", sec[j]);
    }
}
