cmake_minimum_required(VERSION 3.16.0)

project(opencm3_app
    LANGUAGES C ASM
)

add_compile_options(
    -mthumb
    -mcpu=cortex-m3
    -fdata-sections
    -ffunction-sections
    -Wall
    -Wextra
    --specs=nano.specs
    --specs=nosys.specs
)

add_link_options(
    -mthumb
    -mcpu=cortex-m3
    -nostartfiles
    -Wl,--gc-sections
    --specs=nano.specs
    --specs=nosys.specs
)

set(MCU_VARIANT stm32f103cb)
set(OPENCM3_LIB opencm3_stm32f1)
set(LIBOPENCM3_CMAKE_DIR libs/libopencm3_cmake)

add_subdirectory(${LIBOPENCM3_CMAKE_DIR} ${OPENCM3_LIB})

set(APP_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

set(APP_INCS
    ${CMAKE_CURRENT_LIST_DIR}/src
)

add_executable(opencm3_app ${APP_SRCS})
target_include_directories(opencm3_app PRIVATE ${APP_INCS})
target_link_libraries(opencm3_app PRIVATE ${OPENCM3_LIB})
target_link_options(opencm3_app
    PRIVATE
    -T ${CMAKE_BINARY_DIR}/generated.${MCU_VARIANT}.ld
    -Wl,-Map=opencm3_app.map
    -Wl,--print-memory
)
add_custom_command(
    TARGET opencm3_app
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O srec opencm3_app.elf opencm3_app.srec
    BYPRODUCTS opencm3_app.srec
)
