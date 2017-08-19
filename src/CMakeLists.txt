add_subdirectory("SimpleECS")
add_subdirectory("Systems")
add_subdirectory("Components")


add_library(engine "Engine.cpp")
target_link_libraries(engine sfml-system)

add_executable(pong "main.cpp")
target_link_libraries(pong
    ComponentFactory
    manager
    RenderSystem
    PhysicsSystem
    CollisionSystem
    TextSinkRenderSystem
    engine
    sfml-graphics
    sfml-window
    sfml-system
)
