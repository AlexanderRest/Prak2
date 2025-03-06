#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log.h"
#include "error_handler.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;
    char *error_path = NULL;

    // Определение длинных опций
    struct option long_options[] = {
        {"users", no_argument, NULL, 'u'},
        {"processes", no_argument, NULL, 'p'},
        {"help", no_argument, NULL, 'h'},
        {"log", required_argument, NULL, 'l'},
        {"error", required_argument, NULL, 'e'},
        {NULL, 0, NULL, 0}
    };

    // Обработка опций
    while ((opt = getopt_long(argc, argv, "uphl:e:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'u':
                /*list_users();
                break;*/
		if (log_path) {
                    redirect_output_to_file(log_path);  // Перенаправляем stdout в файл
                }
                list_users();  // Выводим список пользователей
                break;
            case 'p':
                /*list_processes();
                break;*/
		if (log_path) {
                    redirect_output_to_file(log_path);  // Перенаправляем stdout в файл
                }
                list_processes();  // Выводим список процессов
                break;
            case 'h':
                print_help();
                return 0;
            case 'l':
                /*log_path = optarg;
                set_log_path(log_path);
                break;*/
		log_path = optarg;
                break;
            case 'e':
                error_path = optarg;
                set_error_path(error_path);
                break;
            default:
                print_help();
                return 1;
        }
    }

    return 0;
}

