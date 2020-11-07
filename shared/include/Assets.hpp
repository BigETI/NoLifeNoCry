#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Asset.hpp"

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Assets class
	class Assets
	{
	public:

		/// @brief Default constructor
		Assets();

		Assets(const Assets&) = delete;
		Assets(Assets&&) = delete;

		/// @brief Destructor
		~Assets();

		/// @brief Load asset
		/// @param assetPath Path to asset
		/// @return Asset pointer if successful, otherwise "nullptr"
		std::shared_ptr<NoLifeNoCry::Engine::Asset> LoadAsset(const std::string& assetPath);

		/// @brief Remove asset from cache
		/// @param assetPath Asset path
		/// @return "true" if successful, otherwise "false"
		bool RemoveAssetFromCache(const std::string& assetPath);

		/// @brief Clear asset cache
		void ClearAssetCache();

		Assets& operator=(const Assets&) = delete;
		Assets& operator=(Assets&&) = delete;

	private:

		/// @brief No asset
		static const std::shared_ptr<NoLifeNoCry::Engine::Asset> noAsset;

		/// @brief Asset cache
		std::unordered_map<std::string, std::shared_ptr<NoLifeNoCry::Engine::Asset>> assetCache;
	};
}
