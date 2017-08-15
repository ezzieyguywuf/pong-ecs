#ifndef ISystem_HEADER
#define ISystem_HEADER

class ISystem
{
    public:
        ~ISystem(){};

        virtual void Execute() const = 0;

};

#endif //ISystem_HEADER
