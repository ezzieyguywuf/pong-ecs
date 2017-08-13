#include "Entity.h"
#include "Common.h"

int main(int argc, char ** argv) {
    Entity ball("ball");
    ball.components.push_back(new RenderComponent(1));
    RenderSystem renderer;
    renderer.Execute(ball);
    return 0;
}
