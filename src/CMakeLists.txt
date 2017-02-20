# Include current build directory, otherwise we can't find generated UI headers
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# CPP source files
FILE(GLOB POD_VS_CLASS_SRC "*.cpp")
LIST(REMOVE_ITEM POD_VS_CLASS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
LIST(SORT POD_VS_CLASS_SRC)
SOURCE_GROUP(source FILES ${POD_VS_CLASS_SRC})

FILE(GLOB POD_VS_CLASS_HDR "*.hpp")
LIST(SORT POD_VS_CLASS_HDR)
SOURCE_GROUP(include FILES ${POD_VS_CLASS_HDR})

ADD_DEFINITIONS(-std=c++17)
ADD_DEFINITIONS(-g)

# Library
ADD_LIBRARY(pod-vs-class-lib ${POD_VS_CLASS_SRC} ${POD_VS_CLASS_HDR})
TARGET_INCLUDE_DIRECTORIES(pod-vs-class-lib PUBLIC ../include)

# Test Exerciser Executable
ADD_EXECUTABLE(pod-vs-class-test main.cpp)
TARGET_LINK_LIBRARIES(pod-vs-class-test
    pod-vs-class-lib
    )

ADD_EXECUTABLE(pod-vs-class-test-without main.cpp)
TARGET_LINK_LIBRARIES(pod-vs-class-test-without
    pod-vs-class-lib
    )
TARGET_COMPILE_DEFINITIONS(pod-vs-class-test-without PUBLIC
    -DPOD_VS_CLASS_DISABLED=1
    )

