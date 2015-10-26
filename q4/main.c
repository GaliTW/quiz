#include <assert.h>
#include <stdio.h>
#include <time.h>

int maxSubArray(int A[], int n);

static struct timespec diffTime(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return diff;
}

int main()
{
    struct timespec start, end;
    struct timespec cpu_time;

    int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int A2[9] = {5, -3, 7, -2, 6, -8, 1, 3, -5};
    int *A3 = &A2[3];
    int A4[14] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7};

    assert(6 == maxSubArray(A, 9));
    assert(4 == maxSubArray(A, 5));
    assert(1 == maxSubArray(A, 3));
    assert(13 == maxSubArray(A2, 9));
    assert(13 == maxSubArray(A2, 5));
    assert(6 == maxSubArray(A3, 6));
    assert(7 == maxSubArray(A4, 14));

    clock_gettime(CLOCK_REALTIME, &start);
    maxSubArray(A, 9);
    maxSubArray(A, 5);
    maxSubArray(A, 3);
    maxSubArray(A2, 9);
    maxSubArray(A2, 5);
    maxSubArray(A3, 6);
    maxSubArray(A4, 14);
    maxSubArray(A4, 7);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diffTime(start, end);

    printf("execution time of maxSubArray() : %ld.%09ld sec\n", (long)cpu_time.tv_sec, cpu_time.tv_nsec);
    return 0;
}
