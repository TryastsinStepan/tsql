cmake_minimum_required(VERSION 3.13)
project(tsql)
set_property(GLOBAL PROPERTY USE_FOLDERS ON) # Эта строка помещает проекты в группы в Visual Studio

# Исключаем проекты ALL_BUILD и ZERO_CHECK из сборки по умолчанию
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

set_property(GLOBAL PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Добавление исполняемого файла
add_executable(my_executable main.c string.c hashfunction.c hashtable.c hmap.c list.c typestring.c)

# Указание пути к заголовочным файлам
target_include_directories(my_executable PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/../build  # Путь к каталогу build относительно исходного каталога
    G:/GodHelpMe/HashTable/lib)
