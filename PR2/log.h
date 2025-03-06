/*#ifndef LOG_H
#define LOG_H

// Установка пути для лог-файла
void set_log_path(const char *path);

// Запись сообщения в лог-файл или на экран
void log_message(const char *message);

void log(int argc, char *argv[]);

#endif // LOGGER_H
*/

/*#ifndef LOG_OUTPUT_H
#define LOG_OUTPUT_H

void redirect_output(const char *path);
void restore_output();

#endif // LOG_OUTPUT_H
*/

#ifndef LOG_H
#define LOG_H

// Функция для перенаправления stdout в файл
void redirect_output_to_file(const char *path);

#endif
