#add_subdirectory("Systems")
#add_subdirectory("Components")

#add_library(engine "Engine.cpp")
#target_link_libraries(engine sfml-system)

#add_library(SFMLComponentFactory "SFMLComponentFactory.cpp")
#target_link_libraries(SFMLComponentFactory sfml-graphics)

add_executable(pong "main.cpp")
target_link_libraries(pong
    #SFMLComponentFactory
    #engine
    #Component_RenderSFML
    sfml-graphics
    sfml-window
    sfml-system
)

#add_library(SFMLComponentFactory_Main "SFMLComponentFactory.cpp")
#target_link_libraries(SFMLComponentFactory_Main sfml-graphics)
