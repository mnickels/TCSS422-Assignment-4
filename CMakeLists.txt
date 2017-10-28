cmake_minimum_required(VERSION 3.8)
project(problem4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES OS.c OS.h fifo_queue.c fifo_queue.h pcb.c pcb.h PriorityQ.c PriorityQ.h)
add_executable(TCSS422-Assignment-4 ${SOURCE_FILES})