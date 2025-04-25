Nama        : Dian Islami
NPM         : 2308107010048
Mata Kuliah : Struktur Data dan Algoritma Kelas D
Tugas       : Tugas ini berkaitan dengan algoritma pengurutan (Sorting Algorithm)

Deskripsi Program
Program ini dibuat untuk mengevaluasi performa algoritma pengurutan (sorting) pada data skala besar, baik berupa data angka (integer) maupun data kata (string).
Tugas ini mengimplementasikan dan membandingkan enam algoritma sorting klasik:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Shell Sort

Tujuan utama dari program ini adalah:
- Menganalisis efisiensi algoritma sorting dari sisi waktu eksekusi dan penggunaan memori.
- Melakukan eksperimen bertahap pada berbagai ukuran data (hingga 2 juta baris).
- Menyusun laporan analisis performa berbasis data dan grafik.

Struktur Data
Program terdiri dari beberapa file:
1. sort_algorithms.h
   Berisi deklarasi fungsi-fungsi sorting untuk data integer dan string.
2. sort_algorithms.c
   Berisi implementasi lengkap dari semua algoritma sorting.
3. generate_data.c
   Program pembangkit data acak berupa angka dan kata yang disimpan ke file data_angka.txt dan data_kata.txt.
4. main.c
   File utama yang:
   - Memuat data dari file,
   - Menyalin data ke buffer,
   - Mengukur waktu dan estimasi memori,
   - Menjalankan sorting untuk masing-masing algoritma,
   - Menampilkan hasil waktu eksekusi dan memori ke konsol.

Data
Jumlah data: 2.000.000 baris angka dan kata
Format data: data_angka.txt & data_kata.txt
Ukuran yang diuji:
- 10.000
- 50.000
- 100.000
- 250.000
- 500.000
- 1.000.000
- 1.500.000
- 2.000.000

Eksperimen
Pengujian dilakukan pada masing-masing algoritma dengan:
- Pengukuran waktu: menggunakan clock() dari <time.h>
- Pengukuran memori: estimasi berdasarkan ukuran array/pointer yang digunakan
- Perbandingan dilakukan untuk:
  a. Integer vs String
  b. Per algoritma dan per ukuran data

Cara Menjalankan Program
1. Jalankan program generate_data.c untuk membuat data .txt yang dibutuhkan
2. Pastikan file `data_angka.txt` & `data_kata.txt`  berada di direktori yang sama dengan file .c
3. Kompilasi program utama dengan cara ketik di terminal:
   gcc main.c sort_algorithms.c -o (inisialisai)
   .(inisialisai)
4. Setelah dijalankan program akan langsung melakukan sorting untuk kedua data .txt dan semua algoritma 

Output yang Ditampilkan
- Waktu eksekusi setiap algoritma
- Estimasi penggunaan memori (dalam MB)
- Ditampilkan secara terpisah untuk data angka dan data kata
  ex:
  =================================================
  Data size: 2000000

  [ Angka (int) ]
  Bubble Sort       : 23.45 s    | Memori: 30.52 MB
  Selection Sort    : 19.87 s    | Memori: 30.52 MB
  ...
  [ Kata (string) ]
  Bubble Sort       : 23.45 s    | Memori: 30.52 MB
  Selection Sort    : 19.87 s    | Memori: 30.52 MB
  ...
