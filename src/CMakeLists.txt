add_subdirectory("SimpleECS")
add_subdirectory("Systems")

add_library(display "Display.cpp")
target_link_libraries(display
    sfml-system
    sfml-graphics
    sfml-window)

add_library(engine "Engine.cpp")
target_link_libraries(engine display sfml-system)

add_executable(pong "main.cpp")
target_link_libraries(pong
    manager
    RenderSystem
    engine
    sfml-graphics
    sfml-window
    sfml-system
)
