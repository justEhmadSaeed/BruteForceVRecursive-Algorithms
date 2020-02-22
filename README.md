# BruteForce VS Recursive Algorithms

### We applied three techniques⚡ to tackle the problem of finding the Subarray of an array, which holds the maximum sum of the whole array.

- ## Brute Force Algorithm
        subArray FIND_MAX_SUBARRAY_BRUTE_FORCE(int *A, int low, int high);
- ## Recursive Algorithm
        subArray FIND_MAX_SUBARRAY(int *A, int low, int high);
        subArray FIND_MAX_CROSSING_SUBARRAY(int *A, int low, int mid, int high);

- ## Hybrid Recursive-BruteForce Algorithm
        subArray HYBRID_FIND_MAX_SUBARRAY(int *A, int low, int high);
        subArray FIND_MAX_CROSSING_SUBARRAY(int *A, int low, int mid, int high);
        subArray FIND_MAX_SUBARRAY_BRUTE_FORCE(int *A, int low, int high);
