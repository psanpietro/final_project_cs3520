cmake_minimum_required(VERSION 3.22)
project(final_project_cs3520)

set(CMAKE_CXX_STANDARD 17)

#most of this code was from imgui-sfml and sfml references to get the project to build
# Add your main executable
add_executable(final_project_cs3520 src/main.cpp
        src/pong/PongController.cpp
        src/pong/PongController.h
        src/pong/GameObject.h
        src/pong/Ball.cpp
        src/pong/Ball.h
        src/pong/Paddle.cpp
        src/pong/Paddle.h
        src/pong/Monocraft.ttf
        src/galaga/GalagaController.cpp
        src/galaga/GalagaController.h
        src/galaga/PlayerShip.cpp
        src/galaga/PlayerShip.h
        src/galaga/EnemyShip.cpp
        src/galaga/EnemyShip.h
        src/galaga/Laser.cpp
        src/galaga/Laser.h
        src/gui/GameSelector.cpp
        src/gui/GameSelector.h
        src/galaga/LaserHandler.cpp
        src/galaga/LaserHandler.h
        src/snake/SnakeController.cpp
        src/snake/SnakeController.h
        src/snake/Snake.cpp
        src/snake/Snake.h
        src/snake/Food.cpp
        src/snake/Food.h
)
include(FetchContent)

set(SFML_VERSION 2.5.1)
set(IMGUI_VERSION 1.87)
set(IMGUI_SFML_VERSION 2.3)

# It's nice to get stripped-down release zips instead of cloning
# a repo and checking out a tag
FetchContent_Declare(
        SFML
        URL "https://github.com/SFML/SFML/archive/${SFML_VERSION}.zip"
)

FetchContent_Declare(
        imgui
        URL "https://github.com/ocornut/imgui/archive/v${IMGUI_VERSION}.zip"
)

# Or by tag...
FetchContent_Declare(
        imgui-sfml
        URL "https://github.com/SFML/imgui-sfml/archive/refs/tags/v2.6.zip"
        # GIT_COMMIT 5f54b69b6aee18db846c81633f86f78c2586dded
        # ^ or like this - sometimes it's better because FetchContent won't look
        # into remote to see if branch head was updated or not - good for stable
        # tags like 'vX.X' corresponding to releases
)

## finally, let's build

# SFML
option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build network" OFF)
FetchContent_MakeAvailable(sfml)

# Dear ImGui
FetchContent_MakeAvailable(imgui)

# ImGui-SFML
set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" ON)

FetchContent_MakeAvailable(imgui-sfml)

target_link_libraries(final_project_cs3520
        PUBLIC
        ImGui-SFML::ImGui-SFML
)

configure_file(src/pong/Monocraft.ttf ${CMAKE_BINARY_DIR}/Monocraft.ttf COPYONLY)