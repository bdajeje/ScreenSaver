#include "eventsubscriber.hpp"

#include <algorithm>

namespace events {

//std::list<EventSubscriber> EventSubscriber::s_subscribers;
std::map<Event, std::vector<Callback>> EventSubscriber::s_registrations;

void EventSubscriber::emitEvent(Event event)
{
	auto it = s_registrations.find(event);
	if(it == s_registrations.end())
		return;

	std::vector<Callback>& callbacks = it->second;
	bool clean_needed = false;

	for(Callback& callback : callbacks)
	{
		if(callback)
			callback();
		else
			clean_needed = true;
	}

	if(clean_needed)
		cleanRegistrations(callbacks);
}

void EventSubscriber::cleanRegistrations(std::vector<Callback>& callbacks)
{
	std::remove_if(callbacks.begin(), callbacks.end(), [](Callback& callback) {
		return !callback;
	});
}

void EventSubscriber::watchEvent(Event event_type, Callback callback)
{
	s_registrations[event_type].push_back(callback);
}

}
