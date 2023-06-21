cmake_minimum_required(VERSION 3.12)
project(LinkedList C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O3 -march=native -mtune=native")

set(SRCS ../linkedList.c adders.tests.c constructors.tests.c main.c removers.tests.c utils.tests.c settersNgetters.tests.c indexers.tests.c)
set(OBJS)
foreach(SRC ${SRCS})
    get_filename_component(SRC_NAME ${SRC} NAME)
    string(REPLACE ".c" ".o" OBJ_NAME ${SRC_NAME})
    add_library(${OBJ_NAME} OBJECT ${SRC})
    list(APPEND OBJS $<TARGET_OBJECTS:${OBJ_NAME}>)
endforeach()

add_executable(exec ${OBJS})

add_custom_target(run
    COMMAND ./exec
    DEPENDS exec
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove -f ${OBJS}
    COMMAND ${CMAKE_COMMAND} -E remove -f exec
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
