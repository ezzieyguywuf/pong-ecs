#ifndef ComponentTypes_HEADER
#define ComponentTypes_HEADER

#include <string>

// Each Component that is tracked by a Manager will have a unique Component ID
typedef unsigned int ComponentID;
// ComponentMask is a unique identifier for a combination of ComponentID's
typedef std::string ComponentMask;

typedef std::string ComponentName;

#endif /* ifndef ComponentTypes_HEADER */
