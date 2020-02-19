#include <iostream>
using namespace std;
struct subArray{
    int max_left;
    int max_right;
    int sum;
};
subArray* FIND_MAX_CROSSING_SUBARRAY(int* A, int low, int mid, int high);
subArray* FIND_MAX_SUBARRAY(int* A, int low, int high);
int main(){
    

}
subArray* FIND_MAX_CROSSING_SUBARRAY(int* A, int low, int mid, int high){
    int left_sum = -10000, sum = 0, max_left, max_right, right_sum = -10000;
    for (int i = mid; i >= low; --i)
    {
        sum+= A[i];
        if(sum>left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int j = mid+1; j <= high; ++j)
    {
            sum+= A[j];
            if(sum>right_sum){
                right_sum = sum;
                max_right = j;
            }
    }
    
    subArray *miniArray = new subArray;
    miniArray->max_left = max_left;
    miniArray->max_right = max_right;
    miniArray->sum = sum;

    return miniArray;
}

subArray* FIND_MAX_SUBARRAY(int* A, int low, int high){
    int left_sum = -10000, sum = 0, max_left, max_right, right_sum = -10000;
    if(high == low){
        subArray *miniArray = new subArray;
        miniArray->max_left = low;
        miniArray->max_right = high;
        miniArray->sum = A[low];
        return miniArray;
    }else
    {
        int mid = floor((high+low)/2);

        subArray* leftArray = new subArray;
        leftArray = FIND_MAX_SUBARRAY(A, low, mid); 

        subArray* rightArray = new subArray;
        rightArray = FIND_MAX_SUBARRAY(A, mid+1 , high);

        subArray* crossArray = new subArray;
        crossArray = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high);  

        if(leftArray->sum >= rightArray->sum && leftArray->sum >= crossArray->sum)
            return leftArray;
            
        else if(rightArray->sum >= leftArray->sum && rightArray->sum >= crossArray->sum)
            return rightArray;
            
        else
            return crossArray;
    }
    

}
