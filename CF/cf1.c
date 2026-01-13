#include <stdio.h>
int main(){
    int i,num;
    scanf("%d", &num);                                                                                                                                                                                               
    int nums[num];
    for(i=0;i<num;i++){
        int n;
        scanf("%d", &n);
        if(n>3){
            if(n%2 == 0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }
        else{
            nums[i] = n;
        }
    }
    for(i=0;i<num;i++){
        printf("%d\n", nums[i]);
    }
}
