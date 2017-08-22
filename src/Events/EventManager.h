#ifndef EventManager_HEADER
#define EventManager_HEADER

#include "IEvent.h"

#include <map>
#include <typeindex>
#include <functional>
#include <vector>
#include <memory>

using std::vector;
using std::function;
using std::shared_ptr;
using std::type_index;
using std::map;
using Func   = function<void(const Event::IEvent&)>;

namespace Event{
    class EventManager
    {
        public:
            // somebody wishes to react to an event
            template <class T>
            static void attach(std::function<void(const Event::IEvent&)> aFunc);
            // call this method in order to notify slots about an event. This is a 'signal'
            static void broadcast(const IEvent& event);
        private:
            static map<type_index, vector<Func>> slots;
    };

    template <class T>
    inline void EventManager::attach(std::function<void(const IEvent&)> aFunc)
    {
        static_assert(std::is_base_of<IEvent, T>::value, "T must be a base of IEvent");
        if (slots.find(type_index(typeid(T))) == slots.end())
            slots[type_index(typeid(T))];
        slots[type_index(typeid(T))].push_back(aFunc);
    }

}

#endif //EventManager_HEADER
