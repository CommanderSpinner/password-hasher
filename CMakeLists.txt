cmake_minimum_required(VERSION 3.16)
project(password_hasher)

# Set the C++ standard to 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find PkgConfig to locate libraries and their flags
find_package(PkgConfig REQUIRED)

# Check for Botan 3 and gtkmm-3.0 (NOT gtkmm-4.0)
pkg_check_modules(BOTAN3 REQUIRED botan-3)
pkg_check_modules(GTKMM3 REQUIRED gtkmm-3.0)

# Glob all .cpp source files
file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")

# Create the executable
add_executable(password_hasher ${SOURCES})

# Include directories for both Botan 3 and GTKMM 3
target_include_directories(password_hasher
  PRIVATE
    ${BOTAN3_INCLUDE_DIRS}
    ${GTKMM3_INCLUDE_DIRS}
)

# Link against the libraries
target_link_libraries(password_hasher
  PRIVATE
    ${BOTAN3_LIBRARIES}
    ${GTKMM3_LIBRARIES}
)

# Add compiler flags
target_compile_options(password_hasher
  PRIVATE
    ${BOTAN3_CFLAGS_OTHER}
    ${GTKMM3_CFLAGS_OTHER}
)
