set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ws2812.C
    ${CMAKE_CURRENT_SOURCE_DIR}/test.c
    PARENT_SCOPE
)
set(LIB_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ws2812.c
    PARENT_SCOPE
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})