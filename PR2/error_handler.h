#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

// Установка пути для файла ошибок
void set_error_path(const char *path);

// Запись ошибки в файл или в stderr
void log_error(const char *message);

#endif // ERROR_HANDLER_H

