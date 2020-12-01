#pragma once

#include <forward_list>
#include <functional>

/// @brief Dirt Machine game engine namespace
namespace DirtMachine
{
	/// @brief Event class
	/// @tparam ...Ts Listener argument types
	template <typename... Ts>
	class Event
	{
	public:

		/// @brief Default constructor
		Event()
		{
			// ...
		}

		/// @brief Copy constructor
		/// @param event Event
		Event(const Event& e)
		{
			*this = e;
		}

		/// @brief Move constructor
		/// @param event Event
		Event(Event&& e)
		{
			*this = e;
		}

		/// @brief Invoke event
		/// @tparam arguments Listener arguments
		void operator()(Ts... arguments)
		{
			for (const auto& listener : listeners)
			{
				listener(arguments...);
			}
		}

		/// @brief Assign operator
		/// @param event Event
		/// @return Itself
		Event& operator=(const Event& e)
		{
			listeners = e.listeners;
			return *this;
		}

		/// @brief Assign operator
		/// @param event Event
		/// @return Itself
		Event& operator=(Event&& e) noexcept
		{
			listeners = e.listeners;
			return *this;
		}

		/// @brief Add listener
		/// @param listener Listener
		/// @return Itself
		Event& operator+=(const std::function<void(Ts...)>& listener)
		{
			listeners.push_front(listener);
			return *this;
		}

		/// @brief Add listener
		/// @param listener Listener
		/// @return Itself
		Event& operator+=(std::function<void(Ts...)>&& listener)
		{
			listeners.push_front(listener);
			return *this;
		}

		/// @brief Add listener
		/// @param listener 
		/// @return Itself
		Event operator+(const std::function<void(Ts...)>& listener)
		{
			return Event(*this) += listener;
		}

		/// @brief Add listener
		/// @param listener Listener
		/// @return Itself
		Event operator+(std::function<void(Ts...)>&& listener)
		{
			return Event(*this) += listener;
		}

		/// @brief Clear
		void Clear()
		{
			listeners.clear();
		}

	private:

		/// @brief Listeners
		std::forward_list<std::function<void(Ts...)>> listeners;
	};
}
