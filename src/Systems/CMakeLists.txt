add_library(InputHandlerSystem "InputHandlerSystem.cpp")
target_link_libraries(InputHandlerSystem EventManager)

add_library(RenderSystem "RenderSystem.cpp")
target_link_libraries(RenderSystem
    sfml-graphics)

add_library(PhysicsSystem "PhysicsSystem.cpp")
add_library(CollisionSystem "SimpleCollisionSystem.cpp")
add_library(TextSinkRenderSystem "TextSinkRenderSystem.cpp")
