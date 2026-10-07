#include <stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    int out[x];
    for(int i=0;i<x;i++){
        int count = 0;
        int y;
        scanf("%d",&y);
        int arr[y];
        for(int j=0;j<y;j++){
            scanf("%d", &arr[j]);
        }
        for(int j=0;j<y-1;j++){
            if(arr[j] > arr[j+1]){
                count++;
            }
        }
        if(count == 0){
            out[i] = y;
        }
        else{
            out[i] = 1;
        }
    }
    for(int i=0;i<x;i++){
        printf("%d\n",out[i]);
    }
}
