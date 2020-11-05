#pragma once

/// @brief BA3 Game Programming template namespace
namespace BA3GameProgrammingTemplate
{
	/// @brief Game exit code enumerator
	enum class EGameExitCode
	{
		/// @brief Game exited successfully
		Success,

		/// @brief Failed to create window for game
		FailedCreatingWindow,

		/// @brief An unhandled exception was thrown
		UnhandledException,

		/// @brief An unknown error occured
		UnknownError
	};
}
