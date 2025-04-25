// Include semua header yang dibutuhkan
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Header guard untuk mencegah duplikasi saat header ini di-include lebih dari sekali
#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

// ===== Deklarasi Fungsi Sorting untuk Array Integer =====
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void merge_sort(int arr[], int l, int r);
void quick_sort(int arr[], int low, int high);
void quick_sort_string(char *arr[], int low, int high);
void shell_sort(int arr[], int n);

// ===== Deklarasi Fungsi Sorting untuk Array String =====
void bubble_sort_string(char *arr[], int n);
void selection_sort_string(char *arr[], int n);
void insertion_sort_string(char *arr[], int n);
void merge_sort_string(char *arr[], int l, int r);
void quick_sort_string(char *arr[], int low, int high);
void shell_sort_string(char *arr[], int n);

// Akhir dari header guard
#endif
