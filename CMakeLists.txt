cmake_minimum_required(VERSION 3.11)
project(NoLifeNoCry LANGUAGES C CXX VERSION 0.0.1)

SET(j "0" CACHE STRING "Use parallelism?")

# Standard libraries
if(MSVC)
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
elseif(UNIX)
	# Linux GCC/Clang
	if(NOT APPLE)
		set(CMAKE_CXX_STDLIB "libstdc++" CACHE STRING "The standard library to use.")
		set(CROSS_BUILD FALSE CACHE BOOL "Whether to cross-build.")
		set(CROSS_BUILD_ARCH "armv6" CACHE STRING "The architecture to cross-build for.")
	# Apple Clang
	else()
		set(CMAKE_CXX_STDLIB "libc++" CACHE STRING "The standard library to use.")

		set(CROSS_BUILD FALSE)
		set(CROSS_BUILD_ARCH)

		set(CMAKE_THREAD_LIBS_INIT "-lpthread")
		set(CMAKE_HAVE_THREADS_LIBRARY 1)
		set(CMAKE_USE_WIN32_THREADS_INIT 0)
		set(CMAKE_USE_PTHREADS_INIT 1)
		set(THREADS_PREFER_PTHREAD_FLAG ON)
	endif()

	set(CMAKE_C_FLAGS "-pthread")
	set(CMAKE_CXX_FLAGS "-fno-sized-deallocation -std=gnu++20 -Wno-register -pthread -static-libstdc++")
	
	# If not cross-building, assume we're using a x86_64 compiler
	if(CROSS_BUILD)
		set(CMAKE_CXX_FLAGS "-march=${CROSS_BUILD_ARCH} ${CMAKE_CXX_FLAGS}")
		message("Generating cross-build project for ${CROSS_BUILD_ARCH}.")
	else()
		set(CMAKE_C_FLAGS "-m32 ${CMAKE_C_FLAGS}")
		set(CMAKE_CXX_FLAGS "-m32 ${CMAKE_CXX_FLAGS}")
		message("Generating x86 project")
	endif()
	# Clang or Apple Clang
	if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=${CMAKE_CXX_STDLIB} -fvisibility=hidden -Wno-switch -Wno-unused-command-line-argument")
	endif()

endif()

# set up configuration types
if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release;DebugPreprocess" CACHE STRING "" FORCE)
else()
	if(NOT CMAKE_BUILD_TYPE)
		set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
	endif()
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY HELPSTRING "Choose the type of build.")
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release;DebugPreprocess")
endif()
if(MSVC)
	set(flags_DebugPreprocess "/P")
else()
	set(flags_DebugPreprocess "-E")
endif()

function(enable_warnings proj)
	# GLM_FORCE_SILENT_WARNINGS Disables warnings in GLM.
	# 4100 is `unreferenced formal parameter` in MSVC.
	if(MSVC)
		target_compile_options(${proj} PRIVATE /W4 /WX /wd4100 /wd4307 -DGLM_FORCE_SILENT_WARNINGS)
	else()
		target_compile_options(${proj} PRIVATE -Wall -Wextra -pedantic -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-strict-aliasing -DGLM_FORCE_SILENT_WARNINGS)
		if (CROSS_BUILD)
			target_compile_options(${proj} PRIVATE -Wno-attributes)
		endif()
	endif()
endfunction()

# set up special DebugPreprocess type (will preprocess files and output the result)
set(CMAKE_C_FLAGS_DEBUGPREPROCESS "${CMAKE_C_FLAGS_DEBUG} ${flags_DebugPreprocess}")
set(CMAKE_CXX_FLAGS_DEBUGPREPROCESS "${CMAKE_CXX_FLAGS_DEBUG} ${flags_DebugPreprocess}")
set(CMAKE_EXE_LINKER_FLAGS_DEBUGPREPROCESS ${CMAKE_EXE_LINKER_FLAGS_DEBUG})
set(CMAKE_SHARED_LINKER_FLAGS_DEBUGPREPROCESS ${CMAKE_SHARED_LINKER_FLAGS_DEBUG})
set(CMAKE_MODULE_LINKER_FLAGS_DEBUGPREPROCESS ${CMAKE_MODULE_LINKER_FLAGS_DEBUG})

# Flags to know when we are compiling in Debug mode.
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DO_PRINTF")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DO_PRINTF")

if(WIN32)
	# https://stackoverflow.com/questions/42946335/deprecated-header-codecvt-replacement
	# `codecvt` is deprecated, but is defined as remaining until a more secure replacement is
	# standardised, thus just defining `_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING` is fine.
	add_definitions(
		-D_CRT_SECURE_NO_WARNINGS
		-D_WINSOCK_DEPRECATED_NO_WARNINGS
		-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
		-DWIN32_LEAN_AND_MEAN
	)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL GNU)
	add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
endif()

add_subdirectory(dependencies)

########################
#                      #
# Game project (begin) #
#                      #
########################

set(PROJECT game)

add_executable(game "")

# Compiler options
if(MSVC)
	target_compile_options(game PRIVATE "/bigobj")
	if(NOT j STREQUAL "0")
		target_compile_options(game PRIVATE "/MP${j}")
	endif()
else()
	if(NOT j STREQUAL "0")
		target_compile_options(game PRIVATE "-j ${j}")
	endif()
endif()

# Enable warnings
enable_warnings(game)

# Shared include files
add_subdirectory(shared/include include-shared-game)
get_property(SHARED_INCLUDE_FILES TARGET game PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/shared/include PREFIX shared/include FILES ${SHARED_INCLUDE_FILES})
set_property(TARGET game PROPERTY SOURCES "")

# Shared source files
add_subdirectory(shared/src src-shared-game)
get_property(SHARED_SOURCE_FILES TARGET game PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/shared/src PREFIX shared/src FILES ${SHARED_SOURCE_FILES})
set_property(TARGET game PROPERTY SOURCES "")

# Game include files
add_subdirectory(game/include include-game)
get_property(GAME_INCLUDE_FILES TARGET game PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/game/include PREFIX game/include FILES ${GAME_INCLUDE_FILES})
set_property(TARGET game PROPERTY SOURCES "")

# Game source files
add_subdirectory(game/src src-game)
get_property(GAME_SOURCE_FILES TARGET game PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/game/src PREFIX game/src FILES ${GAME_SOURCE_FILES})
set_property(TARGET game PROPERTY SOURCES "")

# Target all files
set_property(TARGET game PROPERTY SOURCES "${SHARED_INCLUDE_FILES};${SHARED_SOURCE_FILES};${GAME_INCLUDE_FILES};${GAME_SOURCE_FILES}")

# Target include directories
target_include_directories(game PUBLIC shared/include)
target_include_directories(game PUBLIC game/include)
target_include_directories(game PUBLIC dependencies/cista/include)

# Set compile definitions
target_compile_definitions(game PUBLIC
	WIN32_LEAN_AND_MEAN
	NOGDI
)

# Target libraries for linking
target_link_libraries(game
	CONAN_PKG::glm
	CONAN_PKG::rapidxml
	CONAN_PKG::sfml
)

# Copy files from "./game/resources" to binary output directories
foreach(CMAKE_CONFIGURATION_TYPE ${CMAKE_CONFIGURATION_TYPES})
	add_custom_command(
		TARGET game POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
			${CMAKE_CURRENT_SOURCE_DIR}/game/resources/
			${PROJECT_BINARY_DIR}/${CMAKE_CONFIGURATION_TYPE})
endforeach()

# Output name
set_property(TARGET game PROPERTY OUTPUT_NAME NoLifeNoCry)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT game)

unset(PROJECT)

######################
#                    #
# Game project (end) #
#                    #
######################

##########################
#                        #
# Editor project (begin) #
#                        #
##########################

set(PROJECT editor)

add_executable(editor "")

# Compiler options
if(MSVC)
	target_compile_options(editor PRIVATE "/bigobj")
	if(NOT j STREQUAL "0")
		target_compile_options(editor PRIVATE "/MP${j}")
	endif()
else()
	if(NOT j STREQUAL "0")
		target_compile_options(editor PRIVATE "-j ${j}")
	endif()
endif()

# Enable warnings
enable_warnings(editor)

# Shared include files
add_subdirectory(shared/include include-shared-editor)
get_property(SHARED_INCLUDE_FILES TARGET editor PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/shared/include PREFIX shared/include FILES ${SHARED_INCLUDE_FILES})
set_property(TARGET editor PROPERTY SOURCES "")

# Shared source files
add_subdirectory(shared/src src-shared-editor)
get_property(SHARED_SOURCE_FILES TARGET editor PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/shared/src PREFIX shared/src FILES ${SHARED_SOURCE_FILES})
set_property(TARGET editor PROPERTY SOURCES "")

# Editor include files
add_subdirectory(editor/include include-editor)
get_property(EDITOR_INCLUDE_FILES TARGET editor PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/editor/include PREFIX editor/include FILES ${EDITOR_INCLUDE_FILES})
set_property(TARGET editor PROPERTY SOURCES "")

# Editor source files
add_subdirectory(editor/src src-editor)
get_property(EDITOR_SOURCE_FILES TARGET editor PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/editor/src PREFIX editor/src FILES ${EDITOR_SOURCE_FILES})
set_property(TARGET editor PROPERTY SOURCES "")

# Target all files
set_property(TARGET editor PROPERTY SOURCES "${SHARED_INCLUDE_FILES};${SHARED_SOURCE_FILES};${EDITOR_INCLUDE_FILES};${EDITOR_SOURCE_FILES}")

# Target include directories
target_include_directories(editor PUBLIC shared/include)
target_include_directories(editor PUBLIC editor/include)
target_include_directories(editor PUBLIC dependencies/cista/include)

# Set compile definitions
target_compile_definitions(editor PUBLIC
	WIN32_LEAN_AND_MEAN
	NOGDI
)

# Target libraries for linking
target_link_libraries(editor
	CONAN_PKG::glm
	CONAN_PKG::rapidxml
	CONAN_PKG::sfml
)

# Copy files from "./editor/resources" to binary output directories
foreach(CMAKE_CONFIGURATION_TYPE ${CMAKE_CONFIGURATION_TYPES})
	add_custom_command(
		TARGET editor POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
			${CMAKE_CURRENT_SOURCE_DIR}/editor/resources/
			${PROJECT_BINARY_DIR}/${CMAKE_CONFIGURATION_TYPE})
endforeach()

# Output name
set_property(TARGET editor PROPERTY OUTPUT_NAME NoLifeNoCryEditor)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT editor)

unset(PROJECT)

########################
#                      #
# Editor project (end) #
#                      #
########################
