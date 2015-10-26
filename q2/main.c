#include <stdio.h>
#include <time.h>
#include <assert.h>

char smallest_character(char str[], char c);

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

    char str[6] = "cfjpv";
    char str2[26] = "abcdefghijklmnopqrstuvwxyz";
    assert(smallest_character(str, 'a') == 'c');
    assert(smallest_character(str, 'c') == 'f');
    assert(smallest_character(str, 'z') == 'c');
    assert(smallest_character(str, 'q') == 'v');
    assert(smallest_character(str2, 'a') == 'b');
    assert(smallest_character(str2, 'b') == 'c');
    assert(smallest_character(str2, 'x') == 'y');
    assert(smallest_character(str2, 'y') == 'z');
    assert(smallest_character(str2, 'z') == 'a');
    assert(smallest_character(0, 'a') == 0);
    assert(smallest_character(NULL, 'a') == 0);

    clock_gettime(CLOCK_REALTIME, &start);
    smallest_character(str, 'a');
    smallest_character(str, 'c');
    smallest_character(str, 'z');
    smallest_character(str, 'q');
    smallest_character(str2, 'a');
    smallest_character(str2, 'b');
    smallest_character(str2, 'x');
    smallest_character(str2, 'y');
    smallest_character(str2, 'z');
    smallest_character(0, 'a');
    smallest_character(NULL, 'a');
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diffTime(start, end);
    printf("execution time of smallest_character() : %ld.%09ld sec\n", (long)cpu_time.tv_sec, cpu_time.tv_nsec);
    return 0;
}
