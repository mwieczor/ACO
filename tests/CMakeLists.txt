include_directories( ${gtest_SOURCE_DIR}/include)
include_directories( ${gmock_SOURCE_DIR}/include)
include_directories( ../src/ )

file(GLOB_RECURSE SRC *.cpp *.h*)
add_executable(Tests ${SRC} )

target_link_libraries(Tests gmock gtest UltraLib)
