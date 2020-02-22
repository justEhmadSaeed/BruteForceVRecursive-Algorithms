
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

// Prototpyes
subArray FIND_MAX_SUBARRAY_BRUTE_FORCE(int *A, int low, int high);
void RandomArray(int array[], int size);

int main()
{
    int size = 8;
    cout << "Enter the Size of Array: ";
    cin >> size;
    int *A = new int[size];

    // To generate random Numbers and store them

    srand(time(NULL));
    RandomArray(A, size);

    // Code to call Brute Force and measure time duration

    auto start = chrono::high_resolution_clock::now();
    subArray miniArr;
    miniArr = FIND_MAX_SUBARRAY_BRUTE_FORCE(A, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Code to calculate the time duration

    time_taken *= 1e-9;
    cout << "\n\nTime taken by the Brute Force Algorithm, with " << size << " size of Array is: ";
    cout << fixed << time_taken << setprecision(9) << " seconds" << endl;

    // Output of the SubArray

    cout << "\nLeft Index is " << miniArr.max_left << endl;
    cout << "Right Index is " << miniArr.max_right << endl;
    cout << "Sum is " << miniArr.sum << endl;

    // Code to Save array in csv file

    ofstream OutData;
    OutData.open("brute-force-max-array.csv");
    for (int i = 0; i < size; i++)
        OutData << A[i] << endl;

    delete[] A;
    return 0;
}

// Brute Force Max Sum Array
subArray FIND_MAX_SUBARRAY_BRUTE_FORCE(int *A, int low, int high)
{
    int max_sum = A[low];
    int size = high - low + 1;

    // if size is greater than one
    if (high != low)
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

    // Storing value in Struct
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
