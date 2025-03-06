/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_log_path(const char *path) {
    if (log_file) {
        fclose(log_file);
    }
    log_file = fopen(path, "w");
    if (!log_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
}

void log_message(const char *message) {
    if (log_file) {
        fprintf(log_file, "%s\n", message);
    } else {
        printf("%s\n", message);
    }
}

void log(int argc, char *argv[]) {
    // Предполагается, что вы уже обработали аргументы и решили, что -l включен
    if (argc > 3 && strcmp(argv[1], "-u") == 0 && strcmp(argv[2], "-l") == 0) {
        set_log_path(argv[3]);
    }

    log_message("Это тестовое сообщение для лога.");
    
    // Освобождаем ресурсы
    if (log_file) {
        fclose(log_file);
    }
    
    return;
} */

/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void redirect_output(const char *path) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        perror("Не удалось открыть файл для записи");
        exit(EXIT_FAILURE);
    }
    // Перенаправляем стандартный вывод в файл
    if (dup2(fileno(file), STDOUT_FILENO) == -1) {
        perror("Не удалось перенаправить стандартный вывод");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void restore_output() {
    // Восстанавливаем стандартный вывод
    fflush(stdout);
    dup2(STDOUT_FILENO, fileno(stdout));
}*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void redirect_output_to_file(const char *path) {
    // Проверяем доступ к файлу
    if (access(path, W_OK) == -1) {
        // Если файл недоступен, создаем его
        FILE *file = fopen(path, "w");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fclose(file);
    }

    // Перенаправляем stdout в файл
    FILE *file = freopen(path, "a", stdout);
    if (file == NULL) {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}

