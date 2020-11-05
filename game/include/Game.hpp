#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>
#include <SFML/Window.hpp>

#include "Assets.hpp"
#include "EGameExitCode.hpp"
#include "EGameWindowStyle.hpp"

/// @brief BA3 Game Programming template namespace
namespace BA3GameProgrammingTemplate
{
	/// @brief Game class
	class Game
	{
	public:

		/// @brief Constructor
		/// @param windowWidth Window width
		/// @param windowHeight Window height
		/// @param windowName Window name
		/// @param windowStyle Window style
		Game(std::size_t windowWidth, std::size_t windowHeight, const std::string& windowName, BA3GameProgrammingTemplate::EGameWindowStyle windowStyle);

		/// @brief Destructor
		~Game();

		Game(const Game&) = delete;
		Game(Game&&) = delete;

		/// @brief Read configuration path
		/// @param configurationFilePath Configuration file path
		/// @param result Result
		/// @return "true" if configuration file could be read, otherwise "false"
		bool ReadConfigurationFile(const std::filesystem::path& configurationFilePath, std::unordered_map<std::string, std::string>& result) const;

		/// @brief Start game
		/// @return Game exit code
		BA3GameProgrammingTemplate::EGameExitCode Start();

		Game& operator=(const Game&) = delete;
		Game& operator=(Game&&) = delete;

	private:

		/// @brief SFML window
		sf::Window window;

		/// @brief Game assets
		BA3GameProgrammingTemplate::Assets assets;
	};
}
