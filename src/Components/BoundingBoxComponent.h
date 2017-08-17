#ifndef BoundingBoxComponent_HEADER
#define BoundingBoxComponent_HEADER

#include <SimpleECS/IComponent.h>

class BoundingBoxComponent : public ecs::IComponent_<BoundingBoxComponent>
{
    public:
        BoundingBoxComponent(float w, float h)
            : width(w), height(h){};

        float width;
        float height;

};

#endif //BoundingBoxComponent_HEADER
