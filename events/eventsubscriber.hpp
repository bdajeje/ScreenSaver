#ifndef EVENTSUBSCRIBER_H
#define EVENTSUBSCRIBER_H

#include <functional>
#include <list>
#include <map>
#include <vector>

#include "event_types.hpp"

namespace events {

class EventSubscriber;

//using Callback = std::function<void(const EventSubscriber*)>;
using Callback = std::function<void()>;

class EventSubscriber
{
	protected:

	  void watchEvent(Event event_type, Callback callback);
	  void emitEvent(Event event); // \todo: this method has nothing to do here, either extract it under the events namespace or under a EventEmitter class

	private:

	  void cleanRegistrations(std::vector<Callback>& callbacks);

	protected:

	  static std::map<Event, std::vector<Callback>> s_registrations;

//	  static std::list<EventSubscriber> s_subscribers;
};

}

#endif // EVENTSUBSCRIBER_H
