#add_subdirectory("Systems")
#add_subdirectory("Components")

add_library(display "Display.cpp")
target_link_libraries(display
    sfml-system
    sfml-graphics
    sfml-window)

add_library(engine "Engine.cpp")
target_link_libraries(engine display sfml-system)

add_library(manager "ecs/Manager.cpp")


add_executable(pong "main.cpp")
target_link_libraries(pong
    manager
    engine
    sfml-graphics
    sfml-window
    sfml-system
)

#add_library(SFMLComponentFactory_Main "SFMLComponentFactory.cpp")
#target_link_libraries(SFMLComponentFactory_Main sfml-graphics)
