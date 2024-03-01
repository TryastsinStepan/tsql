cmake_minimum_required(VERSION 3.13)
project(tsql)

# Помещаем проекты в группы в Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Исключаем проекты ALL_BUILD и ZERO_CHECK из сборки по умолчанию
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

# Включаем экспорт компиляционных команд
set_property(GLOBAL PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Устанавливаем переменную для директории с исходными файлами
set(SOURCE_DIR "G:/GodHelpMe/HashTable/src")

# Добавляем исполняемый файл
add_executable(my_executable 
    ${SOURCE_DIR}/main.c
    ${SOURCE_DIR}/string.c
    ${SOURCE_DIR}/hashfunction.c
    ${SOURCE_DIR}/hashtable.c
    ${SOURCE_DIR}/hmap.c
    ${SOURCE_DIR}/list.c
    ${SOURCE_DIR}/typestring.c
)

# Указываем пути к заголовочным файлам
target_include_directories(my_executable PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../build  # Путь к каталогу build относительно исходного каталога
    G:/GodHelpMe/HashTable/lib
)