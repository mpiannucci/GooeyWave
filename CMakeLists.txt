cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(QtMacOpenGL)

# Set C++11 and any other flags
if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    # C++14: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
endif()

# Handle Qt Moccing.
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find all require QT Modules
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

# Find OpenGL modules
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
   MESSAGE("OpenGL Correctly Found")
   include_directories(${OPENGL_INCLUDE_DIR})
else (OPENGL_FOUND)
   MESSAGE("OpenGL environment missing")
endif (OPENGL_FOUND)

# Set the source files 
set(SOURCES Source/main.cpp 
            Source/gooeymain.cpp)
set(HEADERS Source/gooeymain.h)
set(UIS Resources/Forms/gooeymain.ui)

# Handle Win32 Resources and Qt main lib
# if (WIN32)
#     set(SOURCES ${SOURCES} win/example.rc)
# endif ()

# Wrap the Qt UI Headers. You have to do this instead of autouic if 
# your ui files are in a seperate directory
qt5_wrap_ui(GEN_UI_HEADERS ${UIS})

# Wrap the Qt Resources File 
#qt5_add_resources(RESOURCE_FILES example.qrc)

# Apple Package Config
if (APPLE)
    set(SOURCES ${SOURCES} Resources/AppIcon.icns)
    set_source_files_properties(Resources/AppIcon.icns PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
endif ()

# Preprocessor Defs
add_definitions(-DQT_DLL)

# Add all of the source files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Source ${CMAKE_CURRENT_SOURCE_DIR}/Resources/Forms)
add_executable(QtMacOpenGL MACOSX_BUNDLE ${SOURCES} ${HEADERS} ${GEN_UI_HEADERS})

# Mac OSX Bundle Config
set(MACOSX_BUNDLE_BUNDLE_NAME "QtMacOpenGL")
set(MACOSX_BUNDLE_BUNDLE_VERSION "1.0")
set(MACOSX_BUNDLE_LONG_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_COPYRIGHT "Copyright (c) 2015 Matthew Iannucci. All rights reserved.")
set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.nucc.QtMacOpenGL")
set(MACOSX_BUNDLE_ICON_FILE AppIcon.icns)

if (APPLE)
    set_target_properties(QtMacOpenGL PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Resources/Info.plist.in)
endif ()

# Link the qt modules
target_link_libraries(QtMacOpenGL Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL)

# Windows Executable 
if (MSVC)
    target_link_libraries(QtMacOpenGL Qt5::WinMain)
    set_target_properties(${PROJECT} PROPERTIES
        WIN32_EXECUTABLE YES
        LINK_FLAGS "/ENTRY:mainCRTStartup"
    )
endif ()