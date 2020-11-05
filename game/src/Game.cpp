#include <iostream>
#include <rapidxml_utils.hpp>

#include "Game.hpp"

/// @brief Constructor
/// @param windowWidth Window width
/// @param windowHeight Window height
/// @param windowName Window name
/// @param windowStyle Window style
BA3GameProgrammingTemplate::Game::Game(std::size_t windowWidth, std::size_t windowHeight, const std::string& windowName, BA3GameProgrammingTemplate::EGameWindowStyle windowStyle) : window(sf::VideoMode(static_cast<unsigned int>(windowWidth), static_cast<unsigned int>(windowHeight)), windowName, static_cast<sf::Uint32>(windowStyle))
{
    // ...
}

/// @brief Destructor
BA3GameProgrammingTemplate::Game::~Game()
{
	// ...
}

// @brief Read configuration path
/// @param configurationFilePath Configuration file path
/// @param result Result
/// @return "true" if configuration file could be read, otherwise "false"
bool BA3GameProgrammingTemplate::Game::ReadConfigurationFile(const std::filesystem::path& configurationFilePath, std::unordered_map<std::string, std::string>& result) const
{
    bool ret(false);
    result.clear();
    if (std::filesystem::exists(configurationFilePath))
    {
        std::string path(configurationFilePath.string());
        rapidxml::file<> xml_file(path.c_str());
        rapidxml::xml_document<> xml_document;
        xml_document.parse<0>(xml_file.data());
        rapidxml::xml_node<>* xml_node(xml_document.first_node());
        while (xml_node)
        {
            result.insert_or_assign(xml_node->name(), xml_node->value());
            xml_node = xml_node->parent() ? xml_node->next_sibling() : nullptr;
        }
        ret = true;
    }
    return ret;
}

/// @brief Start game
/// @return Game exit code
BA3GameProgrammingTemplate::EGameExitCode BA3GameProgrammingTemplate::Game::Start()
{
    BA3GameProgrammingTemplate::EGameExitCode ret(BA3GameProgrammingTemplate::EGameExitCode::FailedCreatingWindow);
    std::shared_ptr<BA3GameProgrammingTemplate::Asset> test_asset(assets.LoadAsset("./assets/TestAsset.xml"));
    if (test_asset)
    {
        std::cout <<
            "Loaded test asset!" << std::endl <<
            "\tAsset class name: " << test_asset->GetClassName() << std::endl <<
            "\tAsset file type version: " << test_asset->GetFileTypeVersion() << std::endl <<
            "\tMeta data:" << std::endl;
        for (const std::pair<std::string, std::string>& meta_data : test_asset->GetAllMetaData())
        {
            std::cout << "\t\tKey: \"" << meta_data.first << "\"" << std::endl <<
                "\t\tValue: \"" << meta_data.second << "\"" << std::endl << std::endl;
        }
        std::cout << "\tProperties:" << std::endl;
        for (const std::pair<std::string, BA3GameProgrammingTemplate::Asset::PropertyVariant>& property : test_asset->GetAllProperties())
        {
            std::cout << "\t\tKey: \"" << property.first << "\"" << std::endl;
            auto* boolean_result(std::get_if<bool>(&(property.second)));
            if (boolean_result)
            {
                std::cout << "\t\tValue: \"" << (*boolean_result ? "true" : "false") << "\" : bool" << std::endl << std::endl;
            }
            else
            {
                auto* integer_result(std::get_if<int>(&(property.second)));
                if (integer_result)
                {
                    std::cout << "\t\tValue: \"" << *integer_result << "\" : int" << std::endl << std::endl;
                }
                else
                {
                    auto* single_result(std::get_if<float>(&(property.second)));
                    if (single_result)
                    {
                        std::cout << "\t\tValue: \"" << *single_result << "\" : float" << std::endl << std::endl;
                    }
                    else
                    {
                        auto* double_result(std::get_if<double>(&(property.second)));
                        if (double_result)
                        {
                            std::cout << "\t\tValue: \"" << *double_result << "\" : double" << std::endl << std::endl;
                        }
                        else
                        {
                            auto* string_result(std::get_if<std::string>(&(property.second)));
                            if (string_result)
                            {
                                std::cout << "\t\tValue: \"" << *string_result << "\" : std::string" << std::endl << std::endl;
                            }
                            else
                            {
                                std::cout << "\t\tValue: Unknown" << std::endl << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "Failed to load test asset!" << std::endl;
    }
    while (window.isOpen())
    {
        ret = BA3GameProgrammingTemplate::EGameExitCode::Success;
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New window size: (" << event.size.width << ", " << event.size.height << ")" << std::endl;
                break;
            case sf::Event::LostFocus:
                std::cout << "Window lost focus." << std::endl;
                break;
            case sf::Event::GainedFocus:
                std::cout << "Window gained focus." << std::endl;
                break;
            case sf::Event::TextEntered:
                std::cout << "Text entered: " << event.text.unicode << std::endl;
                break;
            case sf::Event::KeyPressed:
                std::cout << "Key pressed: " << (event.key.system ? "Sys+" : "") << (event.key.control ? "Ctrl+" : "") << (event.key.alt ? "Alt+" : "") << (event.key.code) << std::endl;
                break;
            case sf::Event::KeyReleased:
                std::cout << "Key released: " << (event.key.system ? "Sys+" : "") << (event.key.control ? "Ctrl+" : "") << (event.key.alt ? "Alt+" : "") << (event.key.code) << std::endl;
                break;
            case sf::Event::MouseWheelScrolled:
                std::cout << "Mouse wheel scrolled: " << event.mouseWheelScroll.wheel << " : " << event.mouseWheelScroll.delta << " at (" << event.mouseWheelScroll.x << ", " << event.mouseWheelScroll.y << ")" << std::endl;
                break;
            case sf::Event::MouseButtonPressed:
                std::cout << "Mouse button pressed: " << event.mouseButton.button << " at (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
                break;
            case sf::Event::MouseButtonReleased:
                std::cout << "Mouse button released: " << event.mouseButton.button << " at (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
                break;
            case sf::Event::MouseMoved:
                std::cout << "Mouse moved: (" << event.mouseMove.x << ", " << event.mouseMove.y << ")" << std::endl;
                break;
            case sf::Event::MouseEntered:
                std::cout << "Mouse has entered the window." << std::endl;
                break;
            case sf::Event::MouseLeft:
                std::cout << "Mouse has left the window." << std::endl;
                break;
            case sf::Event::JoystickButtonPressed:
                std::cout << "Joystick button pressed: " << event.joystickButton.button << " at joystick ID " << event.joystickButton.joystickId << std::endl;
                break;
            case sf::Event::JoystickButtonReleased:
                std::cout << "Joystick button released: " << event.joystickButton.button << " at joystick ID " << event.joystickButton.joystickId << std::endl;
                break;
            case sf::Event::JoystickMoved:
                std::cout << "Joystick moved: " << event.joystickMove.position << " with axis " << event.joystickMove.axis << " at joystick ID " << event.joystickMove.joystickId << std::endl;
                break;
            case sf::Event::JoystickConnected:
                std::cout << "Joystick ID " << event.joystickConnect.joystickId << " has been connected." << std::endl;
                break;
            case sf::Event::JoystickDisconnected:
                std::cout << "Joystick ID " << event.joystickConnect.joystickId << " has been disconnected." << std::endl;
                break;
            case sf::Event::TouchBegan:
                std::cout << "Touch began: Finger " << event.touch.finger << " at (" << event.touch.x << ", " << event.touch.y << ")" << std::endl;
                break;
            case sf::Event::TouchMoved:
                std::cout << "Touch moved: Finger " << event.touch.finger << " at (" << event.touch.x << ", " << event.touch.y << ")" << std::endl;
                break;
            case sf::Event::TouchEnded:
                std::cout << "Touch ended: Finger " << event.touch.finger << " at (" << event.touch.x << ", " << event.touch.y << ")" << std::endl;
                break;
            case sf::Event::SensorChanged:
                std::cout << "Sensor changed: Type " << event.sensor.type << " at (" << event.sensor.x << ", " << event.sensor.y << ", " << event.sensor.z << ")" << std::endl;
                break;
            }
        }
    }
	return ret;
}
