#pragma once

#include <cstdint>
#include <stdexcept>
#include <sstream>
#include <string>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rttr/registration.h>
#include <Serialiser/ISerialiser.hpp>

/// @brief No Life, No Cry engine serialiser namespace
namespace NoLifeNoCry::Engine::Serialiser
{
	/// @brief XML serialiser class
	/// @tparam TObject Object type
	template <typename TObject>
	class XMLSerialiser : public NoLifeNoCry::Engine::Serialiser::ISerialiser<TObject, rapidxml::xml_node<>*, std::shared_ptr<rapidxml::xml_document<>>>
	{
	public:

		/// @brief Default constructor
		XMLSerialiser<TObject>()
		{
			// ...
		}

		/// @brief Destructor
		~XMLSerialiser<TObject>()
		{
			// ...
		}

		/// @brief Serialise object
		/// @param object Object to serialise
		/// @return Serialised object
		std::shared_ptr<rapidxml::xml_document<>> SerialiseObject(const TObject& object) override
		{
			std::shared_ptr<rapidxml::xml_document<>> ret(std::make_shared<rapidxml::xml_document<>>());
			rttr::type type(rttr::type::get<TObject>());
			if (type)
			{
				std::string type_name(type.get_name().to_string());
				rapidxml::xml_node<>* root_xml_node(ret->allocate_node(rapidxml::node_type::node_element, ret->allocate_string(type_name.c_str())));
				ret->append_node(root_xml_node);
				for (const rttr::property& property : type.get_properties())
				{
					std::string property_name(property.get_name().to_string());
					std::string property_value(property.get_value(object).to_string());
					SerialiseProperty(property, object, root_xml_node);
				}
			}
			return ret;
		}

		/// @brief Deserialise object
		/// @param input Input to deserialise
		/// @return Deserialise input if successful, otherwise "nullptr"
		std::shared_ptr<TObject> DeserialiseObject(rapidxml::xml_node<>* input) override
		{
			if (!input)
			{
				throw std::invalid_argument("Argument \"input\" is null.");
			}
			std::shared_ptr<TObject> ret(std::make_shared<TObject>());
			rttr::type type(rttr::type::get<TObject>());
			for (const rttr::property& property : type.get_properties())
			{
				std::string property_name(property.get_name());
				DeserialiseProperty(property, *(ret.get()), input->first_node(property_name.c_str()));
			}
			return ret;
		}

	private:

		/// @brief Serialise property
		/// @param property Property
		/// @param instance Instance
		/// @param parentXMLNode Parent XML node
		void SerialiseProperty(const rttr::property& property, const rttr::instance& instance, rapidxml::xml_node<>* parentXMLNode)
		{
			rttr::type property_type(property.get_type());
			rttr::variant property_variant(property.get_value(instance));
			while (property_type.is_wrapper())
			{
				property_variant = property_variant.extract_wrapped_value();
				property_type = property_type.get_wrapped_type();
			}
			rapidxml::xml_document<>* xml_document(parentXMLNode->document());
			std::string property_name(property.get_name());
			if ((property_type == rttr::type::get<std::int8_t>()) ||
				(property_type == rttr::type::get<std::uint8_t>()) ||
				(property_type == rttr::type::get<std::int16_t>()) ||
				(property_type == rttr::type::get<std::uint16_t>()) ||
				(property_type == rttr::type::get<std::int32_t>()) ||
				(property_type == rttr::type::get<std::uint32_t>()) ||
				(property_type == rttr::type::get<std::int64_t>()) ||
				(property_type == rttr::type::get<std::uint64_t>()) ||
				(property_type == rttr::type::get<float>()) ||
				(property_type == rttr::type::get<double>()) ||
				(property_type == rttr::type::get<std::string>()))
			{
				std::string property_value(property_variant.to_string());
				parentXMLNode->append_node(xml_document->allocate_node(rapidxml::node_element, xml_document->allocate_string(property_name.c_str()), xml_document->allocate_string(property_value.c_str())));
			}
			else
			{
				std::string property_value(property_variant.to_string());
				rttr::instance property_instance(property_variant);
				rapidxml::xml_node<>* property_xml_node(xml_document->allocate_node(rapidxml::node_element, xml_document->allocate_string(property_name.c_str())));
				parentXMLNode->append_node(property_xml_node);
				for (const rttr::property& property_property : property_type.get_properties())
				{
					SerialiseProperty(property_property, property_instance, property_xml_node);
				}
			}
		}

		/// @brief Deserialise property
		/// @param property Property
		/// @param instance Instance
		/// @param input Input
		void DeserialiseProperty(const rttr::property& property, const rttr::instance& instance, rapidxml::xml_node<>* input)
		{
			if (input)
			{
				rttr::type property_type(property.get_type());
				if (property_type == rttr::type::get<std::int8_t>())
				{
					property.set_value(instance, static_cast<std::int8_t>(std::stoi(input->value())));
				}
				else if (property_type == rttr::type::get<std::uint8_t>())
				{
					property.set_value(instance, static_cast<std::uint8_t>(std::stoi(input->value())));
				}
				else if (property_type == rttr::type::get<std::int16_t>())
				{
					property.set_value(instance, static_cast<std::int16_t>(std::stoi(input->value())));
				}
				else if (property_type == rttr::type::get<std::uint16_t>())
				{
					property.set_value(instance, static_cast<std::uint16_t>(std::stoi(input->value())));
				}
				else if (property_type == rttr::type::get<std::int32_t>())
				{
					property.set_value(instance, static_cast<std::int32_t>(std::stoi(input->value())));
				}
				else if (property_type == rttr::type::get<std::uint32_t>())
				{
					property.set_value(instance, static_cast<std::uint32_t>(std::stoul(input->value())));
				}
				else if (property_type == rttr::type::get<std::int64_t>())
				{
					property.set_value(instance, static_cast<std::int64_t>(std::stol(input->value())));
				}
				else if (property_type == rttr::type::get<std::uint64_t>())
				{
					property.set_value(instance, static_cast<std::uint64_t>(std::stoul(input->value())));
				}
				else if (property_type == rttr::type::get<float>())
				{
					property.set_value(instance, static_cast<float>(std::stof(input->value())));
				}
				else if (property_type == rttr::type::get<double>())
				{
					property.set_value(instance, static_cast<double>(std::stod(input->value())));
				}
				else if (property_type == rttr::type::get<std::string>())
				{
					std::string name(property.get_name());
					property.set_value(instance, std::string(input->value()));
				}
				else
				{
					rttr::variant property_variant(property.get_value(instance));
					while (property_type.is_wrapper())
					{
						property_variant = property_variant.extract_wrapped_value();
						property_type = property_variant.get_type();
					}
					rttr::instance property_instance(property_variant);
					for (const rttr::property& property_property : property_type.get_properties())
					{
						std::string property_property_name(property_property.get_name());
						DeserialiseProperty(property_property, property_instance, input->first_node(property_property_name.c_str()));
					}
				}
			}
		}
	};
}
