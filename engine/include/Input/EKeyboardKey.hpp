#pragma once

#include <SFML/Window/Keyboard.hpp>

/// @brief Dirt Machine game engine input namespace
namespace DirtMachine::Input
{
	/// @brief Keyboard key enumerator
	enum class EKeyboardKey
	{
		/// @brief Unhandled key
		Unknown = sf::Keyboard::Unknown,

		/// @brief The A key
		A = sf::Keyboard::A,

		/// @brief The B key
		B = sf::Keyboard::B,

		/// @brief The C key
		C = sf::Keyboard::C,

		/// @brief The D key
		D = sf::Keyboard::D,

		/// @brief The E key
		E = sf::Keyboard::E,

		/// @brief The F key
		F = sf::Keyboard::F,

		/// @brief The G key
		G = sf::Keyboard::G,

		/// @brief The H key
		H = sf::Keyboard::H,

		/// @brief The I key
		I = sf::Keyboard::I,

		/// @brief The J key
		J = sf::Keyboard::J,

		/// @brief The K key
		K = sf::Keyboard::K,

		/// @brief The L key
		L = sf::Keyboard::L,

		/// @brief The M key
		M = sf::Keyboard::M,

		/// @brief The N key
		N = sf::Keyboard::N,

		/// @brief The O key
		O = sf::Keyboard::O,

		/// @brief The P key
		P = sf::Keyboard::P,

		/// @brief The Q key
		Q = sf::Keyboard::Q,

		/// @brief The R key
		R = sf::Keyboard::R,

		/// @brief The S key
		S = sf::Keyboard::S,

		/// @brief The T key
		T = sf::Keyboard::T,

		/// @brief The U key
		U = sf::Keyboard::U,

		/// @brief The V key
		V = sf::Keyboard::V,

		/// @brief The W key
		W = sf::Keyboard::W,

		/// @brief The X key
		X = sf::Keyboard::X,

		/// @brief The Y key
		Y = sf::Keyboard::Y,

		/// @brief The Z key
		Z = sf::Keyboard::Z,

		/// @brief The 0 key
		Num0 = sf::Keyboard::Num0,

		/// @brief The 1 key
		Num1 = sf::Keyboard::Num1,

		/// @brief The 2 key
		Num2 = sf::Keyboard::Num2,

		/// @brief The 3 key
		Num3 = sf::Keyboard::Num3,

		/// @brief The 4 key
		Num4 = sf::Keyboard::Num4,

		/// @brief The 5 key
		Num5 = sf::Keyboard::Num5,

		/// @brief The 6 key
		Num6 = sf::Keyboard::Num6,

		/// @brief The 7 key
		Num7 = sf::Keyboard::Num7,

		/// @brief The 8 key
		Num8 = sf::Keyboard::Num8,

		/// @brief The 9 key
		Num9 = sf::Keyboard::Num9,

		/// @brief The Escape key
		Escape = sf::Keyboard::Escape,

		/// @brief The left Control key
		LControl = sf::Keyboard::LControl,

		/// @brief The left Shift key
		LShift = sf::Keyboard::LShift,

		/// @brief The left Alt key
		LAlt = sf::Keyboard::LAlt,

		/// @brief The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
		LSystem = sf::Keyboard::LSystem,

		/// @brief The right Control key
		RControl = sf::Keyboard::RControl,

		/// @brief The right Shift key
		RShift = sf::Keyboard::RShift,

		/// @brief The right Alt key
		RAlt = sf::Keyboard::RAlt,

		/// @brief The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
		RSystem = sf::Keyboard::RSystem,

		/// @brief The Menu key
		Menu = sf::Keyboard::Menu,

		/// @brief The [ key
		LBracket = sf::Keyboard::LBracket,

		/// @brief The ] key
		RBracket = sf::Keyboard::RBracket,

		/// @brief The ; key
		Semicolon = sf::Keyboard::Semicolon,

		/// @brief The , key
		Comma = sf::Keyboard::Comma,

		/// @brief The . key
		Period = sf::Keyboard::Period,

		/// @brief The ' key
		Quote = sf::Keyboard::Quote,

		/// @brief The / key
		Slash = sf::Keyboard::Slash,

		/// @brief The \ key
		Backslash = sf::Keyboard::Backslash,

		/// @brief The ~ key
		Tilde = sf::Keyboard::Tilde,

		/// @brief The = key
		Equal = sf::Keyboard::Equal,

		/// @brief The - key (hyphen)
		Hyphen = sf::Keyboard::Hyphen,

		/// @brief The Space key
		Space = sf::Keyboard::Space,

		/// @brief The Enter/Return keys
		Enter = sf::Keyboard::Enter,

		/// @brief The Backspace key
		Backspace = sf::Keyboard::Backspace,

		/// @brief The Tabulation key
		Tab = sf::Keyboard::Tab,

		/// @brief The Page up key
		PageUp = sf::Keyboard::PageUp,

		/// @brief The Page down key
		PageDown = sf::Keyboard::PageDown,

		/// @brief The End key
		End = sf::Keyboard::End,

		/// @brief The Home key
		Home = sf::Keyboard::Home,

		/// @brief The Insert key
		Insert = sf::Keyboard::Insert,

		/// @brief The Delete key
		Delete = sf::Keyboard::Delete,

		/// @brief The + key
		Add = sf::Keyboard::Add,

		/// @brief The - key (minus, usually from numpad)
		Subtract = sf::Keyboard::Subtract,

		/// @brief The * key
		Multiply = sf::Keyboard::Multiply,

		/// @brief The / key
		Divide = sf::Keyboard::Divide,

		/// @brief Left arrow
		Left = sf::Keyboard::Left,

		/// @brief Right arrow
		Right = sf::Keyboard::Right,

		/// @brief Up arrow
		Up = sf::Keyboard::Up,

		/// @brief Down arrow
		Down = sf::Keyboard::Down,

		/// @brief The numpad 0 key
		Numpad0 = sf::Keyboard::Numpad0,

		/// @brief The numpad 1 key
		Numpad1 = sf::Keyboard::Numpad1,

		/// @brief The numpad 1 key
		Numpad2 = sf::Keyboard::Numpad2,

		/// @brief The numpad 2 key
		Numpad3 = sf::Keyboard::Numpad3,

		/// @brief The numpad 3 key
		Numpad4 = sf::Keyboard::Numpad4,

		/// @brief The numpad 4 key
		Numpad5 = sf::Keyboard::Numpad5,

		/// @brief The numpad 5 key
		Numpad6 = sf::Keyboard::Numpad6,

		/// @brief The numpad 6 key
		Numpad7 = sf::Keyboard::Numpad7,

		/// @brief The numpad 7 key
		Numpad8 = sf::Keyboard::Numpad8,

		/// @brief The numpad 8 key
		Numpad9 = sf::Keyboard::Numpad9,

		/// @brief The F1 key
		F1 = sf::Keyboard::F1,

		/// @brief The F2 key
		F2 = sf::Keyboard::F2,

		/// @brief The F3 key
		F3 = sf::Keyboard::F3,

		/// @brief The F4 key
		F4 = sf::Keyboard::F4,

		/// @brief The F5 key
		F5 = sf::Keyboard::F5,

		/// @brief The F6 key
		F6 = sf::Keyboard::F6,

		/// @brief The F7 key
		F7 = sf::Keyboard::F7,

		/// @brief The F8 key
		F8 = sf::Keyboard::F8,

		/// @brief The F9 key
		F9 = sf::Keyboard::F9,

		/// @brief The F10 key
		F10 = sf::Keyboard::F10,

		/// @brief The F11 key
		F11 = sf::Keyboard::F11,

		/// @brief The F12 key
		F12 = sf::Keyboard::F12,

		/// @brief The F13 key
		F13 = sf::Keyboard::F13,

		/// @brief The F14 key
		F14 = sf::Keyboard::F14,

		/// @brief The F15 key
		F15 = sf::Keyboard::F15,

		/// @brief The Pause key
		Pause = sf::Keyboard::Pause
	};
}
