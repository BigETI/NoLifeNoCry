#include "Image.hpp"

/// @brief Default constructor
NoLifeNoCry::Engine::Image::Image()
{
	// TODO
}

/// @brief Destructor
NoLifeNoCry::Engine::Image::~Image()
{
	// TODO
}

/// @brief Create image
/// @param width Image width
/// @param height Image height
/// @param color Image color
void NoLifeNoCry::Engine::Image::Create(unsigned int width, unsigned int height, const NoLifeNoCry::Engine::Color& color)
{
	create(width, height, color);
}

/// @brief Create image
/// @param width Imafe width
/// @param height Image height
/// @param pixels Pixel data
void NoLifeNoCry::Engine::Image::Create(unsigned int width, unsigned int height, const std::uint8_t* pixels)
{
	create(width, height, pixels);
}

/// @brief Load from file
/// @param path Image path
/// @return "true" if image was successfully loaded from the specified path, otherwise "false"
bool NoLifeNoCry::Engine::Image::LoadFromFile(const std::string& path)
{
	return loadFromFile(path);
}

/// @brief Save image to file
/// @param path Image path
/// @return "true" if image was successfully save to the specified path, otherwise "false"
bool NoLifeNoCry::Engine::Image::SaveToFile(const std::string& path) const
{
	return saveToFile(path);
}

/// @brief Get image size
/// @return Image size
glm::uvec2 NoLifeNoCry::Engine::Image::GetSize() const
{
	sf::Vector2u size(getSize());
	return glm::uvec2{ size.x, size.y };
}

/// @brief Create image mask from color
/// @param color Color
/// @param alpha Alpha
void NoLifeNoCry::Engine::Image::CreateMaskFromColor(const NoLifeNoCry::Engine::Color& color, std::uint8_t alpha)
{
	createMaskFromColor(color, alpha);
}

/// @brief Copy image
/// @param source Source image
/// @param destX Destination X
/// @param destY Destination Y
/// @param sourceRect Source rectangle
/// @param applyAlpha Apply alpha
void NoLifeNoCry::Engine::Image::Copy(const NoLifeNoCry::Engine::Image& source, unsigned int destX, unsigned int destY, const NoLifeNoCry::Engine::Rectangle<int>& sourceRect, bool applyAlpha)
{
	copy(source, destX, destY, sourceRect, applyAlpha);
}

/// @brief Set pixel color
/// @param x X
/// @param y Y
/// @param color Color
void NoLifeNoCry::Engine::Image::SetPixel(unsigned int x, unsigned int y, const NoLifeNoCry::Engine::Color& color)
{
	setPixel(x, y, color);
}

/// @brief Get pixel color
/// @param x X
/// @param y Y
/// @return Pixel color
NoLifeNoCry::Engine::Color NoLifeNoCry::Engine::Image::GetPixel(unsigned int x, unsigned int y) const
{
	return getPixel(x, y);
}

/// @brief Get pointer to pixel data
/// @return Pointer to pixel data
const std::uint8_t* NoLifeNoCry::Engine::Image::GetPixelsPointer() const
{
	return getPixelsPtr();
}

/// @brief Flip horizontally
void NoLifeNoCry::Engine::Image::FlipHorizontally()
{
	flipHorizontally();
}

/// @brief Flip vertically
void NoLifeNoCry::Engine::Image::FlipVertically()
{
	flipVertically();
}
