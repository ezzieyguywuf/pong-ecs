#ifndef IEvent_HEADER
#define IEvent_HEADER

namespace Event{
    class IEvent
    {
        public:
            virtual ~IEvent() = 0;
    };
    inline IEvent::~IEvent(){}
}


#endif //IEvent_HEADER
