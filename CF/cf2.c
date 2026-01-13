#include <stdio.h>

int main(){
    int num,i;
    scanf("%d", &num);
    int nums[num];
    for(i=0;i<num;i++){
        int s, k, time;
        scanf("%d %d %d", &s, &k, &time);
        int j=1, temp;
        while(j*k <= time){
            j++;
        }
        if(j%2 != 0){
            temp = s - (time % k);
            if(k <= s){
                nums[i] = temp;
            }
            else{
                if(temp - time >= 0){
                    nums[i] = temp - time;
                }
                else{
                    nums[i] = 0;
                }
            }
        }
        else{
            temp = k - (time % k);
            if(k <= s){
                nums[i] = temp;
            }
            else{
                if(temp - time >= 0){
                    nums[i] = temp - time;
                }
                else{
                    nums[i] = 0;
                }
            }
        }
    }
    for(i=0;i<num;i++){
        printf("%d\n", nums[i]);
    }
}
