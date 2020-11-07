#pragma once

#include <string>
#include <unordered_map>
#include <variant>

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Asset class
	class Asset
	{
	public:

		/// @brief Asset property variant
		using PropertyVariant = std::variant<bool, int, float, double, std::string>;

		Asset() = delete;
		Asset(const Asset&) = delete;
		Asset(Asset&&) = delete;

		/// @brief Constructor
		/// @param className Class name
		/// @param fileTypeVersion File type version
		/// @param metaData Meta data
		/// @param properties Properties
		Asset(std::string&& className, std::string&& fileTypeVersion, std::unordered_map<std::string, std::string>&& metaData, std::unordered_map<std::string, PropertyVariant>&& properties);

		/// @brief Destructor
		~Asset();

		/// @brief Get class name
		/// @return Class name
		const std::string& GetClassName() const noexcept;

		/// @brief Get file type version
		/// @return File type version
		const std::string& GetFileTypeVersion() const noexcept;

		/// @brief Get all meta data
		/// @return All meta data
		const std::unordered_map<std::string, std::string>& GetAllMetaData() const noexcept;

		/// @brief Does meta data exist
		/// @param name Meta data name
		/// @return "true" if property exists, otherwise "false"
		bool DoesMetaDataExist(const std::string& name) const noexcept;

		/// @brief Get meta data
		/// @param name Meta data name
		/// @return Property value if successful, otherwise the specified default value
		const std::string& GetMetaData(const std::string& name) const noexcept;

		/// @brief Set meta data
		/// @param name Meta data name
		/// @param value Meta data value
		void SetMetaData(const std::string& name, const std::string& value);

		/// @brief Remove meta data
		/// @param name Meta data name
		/// @return "true" if successful, otherwise "false"
		bool RemoveMetaData(const std::string& name);

		/// @brief Get properties
		/// @return Properties
		const std::unordered_map<std::string, PropertyVariant>& GetAllProperties() const noexcept;

		/// @brief Does property exist
		/// @param name Property name
		/// @return "true" if property exists, otherwise "false"
		bool DoesPropertyExist(const std::string& name) const noexcept;

		/// @brief Get property
		/// @tparam T Property type
		/// @param name Property name
		/// @param defaultValue Default property value
		/// @return Property value if successful, otherwise the specified default value
		template <typename T>
		const T& GetProperty(const std::string& name, const T& defaultValue = default) const noexcept
		{
			const T& ret(defaultValue);
			std::unordered_map<std::string, PropertyVariant>::const_iterator iterator(properties.find(name));
			if (iterator != properties.end())
			{
				T* pointer(std::get_if<T>(&iterator->second));
				ret = pointer ? *pointer : ret;
			}
			return ret;
		}

		/// @brief Set property
		/// @tparam T Property type
		/// @param name Property name
		/// @param value Property value
		template <typename T>
		void SetProperty(const std::string& name, const T& value)
		{
			properties.insert_or_assign(name, value);
		}

		/// @brief Remove property
		/// @param name Property name
		/// @return "true" if successful, otherwise "false"
		bool RemoveProperty(const std::string& name);

		Asset& operator=(const Asset&) = delete;
		Asset& operator=(Asset&&) = delete;

	private:

		/// @brief Empty string
		static const std::string emptyString;

		/// @brief Asset class name
		std::string className;

		/// @brief File type version
		std::string fileTypeVersion;

		/// @brief Asset meta data
		std::unordered_map<std::string, std::string> metaData;

		/// @brief Asset properties
		std::unordered_map<std::string, PropertyVariant> properties;
	};
}
