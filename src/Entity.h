#ifndef Entity_HEADER
#define Entity_HEADER

#include <string>
#include <vector>
#include "IComponent.h"

class Entity{
    public:
        Entity(std::string aName)
            : name(aName){};

        std::vector<IComponent*> components;

    private:
        std::string name;
};

#endif //Entity_HEADER
