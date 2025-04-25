#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Fungsi untuk menghasilkan angka acak dan menyimpannya ke file
void generate_random_numbers(const char *filename, int count, int max_value) {
    FILE *fp = fopen(filename, "w"); // Membuka file untuk menulis
    if (!fp) {
        perror("File tidak dapat dibuka"); // Menampilkan error jika gagal membuka file
        return;
    }
    srand(time(NULL)); // Menginisialisasi seed untuk random number
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d\n", rand() % max_value); // Menulis angka acak ke file
    }
    fclose(fp); // Menutup file
}


// Fungsi pembantu untuk menghasilkan satu kata acak dengan panjang tertentu
void random_word(char *word, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz"; // Karakter yang mungkin digunakan
    for (int i = 0; i < length; i++) {
        word[i] = charset[rand() % (sizeof(charset) - 1)]; // Pilih karakter acak
    }
    word[length] = '\0'; // Menambahkan null terminator
}


// Fungsi untuk menghasilkan kata acak dan menyimpannya ke file
void generate_random_words(const char *filename, int count, int max_word_length) {
    FILE *fp = fopen(filename, "w"); // Membuka file untuk menulis
    if (!fp) {
        perror("File tidak dapat dibuka"); // Menampilkan error jika gagal membuka file
        return;
    }
    srand(time(NULL)); // Menginisialisasi seed random (diulang di sini, sebaiknya cukup 1x di main)
    char word[100]; // Buffer untuk kata yang dihasilkan
    for (int i = 0; i < count; i++) {
        int len = (rand() % (max_word_length - 3)) + 3; // Panjang kata acak antara 3 hingga max_word_length
        random_word(word, len); // Membuat kata acak
        fprintf(fp, "%s\n", word); // Menulis ke file
    }
    fclose(fp); // Menutup file
}

int main() {
    // Menghasilkan 2 juta angka acak dari 0 hingga 1.999.999 dan simpan ke file
    generate_random_numbers("data_angka.txt", 2000000, 2000000);

    // Menghasilkan 2 juta kata acak dengan panjang hingga 20 karakter dan simpan ke file
    generate_random_words("data_kata.txt", 2000000, 20);
    return 0;
}
