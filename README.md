This project utilizes the Entity-Component-System design pattern to a fault (I
think even the walls are Entities) to simulate a very rough clone of pong.

In order to build this, you will need SFML headers installed in your search path

Then, the following should get you going:

```sh
mkdir build
cd build
cmake ..
make
./bin/pong
```

The `w` and `s` keys are used for player 1 and the `k` and `i` keys are used for
player 2.

On of my goals with this project (as with most of my projects) was to keep the
depedency footprint small - SFML is a very lightweight (the lightest weight I
could find...) library that provides us with a cross-platform method of making a
window and "drawing stuff". If you know of something lighter weight let me know.

Some of the main features of this project:

- Everything is an Entity - I realize that is overkill, but I wanted to really
  get a firm understanding all the pros/cons of the ECS pattern
- Based on the fabulous [Fix Your Timestep!][1] article, a fixed timestep is
  used.
- A custom (very basic) Engine is used: it's simple, but effective (two of my
  favourite adjectives)
- Since everything is an Entity, we have some pretty specific systems to operate
  on them
    - `InputHandlerSystem`[2] manages input from the user - two players can play
      together!
    - `PhysicsSystem`[3] manages momemtum, speed, drag
    - `EventCollissionSystem`[4] reacts to broadcasted events from the PhysicsSystem,
      and figures out if things went "bump"
    - `TextSinkRenderSystem`[5] is used to render text
    - `RenderSystem`[6] is used to draw to the screen

[1]: https://www.gafferongames.com/post/fix_your_timestep/
[2]: src/Systems/InputHandlerSystem.cpp
[3]: src/Systems/PhysicsSystem.cpp
[4]: src/Systems/EventCollisionSystem.cpp
[5]: src/Systems/TextSinkRenderSystem.cpp
[6]: src/Systems/RenderSystem.cpp
