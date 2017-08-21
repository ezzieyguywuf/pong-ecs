#include "EventManager.h"
#include <SimpleECS/Types.h>
#include <type_traits>

using Event::EventManager;
using Event::IEvent;
using Func    = std::function<void(const IEvent&)>;

std::map<std::type_index, std::vector<Func>> EventManager::slots;

void EventManager::broadcast(const IEvent& event)
{
    const auto funcs = slots.find(type_index(typeid(event)));
    if (funcs == slots.end())
        return;

    for (const auto func : funcs->second)
    {
        func(event);
    }
}
