add_subdirectory("SimpleECS")
add_subdirectory("Events")
add_subdirectory("Systems")
add_subdirectory("Components")

add_library(Engine "Engine.cpp")
target_link_libraries(Engine 
    sfml-system
    EventManager)

add_executable(pong "main.cpp")
target_link_libraries(pong
    Engine
    InputHandlerSystem
    ComponentFactory
    manager
    RenderSystem
    PhysicsSystem
    CollisionSystem
    TextSinkRenderSystem
    sfml-graphics
    sfml-window
    sfml-system
)
