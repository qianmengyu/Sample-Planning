cmake_minimum_required(VERSION 3.0)
project(path_planning)  # 将 YourProjectName 替换为您的项目名称

# 添加可执行文件
add_executable(main main.cpp)  # main.cpp 是包含主函数的文件

# 设置包含目录，以便编译器能够找到您的头文件
include_directories(${CMAKE_SOURCE_DIR})

# 如果您的 Map.h 位于单独的 include 目录下，例如 include 文件夹，则可以使用以下命令：
include_directories(
	${CMAKE_SOURCE_DIR}
	/include
	/src)

target_sources(main PRIVATE src/Map.cpp src/Dijkstra.cpp src/Utility.cpp src/AStar.cpp)
# 如果您的 Map.h 文件没有额外的依赖项，您的项目可能不需要链接任何其他库。
# 如果需要链接其他库，请添加以下命令：
# target_link_libraries(main ${SOME_OTHER_LIBRARIES})
