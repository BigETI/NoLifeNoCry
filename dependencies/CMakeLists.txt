include(cmake-conan/conan.cmake)

# Automatically download and set up paths to a library on Conan
# Works for multi-configuration
function(add_conan_lib pkg_name conan_pkg)
	conan_check(REQUIRED)

	conan_cmake_run(
		REQUIRES ${conan_pkg}
		ARCH ${CROSS_BUILD_ARCH}
		BASIC_SETUP CMAKE_TARGETS
		BUILD missing
	)

	set_target_properties(${pkg_name} PROPERTIES IMPORTED_GLOBAL TRUE)
endfunction()

# Cista++ Git submodule from https://github.com/felixguendling/cista
#add_subdirectory(cista)

# GLM from conan-center
add_conan_lib(CONAN_PKG::glm glm/0.9.9.8)

# GoogleTest from conan-center
add_conan_lib(CONAN_PKG::gtest gtest/1.10.0)

# RapidXml from conan-center
add_conan_lib(CONAN_PKG::rapidxml rapidxml/1.13)

# Run Time Type Reflection library from conan-center
add_conan_lib(CONAN_PKG::rttr rttr/0.9.6)

# SFML from bincrafters in bintray
add_conan_lib(CONAN_PKG::sfml sfml/2.5.1@bincrafters/stable)
