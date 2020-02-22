
// Libraries to be added

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <time.h>
#include <fstream>

using namespace std;

// Struct to store values
struct subArray
{
    int max_left;
    int max_right;
    int sum;
};

subArray FIND_MAX_CROSSING_SUBARRAY(int *A, int low, int mid, int high);
subArray HYBRID_FIND_MAX_SUBARRAY(int *A, int low, int high);
subArray FIND_MAX_SUBARRAY_BRUTE_FORCE(int *A, int low, int high);
void RandomArray(int array[], int size);

int main()
{

    int size;
    cout << "Enter the Size of Array: ";
    cin >> size;
    int *A = new int[size];

    // To generate random Numbers and store them

    srand(time(NULL));
    RandomArray(A, size);

    // Code to call Recursive Max Array and measure time duration

    auto start = chrono::high_resolution_clock::now();
    subArray miniArr;
    miniArr = HYBRID_FIND_MAX_SUBARRAY(A, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Code to calculate the time duration

    time_taken *= 1e-9;
    cout << "\n\n Time taken by the Recursive max array, with " << size << " size of Array is: ";
    cout << fixed << time_taken << setprecision(9) << " seconds" << endl;

    // Output of the SubArray

    cout << "\nLeft Index is " << miniArr.max_left << endl;
    cout << "Right Index is " << miniArr.max_right << endl;
    cout << "Sum is " << miniArr.sum << endl;

    // Code to Save array in csv file

    /* ofstream OutData;
    OutData.open("hybrid-max-array.csv");
    for (int i = 0; i < size; i++)
        OutData << A[i] << endl; */

    delete[] A;
    return 0;
}

subArray HYBRID_FIND_MAX_SUBARRAY(int *A, int low, int high)
{
    int size = high - low + 1;
    if (size <= 37)

        return FIND_MAX_SUBARRAY_BRUTE_FORCE(A, low, high);

    else
    {
        int mid = floor((high + low) / 2);

        subArray leftArray;
        subArray rightArray;
        subArray crossArray;

        leftArray = HYBRID_FIND_MAX_SUBARRAY(A, low, mid);

        rightArray = HYBRID_FIND_MAX_SUBARRAY(A, mid + 1, high);

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
    int left_sum = A[mid], sum, max_left = mid;

    sum = A[mid];

    for (int i = mid - 1; i >= low; --i)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = A[mid + 1];
    int max_right = mid + 1, right_sum = A[mid + 1];

    for (int j = mid + 2; j <= high; ++j)
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
    miniArray.sum = left_sum + right_sum;

    return miniArray;
}

subArray FIND_MAX_SUBARRAY_BRUTE_FORCE(int *A, int low, int high)
{
    int max_sum = A[low];
    int size = high - low + 1;
    if (low != high)
    {
        for (int i = 0; i < size; ++i)
        {
            int sum = 0;
            for (int j = i; j < size; ++j)
            {
                sum += A[j];
                if (sum > max_sum)
                {
                    max_sum = sum;
                    low = i;
                    high = j;
                }
            }
        }
    }
    subArray miniArray;
    miniArray.max_left = low;
    miniArray.max_right = high;
    miniArray.sum = max_sum;

    return miniArray;
}

// RandomArray Function to fill the array with random numbers
void RandomArray(int array[], int size)
{

    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
        if (i % 2 == 0)
            array[i] *= -1;
    }
}
