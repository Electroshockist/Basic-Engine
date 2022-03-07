#pragma once
#include <vector>

template <typename ...T>
class Event {
	std::vector<void(*)(T...)> callbacks;

public:
	Event() {}

	~Event() {}

	void Subscribe(void(*function)(T...)) {
		callbacks.push_back(function);
	}

	void Unsubscribe(void(*function)(T...)) {
		callbacks.erase(std::remove(callbacks.begin(), callbacks.end(), function), callbacks.end());
	}

	void Invoke(T&... args) {
		if(!callbacks.empty()) {
			for(auto& function : callbacks) {
				function(args...);
			}
		}
	}
};
