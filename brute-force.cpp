#include <iostream>
using namespace std;
struct subArray{
    int max_left;
    int max_right;
    int sum;
};
subArray* FIND_MAX_CROSSING_SUBARRAY(int* A, int low, int mid, int high);
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
