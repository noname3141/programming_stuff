#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    int operations[t];
    for(int i = 0; i < t; i++){
        int m;
        scanf("%d", &m);
        int arr[m];
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[j]);
        }
        int op = 0;
        for(int j = 0; j < m; j++){
            if(arr[j] == -1){
                continue;
            }
            if(arr[j] == 0){
                arr[j] = -1;
                op++;
                continue;
            }
            else if(arr[j] == 2){
                for(int k = j + 1; k < m; k++){
                    int br = 0;
                    if(arr[k] == -1){
                        continue;
                    }
                    if(arr[k] == 1){
                        arr[j] = -1;
                        arr[k] = -1;
                        op++;
                        break;
                    }
                    else if(arr[k] == 2){
                        for(int x = k + 1; x < m; x++){
                            if(arr[x] == -1){
                                continue;
                            }
                            if(arr[x] == 2){
                                arr[j] = -1;
                                arr[k] = -1;
                                arr[x] = -1;
                                op++;
                                br = 1;
                                break;
                            }
                        }
                        if(br == 1){
                            break;
                        }
                    }
                }
            }
            else if(arr[j] == 1){
                for(int k = j + 1; k < m; k++){
                    int br = 0;
                    if(arr[k] == -1){
                        continue;
                    }
                    if(arr[k] == 2){
                        arr[j] = -1;
                        arr[k] = -1;
                        op++;
                        break;
                    }
                    else if(arr[k] == 1){
                        for(int x = k + 1; x < m; x++){
                            if(arr[x] == -1){
                                continue;
                            }
                            if(arr[x] == 1){
                                arr[j] = -1;
                                arr[k] = -1;
                                arr[x] = -1;
                                op++;
                                br = 1;
                                break;
                            }
                        }
                        if(br == 1){
                            break;
                        }
                    }
                }
            }
        }
        operations[i] = op;
    }
    for(int j = 0; j < t; j++){
        printf("%d\n", operations[j]);
    }
}
