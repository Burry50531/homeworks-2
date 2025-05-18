#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int global_data = 1;           // Сегмент .data
int global_bss;                // Сегмент .bss

void dummy_function() {}       // Сегмент .text

#define ITERATIONS 10000000    // Кількість ітерацій

int main() {
    clock_t start, end;
    int stack_var = 1;         // Змінна у стеку
    int *heap_var = malloc(sizeof(int));  // Змінна в купі (heap)
    *heap_var = 1;

    // Сегмент .text – виклик функції
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) dummy_function();
    end = clock();
    printf("Час доступу до сегменту .text: %f сек\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Сегмент .data – доступ до ініціалізованої глобальної змінної
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) global_data++;
    end = clock();
    printf("Час доступу до сегменту .data: %f сек\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Сегмент .bss – доступ до неініціалізованої глобальної змінної
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) global_bss++;
    end = clock();
    printf("Час доступу до сегменту .bss: %f сек\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Купа (heap)
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) (*heap_var)++;
    end = clock();
    printf("Час доступу до купи (heap): %f сек\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Стек
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) stack_var++;
    end = clock();
    printf("Час доступу до стеку: %f сек\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(heap_var);
    return 0;
}
