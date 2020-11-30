#pragma once

#include <memory>

/// @brief No Life, No Cry engine serialiser namespace
namespace NoLifeNoCry::Engine::Serialiser
{
	/// @brief Serialiser class
	/// @tparam TObject Object type
	/// @tparam TInput Input type
	/// @tparam TOutput Output type
	template <typename TObject, typename TInput, typename TOutput>
	class ISerialiser
	{
	public:

		/// @brief Serialise object
		/// @param object Object to serialise
		/// @return Serialised object
		virtual TOutput SerialiseObject(const TObject& object) = 0;

		/// @brief Deserialise object
		/// @param input Input to deserialise
		/// @return Deserialise input if successful, otherwise "nullptr"
		virtual std::shared_ptr<TObject> DeserialiseObject(TInput input) = 0;

		ISerialiser& operator=(const ISerialiser&) = delete;
		ISerialiser& operator=(ISerialiser&&) = delete;
	};
}
