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

# RapidXml from conan-center
add_conan_lib(CONAN_PKG::rapidxml rapidxml/1.13)

# SFML from bintray/bincrafters
add_conan_lib(CONAN_PKG::sfml sfml/2.5.1@bincrafters/stable)
