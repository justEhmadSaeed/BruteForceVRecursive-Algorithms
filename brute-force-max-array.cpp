
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
subArray *FIND_MAX_SUBARRAY_BRUTE_FORCE(int *A, int size);
void RandomArray(int array[], int size);

int main()
{
    int size = 16;
    // cout << "Enter the Size of Array: ";
    // cin >> size;
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int *A = arr;

    // To generate random Numbers and store them

    srand(time(NULL));
    RandomArray(A, size);
    // Code to call Recursive Max Array and measure time duration

    //auto start = chrono::high_resolution_clock::now();
    subArray *miniArr;
    miniArr = FIND_MAX_SUBARRAY_BRUTE_FORCE(A, size);
    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Code to calculate the time duration

    /* time_taken *= 1e-9;
    cout << "\n Time taken by the recursive max array, with " << size << " size of Array is: ";
    cout << fixed << time_taken << setprecision(9) << " seconds" << endl; */

    cout << "Left Index is " << miniArr->max_left << endl;
    cout << "Right Index is " << miniArr->max_right << endl;
    cout << "Sum is " << miniArr->sum << endl;

    // Code to Save array in csv file

    ofstream OutData;
    OutData.open("recursive-max-array.csv");
    for (int i = 0; i < size; i++)
        OutData << A[i] << endl;

    delete[] A;
    return 0;
}
subArray *FIND_MAX_SUBARRAY_BRUTE_FORCE(int *A, int size)
{
    int low, high, sum = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j <= size; ++j)
            if (A[j] - A[i] > sum)
            {
                sum = A[j] - A[i];
                low = i;
                high = j;
            }
    }

    subArray *miniArray = new subArray;
    miniArray->max_left = low;
    miniArray->max_right = high;
    miniArray->max_right = sum;
    return miniArray;
}

// RandomArray Function to fill the array with random numbers
void RandomArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand();
}