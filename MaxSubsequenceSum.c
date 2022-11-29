#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bruteForce(int*,int);
int MaxOfThree(int,int,int);
int CalculateMaxSum(int*,int,int,int);
int MaxGain(int*,int,int);

#define MIN_INT -2147483647



int main(){
    int i,N;
    int* gain_arr;

    printf("Number of blocks: ");
    scanf("%d",&N);

    gain_arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        printf("%d. eleman: ",i);
        scanf("%d",&gain_arr[i]);
    }


    bruteForce(gain_arr,N);
    printf("\nDivide And Conquer Approach: %d\n",MaxGain(gain_arr,0,N-1));
    
    return 0;
}
/////////////////////Brute Force Approach////////////////////////////////////////////////////

void bruteForce(int* gains,int N){
    int i,j;                        //loop variables
    int start=0,end=0,sum=0,max=MIN_INT; //start&end->Limit points, sum->current sum, max->max sum

    for(i=0;i<N;i++){               //start point
        sum=0;
        for(j=i;j<N;j++){           //end point
            sum+=gains[j];
            if(sum>max){            //compares that if current sum value bigger than max
                max=sum;
                start=i;    
                end=j;
            }
        }
    }
    printf("%d--> %d to %d",max,start,end);
}

////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////Divide & Conquer Approach///////////////////////////

//find the greatest integer of three-->used to find max sum in divide and conquer approach
int MaxOfThree(int a,int b,int c){
    if(a>b){
        if(a>c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b>c){
            return b;
        }else{
            return c;
        }
    }
}


int MaxGain(int* gain, int start,int end){
    int mid;
    
    if(end<start){  //to detect false input
        return -1;
    }

    if(start==end){ //stop point of recursive func
        return gain[start];
    }

    mid=(start+end)/2;

    //detect greatest of start to mid,mid to end, and their mid included versions 
    return MaxOfThree(MaxGain(gain,start,mid-1),MaxGain(gain,mid+1,end),CalculateMaxSum(gain,start,mid,end));
}

//calculate max sum with mid included
int CalculateMaxSum(int* gain, int start, int mid, int end){
    int i,sum=0;
    int left_sum=MIN_INT; //max_sum of start to mid
    int right_sum=MIN_INT; //max_sum of mid to end

    for(i=mid;i>=start;i--){ //mid to start
        sum+=gain[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }
    //            start<--------mid-------->end
    sum=0;
    for(i=mid;i<=end;i++){  //mid to end
        sum+=gain[i];
        if(sum>right_sum){
            right_sum=sum;
        }
    }

    //total, left or right
    return MaxOfThree((left_sum+right_sum-gain[mid]), left_sum, right_sum);
}
