cmake_minimum_required(VERSION 3.10)

# set the project name
project(StudentManager)

# add the executable
add_executable(main main.cpp
        models/Score.cpp
        models/Score.h
        models/Student.cpp
        models/Student.h
        stores/Store.h
        stores/Store.cpp
        stores/StudentStash.cpp
        stores/StudentStash.h
        stores/ScoreStash.cpp
        stores/ScoreStash.h
        views/UI.h
        views/MainMenu.cpp
        views/MainMenu.h
        views/ScoreDetail.cpp
        views/ScoreDetail.h
        views/StudentDetail.cpp
        views/StudentDetail.h
        Application.cpp
        Application.h
)
if(NOT PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    # Git auto-ignore out-of-source build directory
    file(GENERATE OUTPUT .gitignore CONTENT "build/\ninstall/")
endif()