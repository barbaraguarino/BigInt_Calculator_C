cmake_minimum_required(VERSION 3.20)
project(BigInt_Calculator_C C)

set(CMAKE_C_STANDARD 11)

# Inclui a pasta de headers
include_directories(include)

# Adiciona os arquivos .c ao executável
add_executable(BigInt_Calculator_C
        src/main.c
        src/bigint.c
        src/operations.c
        include/imports.h
)