#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
    time_t max_time = (time_t)(~((time_t)0) >> 1);  // Максимальне значення для signed time_t
    printf("Максимальне значення time_t: %ld\n", (long)max_time);

    struct tm *broken_time = gmtime(&max_time);
    printf("Дата переповнення time_t: %s", asctime(broken_time));
    return 0;
}
