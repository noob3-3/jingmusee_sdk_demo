cmake_minimum_required(VERSION 3.27)
project(JM_VoiceIntercom)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_GENERATOR_PLATFORM x86)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)


## 添加库文件搜索路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/SDK)

add_executable(JM_VoiceIntercom main.cpp)

target_link_libraries(JM_VoiceIntercom I8H_SDK)
# 添加自定义命令和自定义目标，用于复制 DLL 文件
add_custom_command(TARGET JM_VoiceIntercom POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/SDK/I8H_SDK.dll
        $<TARGET_FILE_DIR:JM_VoiceIntercom>
        COMMENT "Copying DLL to output directory"
)

add_custom_target(CopyDLLs ALL
        DEPENDS JM_VoiceIntercom
)
