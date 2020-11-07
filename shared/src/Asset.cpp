#include "Asset.hpp"

/// @brief Constructor
/// @param className Class name
/// @param metaData Meta data
/// @param properties Properties
NoLifeNoCry::Engine::Asset::Asset(std::string&& className, std::string&& fileTypeVersion, std::unordered_map<std::string, std::string>&& metaData, std::unordered_map<std::string, PropertyVariant>&& properties) : className(className), fileTypeVersion(fileTypeVersion), metaData(metaData), properties(properties)
{
	// ...
}

/// @brief Destructor
NoLifeNoCry::Engine::Asset::~Asset()
{
	// ...
}

/// @brief Get class name
/// @return Class name
const std::string& NoLifeNoCry::Engine::Asset::GetClassName() const noexcept
{
	return className;
}

/// @brief Get file type version
/// @return File type version
const std::string& NoLifeNoCry::Engine::Asset::GetFileTypeVersion() const noexcept
{
	return fileTypeVersion;
}

/// @brief Get all meta data
/// @return All meta data
const std::unordered_map<std::string, std::string>& NoLifeNoCry::Engine::Asset::GetAllMetaData() const noexcept
{
	return metaData;
}

/// @brief Does meta data exist
/// @param name Meta data name
/// @return "true" if property exists, otherwise "false"
bool NoLifeNoCry::Engine::Asset::DoesMetaDataExist(const std::string& name) const noexcept
{
	return metaData.find(name) != metaData.end();
}

/// @brief Get meta data
/// @param name Meta data name
/// @return Property value if successful, otherwise the specified default value
const std::string& NoLifeNoCry::Engine::Asset::GetMetaData(const std::string& name) const noexcept
{
	std::unordered_map<std::string, std::string>::const_iterator iterator(metaData.find(name));
	return (iterator != metaData.end()) ? iterator->second : emptyString;
}

/// @brief Set meta data
/// @param name Meta data name
/// @param value Meta data value
void NoLifeNoCry::Engine::Asset::SetMetaData(const std::string& name, const std::string& value)
{
	metaData.insert_or_assign(name, value);
}

/// @brief Remove meta data
/// @param name Meta data name
/// @return "true" if successful, otherwise "false"
bool NoLifeNoCry::Engine::Asset::RemoveMetaData(const std::string& name)
{
	return static_cast<bool>(metaData.erase(name));
}

/// @brief Get properties
/// @return Properties
const std::unordered_map<std::string, NoLifeNoCry::Engine::Asset::PropertyVariant>& NoLifeNoCry::Engine::Asset::GetAllProperties() const noexcept
{
	return properties;
}

/// @brief Does property exist
/// @param name Property name
/// @return "true" if property exists, otherwise "false"
bool NoLifeNoCry::Engine::Asset::DoesPropertyExist(const std::string& name) const noexcept
{
	return properties.find(name) != properties.end();
}

/// @brief Remove property
/// @param name Property name
/// @return "true" if successful, otherwise "false"
bool NoLifeNoCry::Engine::Asset::RemoveProperty(const std::string& name)
{
	return static_cast<bool>(properties.erase(name));
}

/// @brief Empty string
const std::string NoLifeNoCry::Engine::Asset::emptyString;
