# Check if boost is installed
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARY_DIRS ${Boost_LIBRARY_DIRS}")
    message(STATUS "Boost_LIBRARIES ${Boost_LIBRARIES}")
    include_directories(
        ${Boost_INCLUDE_DIRS}
        ${Boost_LIBRARY_DIRS})
    # Compile options for Boost
    add_compile_options(-lunit_test_framework)
else()
    message(ERROR "BOOST NOT FOUND")
endif()

# Create executable by including test files
add_executable(kamodoro_tests
    main.cpp)

# Link boost libraries to executable
target_link_libraries(kamodoro_tests
    PUBLIC ${Boost_LIBRARIES})