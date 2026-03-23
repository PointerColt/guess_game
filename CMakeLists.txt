set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_TLS_VERIFY OFF)
project(PhysicsApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# This downloads the Web Library (CPR)
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG 1.10.x
)
FetchContent_MakeAvailable(cpr)

# This downloads the JSON Library
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

add_executable(PhysicsApp main.cpp)

# This connects the libraries to your code
target_link_libraries(PhysicsApp PRIVATE cpr::cpr nlohmann_json::nlohmann_json)