link_directories(
    ${GTKMM_LIBRARY_DIRS})

include_directories(
    ${GTKMM_INCLUDE_DIRS})

add_library(timer
    Timer.hpp
    Timer.cpp)   

add_executable(kamodoro 
    main.cpp)

target_link_libraries(kamodoro 
    PRIVATE ${GTKMM_LIBRARIES})