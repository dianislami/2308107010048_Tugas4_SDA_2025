#include "sort_algorithms.h"


// =====================
// BUBBLE SORT
// =====================

// Bubble Sort untuk integer
void bubble_sort(int arr[], int n) {
    // Bandingkan pasangan elemen bersebelahan dan tukar jika urutannya salah
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
        }
    }
}
// Bubble Sort untuk string (array of char pointers)
void bubble_sort_string(char *arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Gunakan strcmp untuk membandingkan string
            if (strcmp(arr[j], arr[j+1]) > 0) {
                char *temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
        }
    }
}



// =====================
// SELECTION SORT
// =====================

// Selection Sort untuk integer
void selection_sort(int arr[], int n) {
    // Menemukan elemen terkecil dan menempatkannya di depan
    for (int i = 0; i < n-1; i++) {
        int min = i;
        // Cari elemen terkecil dalam sisa array
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        // Tukar elemen terkecil ke posisi saat ini
        int temp = arr[min]; arr[min] = arr[i]; arr[i] = temp;
    }
}
// Selection Sort untuk string
void selection_sort_string(char *arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (strcmp(arr[j], arr[min]) < 0) min = j;
        }
        char *temp = arr[min]; arr[min] = arr[i]; arr[i] = temp;
    }
}


// =====================
// INSERTION SORT
// =====================

// Insertion Sort untuk integer
void insertion_sort(int arr[], int n) {
    // Menyisipkan elemen pada posisi yang benar
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        // Geser elemen yang lebih besar ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]; j--;
        }
        arr[j+1] = key;
    }
}

// Insertion Sort untuk string
void insertion_sort_string(char *arr[], int n) {
    for (int i = 1; i < n; i++) {
        char *key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


// =====================
// MERGE SORT
// =====================

// Fungsi bantu merge untuk integer
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Gunakan heap allocation untuk array L dan R
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Gagal alokasi memori pada merge\n");
        exit(1);
    }

    // Salin data ke array sementara
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Gabungkan kembali array yang sudah diurutkan
    i = 0; j = 0; k = l;

    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    // Salin sisa elemen
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    // Jangan lupa free heap memory
    free(L);
    free(R);
}
// Fungsi bantu merge untuk string
void merge_string(char *arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    char **L = malloc(n1 * sizeof(char *));
    char **R = malloc(n2 * sizeof(char *));
    if (!L || !R) {
        fprintf(stderr, "Gagal alokasi memori pada merge_string\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (strcmp(L[i], R[j]) <= 0) ? L[i++] : R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge sort utama untuk integer
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// Merge sort utama untuk string
void merge_sort_string(char *arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_string(arr, l, m);
        merge_sort_string(arr, m + 1, r);
        merge_string(arr, l, m, r);
    }
}


// =====================
// QUICK SORT
// =====================

// Partition untuk quick sort integer
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    return i + 1;
}
// Quick sort untuk integer
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Partition untuk quick sort string
int partition_string(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    char *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick sort untuk string
void quick_sort_string(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition_string(arr, low, high);
        quick_sort_string(arr, low, pi - 1);
        quick_sort_string(arr, pi + 1, high);
    }
}


// =====================
// SHELL SORT
// =====================

// Shell Sort untuk integer
void shell_sort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            // Geser elemen yang lebih besar dengan interval "gap"
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Shell Sort untuk string
void shell_sort_string(char *arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char *temp = arr[i];
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}