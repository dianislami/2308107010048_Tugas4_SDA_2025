#include "sort_algorithms.h" // Header berisi deklarasi fungsi sorting (harus disediakan)

#define MAX_DATA 2000000
#define MAX_STRING_LEN 100
#define BYTE_TO_MB (1024.0 * 1024.0) // Konversi byte ke megabyte

// Fungsi untuk memuat data angka dari file ke array
void load_data(const char *filename, int *arr, int count) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file");
        exit(1);
    }
    for (int i = 0; i < count; i++) fscanf(fp, "%d", &arr[i]);
    fclose(fp);
}

// Fungsi untuk memuat data string dari file ke array pointer string
void load_string_data(const char *filename, char **arr, int count) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file kata");
        exit(1);
    }
    char buffer[MAX_STRING_LEN];
    for (int i = 0; i < count; i++) {
        fscanf(fp, "%s", buffer);
        arr[i] = strdup(buffer); // Duplikat string agar bisa dimanipulasi
    }
    fclose(fp);
}

// Estimasi memori dasar untuk integer (2 array int)
double calculate_base_memory(int size) {
    return (size * sizeof(int) * 2) / BYTE_TO_MB;
}

// Estimasi memori untuk merge sort (butuh array tambahan)
double calculate_merge_memory(int size) {
    return (size * sizeof(int) * 4) / BYTE_TO_MB;
}

// Estimasi memori dasar untuk array pointer ke string (tanpa isi string)
double calculate_string_memory(int size) {
    return (size * sizeof(char *) * 2) / BYTE_TO_MB; // 2 array pointer string
}

int main() {
    int data_sizes[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};
    int *data = malloc(MAX_DATA * sizeof(int)); // Array utama data angka
    int *copy = malloc(MAX_DATA * sizeof(int)); // Salinan data untuk sorting

    char **data_kata = malloc(MAX_DATA * sizeof(char *)); // Array utama data string
    char **copy_kata = malloc(MAX_DATA * sizeof(char *)); // Salinan data string untuk sorting

    // Cek alokasi memori
    if (!data || !copy || !data_kata || !copy_kata) {
        fprintf(stderr, "Gagal alokasi memori\n");
        exit(1);
    }

    for (int i = 0; i < sizeof(data_sizes)/sizeof(int); i++) {
        int size = data_sizes[i];
        printf("\n=============================================\n");
        printf("Data size: %d\n", size);

        // ========================================
        // Bagian Data ANGKA
        // ========================================
        load_data("data_angka.txt", data, size); // Memuat data angka dari file
        double base_memory = calculate_base_memory(size);
        double merge_memory = calculate_merge_memory(size);

        printf("\n[ Angka (int) ]\n");
        printf("Estimasi Memori Dasar (2 array int): %.2f MB\n", base_memory);

        // Bubble Sort
        memcpy(copy, data, size * sizeof(int));
        clock_t start = clock();
        bubble_sort(copy, size);
        printf("Bubble Sort       : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, base_memory);

        // Selection Sort      
        memcpy(copy, data, size * sizeof(int));
        start = clock();
        selection_sort(copy, size);
        printf("Selection Sort    : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, base_memory);

        // Insertion Sort
        memcpy(copy, data, size * sizeof(int));
        start = clock();
        insertion_sort(copy, size);
        printf("Insertion Sort    : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, base_memory);

        // Merge Sort
        memcpy(copy, data, size * sizeof(int));
        start = clock();
        merge_sort(copy, 0, size - 1);
        printf("Merge Sort        : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, merge_memory);

        // Quick Sort
        memcpy(copy, data, size * sizeof(int));
        start = clock();
        quick_sort(copy, 0, size - 1);
        printf("Quick Sort        : %.2f s    | Memori: %.2f MB (est)\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, base_memory + 1.0);

        // Shell Sort
        memcpy(copy, data, size * sizeof(int));
        start = clock();
        shell_sort(copy, size);
        printf("Shell Sort        : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, base_memory);

        // ========================================
        // Bagian Data KATA (string)
        // ========================================
        load_string_data("data_kata.txt", data_kata, size); // Memuat data string dari file
        double str_memory = calculate_string_memory(size);

        printf("\n[ Kata (string) ]\n");
        printf("Estimasi Memori Dasar (2 array pointer): %.2f MB\n", str_memory);

        // Bubble Sort String
        for (int j = 0; j < size; j++) copy_kata[j] = strdup(data_kata[j]);
        start = clock();
        bubble_sort_string(copy_kata, size);
        printf("Bubble Sort       : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, str_memory);

        // Selection Sort String
        for (int j = 0; j < size; j++) {
            free(copy_kata[j]);
            copy_kata[j] = strdup(data_kata[j]);
        }
        start = clock();
        selection_sort_string(copy_kata, size);
        printf("Selection Sort    : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, str_memory);

        // Insertion Sort String
        for (int j = 0; j < size; j++) {
            free(copy_kata[j]);
            copy_kata[j] = strdup(data_kata[j]);
        }
        start = clock();
        insertion_sort_string(copy_kata, size);
        printf("Insertion Sort    : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, str_memory);

        // Merge Sort String
        for (int j = 0; j < size; j++) {
            free(copy_kata[j]);
            copy_kata[j] = strdup(data_kata[j]);
        }
        start = clock();
        merge_sort_string(copy_kata, 0, size - 1);
        printf("Merge Sort        : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, str_memory * 2);

        // Quick Sort String
        for (int j = 0; j < size; j++) {
            free(copy_kata[j]);
            copy_kata[j] = strdup(data_kata[j]);
        }
        start = clock();
        quick_sort_string(copy_kata, 0, size - 1);
        printf("Quick Sort        : %.2f s    | Memori: %.2f MB (est)\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, str_memory + 1.0);

        // Shell Sort String
        for (int j = 0; j < size; j++) {
            free(copy_kata[j]);
            copy_kata[j] = strdup(data_kata[j]);
        }
        start = clock();
        shell_sort_string(copy_kata, size);
        printf("Shell Sort        : %.2f s    | Memori: %.2f MB\n",
               (double)(clock() - start)/CLOCKS_PER_SEC, str_memory);

        // Bebaskan memori string
        for (int j = 0; j < size; j++) {
            free(data_kata[j]);
            free(copy_kata[j]);
        }
    }

    // Bebaskan memori array
    free(data);
    free(copy);
    free(data_kata);
    free(copy_kata);

    return 0;
}