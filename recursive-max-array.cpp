
// Libraries to be added

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
//#include <chrono>
#include <time.h>
#include <fstream>

using namespace std;
struct subArray
{
    int max_left;
    int max_right;
    int sum;
};
subArray FIND_MAX_CROSSING_SUBARRAY(int *A, int low, int mid, int high);
subArray FIND_MAX_SUBARRAY(int *A, int low, int high);
void RandomArray(int array[], int size);

int main()
{

    int size = 16;
    cout << "Enter the Size of Array: ";
    cin >> size;
    int *A = new int[size];

    // To generate random Numbers and store them

    srand(time(NULL));
    RandomArray(A, size);
    // Code to call Recursive Max Array and measure time duration

    //auto start = chrono::high_resolution_clock::now();
    subArray miniArr;
    miniArr = FIND_MAX_SUBARRAY(A, 0, size - 1);
    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Code to calculate the time duration

    /* time_taken *= 1e-9;
    cout << "\n Time taken by the recursive max array, with " << size << " size of Array is: ";
    cout << fixed << time_taken << setprecision(9) << " seconds" << endl; */

    cout << "Left Index is " << miniArr.max_left << endl;
    cout << "Right Index is " << miniArr.max_right << endl;
    cout << "Sum is " << miniArr.sum << endl;

    // Code to Save array in csv file

    ofstream OutData;
    OutData.open("recursive-max-array.csv");
    for (int i = 0; i < size; i++)
        OutData << A[i] << endl;

    delete[] A;
    return 0;
}

subArray FIND_MAX_SUBARRAY(int *A, int low, int high)
{
    int left_sum = -14748369, sum = 0, max_left, max_right, right_sum = -1474836;
    if (high == low)
    {
        subArray miniArray;
        miniArray.max_left = low;
        miniArray.max_right = high;
        miniArray.sum = A[low];
        return miniArray;
    }
    else
    {
        int mid = floor((high + low) / 2);

        subArray leftArray;
        leftArray = FIND_MAX_SUBARRAY(A, low, mid);

        subArray rightArray;
        rightArray = FIND_MAX_SUBARRAY(A, mid + 1, high);

        subArray crossArray;
        crossArray = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high);

        if (leftArray.sum >= rightArray.sum && leftArray.sum >= crossArray.sum)
            return leftArray;

        else if (rightArray.sum >= leftArray.sum && rightArray.sum >= crossArray.sum)
            return rightArray;

        else
            return crossArray;
    }
}

subArray FIND_MAX_CROSSING_SUBARRAY(int *A, int low, int mid, int high)
{
    int left_sum = -10000, sum = 0, max_left, max_right, right_sum = -10000;
    for (int i = mid; i >= low; --i)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int j = mid + 1; j <= high; ++j)
    {
        sum += A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }

    subArray miniArray;
    miniArray.max_left = max_left;
    miniArray.max_right = max_right;
    miniArray.sum = sum;

    return miniArray;
}

// RandomArray Function to fill the array with random numbers
void RandomArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand();
}
