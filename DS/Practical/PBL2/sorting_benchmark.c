// PBL-II : Sorting Algorithm Speed Test Bench
//
// Generates random datasets of various sizes (1000 to 10000) and measures the
// execution time (in milliseconds) of Bubble, Insertion, Selection, Merge and
// Quick sort. The results are printed as a table and written to results.csv,
// which is later plotted in Excel by generate_report.py.

#if defined(_WIN32)
#define _CRT_SECURE_NO_WARNINGS
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32)
#include <windows.h>
#else
#include <time.h>
#endif

#define START_SIZE 1000
#define END_SIZE 10000
#define STEP_SIZE 1000
#define REPETITIONS 3
#define VALUE_LIMIT 1000000

// Returns the current monotonic clock value in milliseconds.
//
// Uses the Windows high-resolution performance counter on Windows (MSVC and
// MinGW) and the POSIX monotonic clock everywhere else.
static double now_ms(void)
{
#if defined(_WIN32)
    static LARGE_INTEGER frequency;
    static int initialized = 0;
    LARGE_INTEGER counter;

    if (!initialized)
    {
        QueryPerformanceFrequency(&frequency);
        initialized = 1;
    }

    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart * 1000.0 / (double)frequency.QuadPart;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec * 1000.0 + (double)ts.tv_nsec / 1000000.0;
#endif
}

static void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

static void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

static void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

static void merge_sort_recursive(int arr[], int temp[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(arr, temp, left, mid);
        merge_sort_recursive(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

static void merge_sort(int arr[], int n)
{
    int *temp = (int *)malloc((size_t)n * sizeof(int));
    if (temp == NULL)
    {
        return;
    }
    merge_sort_recursive(arr, temp, 0, n - 1);
    free(temp);
}

static void quick_sort_recursive(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        quick_sort_recursive(arr, low, i);
        quick_sort_recursive(arr, i + 2, high);
    }
}

static void quick_sort(int arr[], int n)
{
    quick_sort_recursive(arr, 0, n - 1);
}

// ---------------------------------------------------------------------------
// Algorithm registry
//
// To add a new algorithm:
//   1. Write a sorting function with the signature `void name(int arr[], int n)`
//      that sorts arr[0..n-1] in ascending order.
//   2. Add one entry { "name", name } to the `algorithms` array in main().
// The name is used both for the console table and the CSV header, so keep it
// short and free of commas.
// ---------------------------------------------------------------------------
typedef void (*sort_fn)(int[], int);

typedef struct
{
    const char *name;
    sort_fn function;
} algorithm_t;

// Measures the average time (ms) taken by one algorithm over the given number
// of repetitions. The source data is copied into a work buffer before every
// run so that each algorithm always receives identical, unsorted input.
static double benchmark(sort_fn function, const int source[], int n)
{
    int *work = (int *)malloc((size_t)n * sizeof(int));
    if (work == NULL)
    {
        return 0.0;
    }

    double total = 0.0;
    for (int r = 0; r < REPETITIONS; r++)
    {
        memcpy(work, source, (size_t)n * sizeof(int));
        double start = now_ms();
        function(work, n);
        total += now_ms() - start;
    }

    free(work);
    return total / REPETITIONS;
}

int main(void)
{
    const algorithm_t algorithms[] = {
        {"bubble", bubble_sort},
        {"insertion", insertion_sort},
        {"selection", selection_sort},
        {"merge", merge_sort},
        {"quick", quick_sort},
    };
    const int algorithm_count = (int)(sizeof(algorithms) / sizeof(algorithms[0]));

    FILE *csv = fopen("results.csv", "w");
    if (csv == NULL)
    {
        fprintf(stderr, "Error: could not open results.csv for writing.\n");
        return 1;
    }

    fprintf(csv, "size");
    for (int a = 0; a < algorithm_count; a++)
    {
        fprintf(csv, ",%s", algorithms[a].name);
    }
    fprintf(csv, "\n");

    printf("Sorting Algorithm Speed Test Bench\n");
    printf("Repetitions per algorithm: %d\n\n", REPETITIONS);
    printf("%8s", "Size");
    for (int a = 0; a < algorithm_count; a++)
    {
        printf("%14s", algorithms[a].name);
    }
    printf("\n");

    srand(12345);

    for (int n = START_SIZE; n <= END_SIZE; n += STEP_SIZE)
    {
        int *data = (int *)malloc((size_t)n * sizeof(int));
        if (data == NULL)
        {
            fprintf(stderr, "Error: out of memory for size %d.\n", n);
            fclose(csv);
            return 1;
        }

        for (int i = 0; i < n; i++)
        {
            data[i] = rand() % VALUE_LIMIT;
        }

        printf("%8d", n);
        fprintf(csv, "%d", n);

        for (int a = 0; a < algorithm_count; a++)
        {
            double time_ms = benchmark(algorithms[a].function, data, n);
            printf("%14.3f", time_ms);
            fprintf(csv, ",%.3f", time_ms);
        }

        printf("\n");
        fprintf(csv, "\n");
        free(data);
    }

    fclose(csv);
    printf("\nTimes are in milliseconds (average of %d runs).\n", REPETITIONS);
    printf("Results saved to results.csv\n");
    return 0;
}
