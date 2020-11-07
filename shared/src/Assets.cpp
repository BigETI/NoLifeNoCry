#include <filesystem>
#include <iostream>
#include <rapidxml_utils.hpp>

#include "Assets.hpp"

/// @brief Default constructor
NoLifeNoCry::Engine::Assets::Assets()
{
	// ...
}

/// @brief Destructor
NoLifeNoCry::Engine::Assets::~Assets()
{
	// ...
}

/// @brief Load asset
/// @param assetPath Path to asset
/// @return Asset pointer if successful, otherwise "nullptr"
std::shared_ptr<NoLifeNoCry::Engine::Asset> NoLifeNoCry::Engine::Assets::LoadAsset(const std::string& assetPath)
{
	std::shared_ptr<NoLifeNoCry::Engine::Asset> ret(noAsset);
	std::unordered_map<std::string, std::shared_ptr<NoLifeNoCry::Engine::Asset>>::const_iterator iterator(assetCache.find(assetPath));
	if (iterator == assetCache.end())
	{
		// TODO: Load asset from file
		if (std::filesystem::exists(assetPath))
		{;
			rapidxml::file<> xml_file(assetPath.c_str());
			rapidxml::xml_document<> xml_document;
			xml_document.parse<0>(xml_file.data());
			rapidxml::xml_node<>* asset_xml_node(xml_document.first_node("Asset"));
			if (asset_xml_node)
			{
				rapidxml::xml_attribute<>* class_xml_attribute(asset_xml_node->first_attribute("class"));
				rapidxml::xml_attribute<>* version_xml_attribute(asset_xml_node->first_attribute("version"));
				if (class_xml_attribute && version_xml_attribute)
				{
					std::string class_name(class_xml_attribute->value());
					std::string asset_file_type_version(version_xml_attribute->value());
					std::unordered_map<std::string, std::string> meta_data;
					std::unordered_map<std::string, NoLifeNoCry::Engine::Asset::PropertyVariant> properties;
					if (asset_file_type_version == "1.0")
					{
						rapidxml::xml_node<>* entry_xml_node(nullptr);
						rapidxml::xml_node<>* meta_xml_node(asset_xml_node->first_node("Meta"));
						if (meta_xml_node)
						{
							entry_xml_node = meta_xml_node->first_node();
							while (entry_xml_node)
							{
								meta_data.insert_or_assign(entry_xml_node->name(), entry_xml_node->value());
								entry_xml_node = entry_xml_node->parent() ? entry_xml_node->next_sibling() : nullptr;
							}
						}
						rapidxml::xml_node<>* properties_xml_node(asset_xml_node->first_node("Properties"));
						if (properties_xml_node)
						{
							entry_xml_node = properties_xml_node->first_node();
							while (entry_xml_node)
							{
								std::string entry_name(entry_xml_node->name());
								rapidxml::xml_attribute<>* entry_type_xml_attribute(entry_xml_node->first_attribute("type"));
								if (entry_type_xml_attribute)
								{
									std::string entry_type(entry_type_xml_attribute->value());
									std::string entry_value(entry_xml_node->value());
									if (entry_type == "Boolean")
									{
										properties.insert_or_assign(entry_name, (entry_value == "true") || (entry_value == "1"));
									}
									else if (entry_type == "Integer")
									{
										properties.insert_or_assign(entry_name, std::stoi(entry_value));
									}
									else if (entry_type == "Single")
									{
										properties.insert_or_assign(entry_name, std::stof(entry_value));
									}
									else if (entry_type == "Double")
									{
										properties.insert_or_assign(entry_name, std::stod(entry_value));
									}
									else if (entry_type == "String")
									{
										properties.insert_or_assign(entry_name, entry_value);
									}
									else
									{
										std::cerr << "Unknown property type \"" << entry_type << "\"." << std::endl;
									}
								}
								entry_xml_node = entry_xml_node->parent() ? entry_xml_node->next_sibling() : nullptr;
							}
						}
						ret = std::make_shared<NoLifeNoCry::Engine::Asset>(std::move(class_name), std::move(asset_file_type_version), std::move(meta_data), std::move(properties));
						assetCache.insert_or_assign(assetPath, ret);
					}
					else
					{
						std::cerr << "Asset file type version \"" << asset_file_type_version << "\" is not supported." << std::endl;
					}
				}
			}
		}
	}
	else
	{
		ret = iterator->second;
	}
	return ret;
}

/// @brief Remove asset from cache
/// @param assetPath Asset path
/// @return "true" if successful, otherwise "false"
bool NoLifeNoCry::Engine::Assets::RemoveAssetFromCache(const std::string& assetPath)
{
	return static_cast<bool>(assetCache.erase(assetPath));
}

/// @brief Clear asset cache
void NoLifeNoCry::Engine::Assets::ClearAssetCache()
{
	assetCache.clear();
}

/// @brief No asset
const std::shared_ptr<NoLifeNoCry::Engine::Asset> NoLifeNoCry::Engine::Assets::noAsset;
