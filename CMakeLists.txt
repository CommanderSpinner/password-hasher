cmake_minimum_required(VERSION 3.16)
project(password_hasher)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(BOTAN3 REQUIRED botan-3)

file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
add_executable(password_hasher ${SOURCES})

# Include Botan 3 headers from pkg-config
target_include_directories(password_hasher PRIVATE ${BOTAN3_INCLUDE_DIRS})

# Link Botan 3 libraries from pkg-config
target_link_libraries(password_hasher PRIVATE ${BOTAN3_LIBRARIES})

# Add necessary compiler flags from pkg-config (if any)
target_compile_options(password_hasher PRIVATE ${BOTAN3_CFLAGS_OTHER})
