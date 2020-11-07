#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>

#include "Assets.hpp"
#include "EExitCode.hpp"
#include "Window.hpp"

/// @brief No Life, No Cry game namespace
namespace NoLifeNoCry::Game
{
	/// @brief Game window class
	class GameWindow : public NoLifeNoCry::Engine::Window
	{
	public:

		/// @brief Constructor
		/// @param windowWidth Window width
		/// @param windowHeight Window height
		/// @param windowName Window name
		/// @param windowStyle Window style
		GameWindow(std::size_t windowWidth, std::size_t windowHeight, const std::string& windowName, NoLifeNoCry::Engine::EWindowStyle windowStyle);

		/// @brief Destructor
		~GameWindow();

		GameWindow(const GameWindow&) = delete;
		GameWindow(GameWindow&&) = delete;

		/// @brief Start game
		/// @return Game exit code
		NoLifeNoCry::Engine::EExitCode Start();

		GameWindow& operator=(const GameWindow&) = delete;
		GameWindow& operator=(GameWindow&&) = delete;

	private:

		/// @brief Game assets
		NoLifeNoCry::Engine::Assets assets;
	};
}
