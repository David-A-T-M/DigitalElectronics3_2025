cmake_minimum_required(VERSION 3.10)
project(LPC1769_Educativo C)

# Busca todos los archivos .c en el proyecto y subcarpetas
file(GLOB_RECURSE SOURCES "*.c")

# Crea una librería estática con todos los archivos encontrados
add_library(lpc1769_codes STATIC ${SOURCES})

# Opcional: incluye todos los directorios para análisis y autocompletado
include_directories(${CMAKE_SOURCE_DIR})
