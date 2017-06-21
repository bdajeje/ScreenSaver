#ifndef EVENTSUBSCRIBER_H
#define EVENTSUBSCRIBER_H

#include <map>
#include <vector>

#include "event_types.hpp"

namespace events {

class EventSubscriber
{
	protected:

	  void watchEvent(Event event_type, std::function<>());

	protected:

	  std::map<Event, std::vector<std::function<>()>> _registrations;
};

}

#endif // EVENTSUBSCRIBER_H
