#pragma once

#include <iostream>
#include <filesystem>
#include <memory>
#include <string>
#include <vector>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_utils.hpp>

#include "AssetMetaData.hpp"
#include "XMLSerialiser.hpp"

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Asset class
	template <typename T>
	class Asset
	{
	public:

		/// @brief Meta
		NoLifeNoCry::Engine::AssetMetaData metaData;

		/// @brief Asset properties
		T properties;

		Asset<T>() = delete;

		/// @brief Copy constructor
		/// @param asset Asset
		Asset<T>(const Asset<T>& asset) : className(asset.classsName), fileTypeVersion(asset.fileTypeVersion), metaData(asset.metaData), properties(asset.properties)
		{
			// ...
		}

		/// @brief Move constructor
		/// @param asset Asset
		Asset<T>(Asset<T>&& asset) : className(asset.classsName), fileTypeVersion(asset.fileTypeVersion), metaData(asset.metaData), properties(asset.properties)
		{
			// ...
		}

		/// @brief Constructor
		/// @param className Class name
		/// @param fileTypeVersion File type version
		/// @param metaData Meta data
		/// @param properties Properties
		Asset(const std::filesystem::path& path, std::string&& className, std::string&& fileTypeVersion, NoLifeNoCry::Engine::AssetMetaData&& metaData, T&& properties) : path(path), className(className), fileTypeVersion(fileTypeVersion), metaData(metaData), properties(properties)
		{
			// ...
		}

		/// @brief Destructor
		~Asset()
		{
			// ...
		}

		static std::shared_ptr<Asset<T>> Load(const std::filesystem::path& assetPath)
		{
			std::shared_ptr<Asset<T>> ret(nullptr);
			try
			{
				if (std::filesystem::is_block_file(assetPath) ||
					std::filesystem::is_character_file(assetPath) ||
					std::filesystem::is_regular_file(assetPath))
				{
					std::string asset_path(assetPath.string());
					rapidxml::file<> xml_file(asset_path.c_str());
					rapidxml::xml_document<> xml_document;
					xml_document.parse<0>(xml_file.data());
					rapidxml::xml_node<>* asset_xml_node(xml_document.first_node("Asset"));
					if (asset_xml_node)
					{
						rapidxml::xml_attribute<>* class_xml_attribute(asset_xml_node->first_attribute("class"));
						rapidxml::xml_attribute<>* asset_file_type_version_xml_attribute(asset_xml_node->first_attribute("version"));
						if (class_xml_attribute && asset_file_type_version_xml_attribute)
						{
							std::string class_name(class_xml_attribute->value());
							std::string file_type_version(asset_file_type_version_xml_attribute->value());
							if (file_type_version == "1.0")
							{
								rapidxml::xml_node<>* meta_data_xml_node(asset_xml_node->first_node("Meta"));
								rapidxml::xml_node<>* properties_xml_node(asset_xml_node->first_node("Properties"));
								NoLifeNoCry::Engine::AssetMetaData meta_data;
								T properties;
								if (meta_data_xml_node)
								{
									std::shared_ptr<NoLifeNoCry::Engine::AssetMetaData> meta_data_result(NoLifeNoCry::Engine::XMLSerialiser<NoLifeNoCry::Engine::AssetMetaData>().DeserialiseObject(meta_data_xml_node));
									if (meta_data_result)
									{
										meta_data = *meta_data_result;
									}
								}
								if (properties_xml_node)
								{
									std::shared_ptr<T> properties_result(NoLifeNoCry::Engine::XMLSerialiser<T>().DeserialiseObject(properties_xml_node));
									if (properties_result)
									{
										properties = *properties_result;
									}
								}
								ret = std::make_shared<Asset<T>>(assetPath, std::move(class_name), std::move(file_type_version), std::move(meta_data), std::move(properties));
							}
						}
					}
				}
			}
			catch (const std::exception e)
			{
				std::cerr << "Failed to load asset \"" << assetPath << "\"" << std::endl <<
					e.what() << std::endl;
			}
			catch (int e)
			{
				std::cerr << "Failed to load asset \"" << assetPath << "\"" << std::endl <<
					"Error code: " << e << std::endl;
			}
			catch (...)
			{
				std::cerr << "Failed to load asset \"" << assetPath << "\"" << std::endl <<
					"An unknown error has occured. :(" << std::endl;
			}
			return ret;
		}

		/// @brief Load all assets from a directory
		/// @param assetsDirectoryPath Assets directory path
		/// @param result Result
		/// @return Loaded assets
		static std::vector<std::shared_ptr<Asset<T>>>& LoadAll(const std::filesystem::path& assetsDirectoryPath, std::vector<std::shared_ptr<Asset<T>>>& result)
		{
			result.clear();
			if (std::filesystem::is_directory(assetsDirectoryPath))
			{
				for (const std::filesystem::path& asset_file_path : assetsDirectoryPath)
				{
					if (std::filesystem::is_block_file(asset_file_path) ||
						std::filesystem::is_character_file(asset_file_path) ||
						std::filesystem::is_regular_file(asset_file_path))
					{
						std::shared_ptr<Asset<T>> asset(Load(asset_file_path));
						if (asset)
						{
							result.push_back(asset);
						}
					}
				}
			}
			return result;
		}

		/// @brief Save asset
		/// @return "true" if successful, otherwise "false"
		bool Save()
		{
			return Save(assetPath);
		}

		/// @brief Save asset
		/// @param assetPath Asset path
		/// @return "true" if successful, otherwise "false"
		bool Save(const std::string& assetPath)
		{
			bool ret(false);
			std::ofstream output_file_stream(assetPath);
			if (output_file_stream.is_open())
			{
				rapidxml::xml_document<> xml_document;
				rapidxml::xml_node<>* asset_xml_node(xml_document.allocate_node(rapidxml::node_type::node_element, "Asset"));
				std::string property_value(rttr::type::get<T>().get_name().to_string());
				asset_xml_node->append_attribute(xml_document.allocate_attribute("class", xml_document.allocate_string(property_value.c_str())));
				asset_xml_node->append_attribute(xml_document.allocate_attribute("version", xml_document.allocate_string("1.0")));
				std::shared_ptr<rapidxml::xml_document<>> serialised_meta_data_xml_document(XMLSerialiser<NoLifeNoCry::Engine::AssetMetaData>().SerialiseObject(metaData));
				std::shared_ptr<rapidxml::xml_document<>> serialised_properties_xml_document(XMLSerialiser<T>().SerialiseObject(properties));
				rapidxml::xml_node<>* serialised_meta_data_xml_node(serialised_meta_data_xml_document->first_node());
				rapidxml::xml_node<>* serialised_properties_xml_node(serialised_properties_xml_document->first_node());
				rapidxml::xml_node<>* meta_data_xml_node(xml_document.allocate_node(rapidxml::node_type::node_element, "Meta"));
				rapidxml::xml_node<>* properties_xml_node(xml_document.allocate_node(rapidxml::node_type::node_element, "Properties"));
				rapidxml::xml_node<>* current_serialised_xml_node;
				if (serialised_meta_data_xml_node)
				{
					current_serialised_xml_node = serialised_meta_data_xml_node->first_node();
					while (current_serialised_xml_node)
					{
						meta_data_xml_node->append_node(xml_document.clone_node(current_serialised_xml_node));
						current_serialised_xml_node = current_serialised_xml_node->parent() ? current_serialised_xml_node->next_sibling() : nullptr;
					}
				}
				if (serialised_properties_xml_node)
				{
					current_serialised_xml_node = serialised_properties_xml_node->first_node();
					while (current_serialised_xml_node)
					{
						properties_xml_node->append_node(xml_document.clone_node(current_serialised_xml_node));
						current_serialised_xml_node = current_serialised_xml_node->parent() ? current_serialised_xml_node->next_sibling() : nullptr;
					}
				}
				asset_xml_node->append_node(meta_data_xml_node);
				asset_xml_node->append_node(properties_xml_node);
				xml_document.append_node(asset_xml_node);
				output_file_stream << "<?xml version=\"1.0\"?>" << std::endl << xml_document;
				ret = true;
			}
			return ret;
		}

		/// @brief Get class name
		/// @return Class name
		const std::string& GetClassName() const noexcept
		{
			return className;
		}

		/// @brief Get file type version
		/// @return File type version
		const std::string& GetFileTypeVersion() const noexcept
		{
			return fileTypeVersion;
		}

		Asset& operator=(const Asset&) = delete;
		Asset& operator=(Asset&&) = delete;

	private:

		/// @brief Empty string
		static const std::string emptyString;

		/// @brief Asset path
		std::filesystem::path path;

		/// @brief Asset class name
		std::string className;

		/// @brief File type version
		std::string fileTypeVersion;
	};
}
