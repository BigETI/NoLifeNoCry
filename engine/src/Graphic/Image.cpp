#include <Graphic/Image.hpp>

/// @brief Default constructor
NoLifeNoCry::Engine::Graphic::Image::Image() : sf::Image()
{
	// TODO
}

/// @brief Destructor
NoLifeNoCry::Engine::Graphic::Image::~Image()
{
	// TODO
}

/// @brief Create image
/// @param width Image width
/// @param height Image height
/// @param color Image color
void NoLifeNoCry::Engine::Graphic::Image::Create(unsigned int width, unsigned int height, const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	create(width, height, colour);
}

/// @brief Create image
/// @param width Imafe width
/// @param height Image height
/// @param pixels Pixel data
void NoLifeNoCry::Engine::Graphic::Image::Create(unsigned int width, unsigned int height, const std::uint8_t* pixels)
{
	create(width, height, pixels);
}

/// @brief Load from file
/// @param path Image path
/// @return "true" if image was successfully loaded from the specified path, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Image::LoadFromFile(const std::string& path)
{
	return loadFromFile(path);
}

/// @brief Save image to file
/// @param path Image path
/// @return "true" if image was successfully save to the specified path, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Image::SaveToFile(const std::string& path) const
{
	return saveToFile(path);
}

/// @brief Get image size
/// @return Image size
glm::uvec2 NoLifeNoCry::Engine::Graphic::Image::GetSize() const
{
	sf::Vector2u size(getSize());
	return glm::uvec2{ size.x, size.y };
}

/// @brief Create image mask from colour
/// @param colour Colour
/// @param alpha Alpha
void NoLifeNoCry::Engine::Graphic::Image::CreateMaskFromColor(const NoLifeNoCry::Engine::Graphic::Colour& colour, std::uint8_t alpha)
{
	createMaskFromColor(colour, alpha);
}

/// @brief Copy image
/// @param source Source image
/// @param destX Destination X
/// @param destY Destination Y
/// @param sourceRect Source rectangle
/// @param applyAlpha Apply alpha
void NoLifeNoCry::Engine::Graphic::Image::Copy(const NoLifeNoCry::Engine::Graphic::Image& source, unsigned int destX, unsigned int destY, const NoLifeNoCry::Engine::Graphic::Rectangle<int>& sourceRect, bool applyAlpha)
{
	copy(source, destX, destY, sourceRect, applyAlpha);
}

/// @brief Set pixel colour
/// @param x X
/// @param y Y
/// @param color Color
void NoLifeNoCry::Engine::Graphic::Image::SetPixel(unsigned int x, unsigned int y, const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	setPixel(x, y, colour);
}

/// @brief Get pixel color
/// @param x X
/// @param y Y
/// @return Pixel color
NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::Graphic::Image::GetPixel(unsigned int x, unsigned int y) const
{
	return getPixel(x, y);
}

/// @brief Get pointer to pixel data
/// @return Pointer to pixel data
const std::uint8_t* NoLifeNoCry::Engine::Graphic::Image::GetPixelsPointer() const
{
	return getPixelsPtr();
}

/// @brief Flip horizontally
void NoLifeNoCry::Engine::Graphic::Image::FlipHorizontally()
{
	flipHorizontally();
}

/// @brief Flip vertically
void NoLifeNoCry::Engine::Graphic::Image::FlipVertically()
{
	flipVertically();
}
