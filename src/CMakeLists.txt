set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES} Graph/Maze2D.cpp Graph/Maze2D.h Graph/RandKruskalMaze.cpp Graph/RandKruskalMaze.h Graph/Vertex.cpp Graph/Vertex.h Graph/Connection.cpp Graph/Connection.h Graph/Coordinates.cpp Graph/Coordinates.h Graph/AccessForbiddenException.cpp Graph/AccessForbiddenException.h)