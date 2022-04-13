cmake_minimum_required(VERSION 3.0)

# Set the project name
project (neuralwork)

# Create a sources variable with a link to all cpp files to compile
file(GLOB SOURCES true 

)


# Add an executable with the above sources
add_executable(neuralworkTests ${SOURCES})


#google tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
#

target_link_libraries(
  neuralworkTests
  neuralworkLib
)
