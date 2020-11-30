#pragma once

#include <filesystem>
#include <memory>
#include <string>
#include <vector>
#include <EExitCode.hpp>
#include <SaveGame.hpp>
#include <UI/Window.hpp>

/// @brief No Life, No Cry game namespace
namespace NoLifeNoCry::Game
{
	/// @brief Game window class
	class GameWindow : public NoLifeNoCry::Engine::UI::Window
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

		GameWindow& operator=(const GameWindow&) = delete;
		GameWindow& operator=(GameWindow&&) = delete;

	private:

		/// @brief Save games
		std::vector<std::shared_ptr<NoLifeNoCry::Game::SaveGame>> saveGames;
	};
}
