 Аналіз пам’яті та типу time_t у мові C

Опис

Проєкт містить дві програми на C:
1. `memory_segments.c` — вимірювання часу доступу до різних сегментів пам’яті: `.text`, `.data`, `.bss`, стек, купа.
2. `time_overflow_check.c` — визначення дати переповнення типу `time_t`.

 Компіляція та запуск

```bash
gcc -o memory_test memory_segments.c
./memory_test

gcc -o time_test time_overflow_check.c
./time_test
