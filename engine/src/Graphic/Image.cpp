#include <Graphic/Image.hpp>

/// @brief Default constructor
DirtMachine::Graphic::Image::Image() :
	sf::Image()
{
	// TODO
}

/// @brief Destructor
DirtMachine::Graphic::Image::~Image()
{
	// TODO
}

/// @brief Create image
/// @param width Image width
/// @param height Image height
/// @param color Image color
void DirtMachine::Graphic::Image::Create(unsigned int width, unsigned int height, const DirtMachine::Graphic::Colour& colour)
{
	create(width, height, colour);
}

/// @brief Create image
/// @param width Imafe width
/// @param height Image height
/// @param pixels Pixel data
void DirtMachine::Graphic::Image::Create(unsigned int width, unsigned int height, const std::uint8_t* pixels)
{
	create(width, height, pixels);
}

/// @brief Load from file
/// @param path Image path
/// @return "true" if image was successfully loaded from the specified path, otherwise "false"
bool DirtMachine::Graphic::Image::LoadFromFile(const std::string& path)
{
	return loadFromFile(path);
}

/// @brief Save image to file
/// @param path Image path
/// @return "true" if image was successfully save to the specified path, otherwise "false"
bool DirtMachine::Graphic::Image::SaveToFile(const std::string& path) const
{
	return saveToFile(path);
}

/// @brief Get image size
/// @return Image size
glm::uvec2 DirtMachine::Graphic::Image::GetSize() const
{
	sf::Vector2u size(getSize());
	return glm::uvec2{ size.x, size.y };
}

/// @brief Create image mask from colour
/// @param colour Colour
/// @param alpha Alpha
void DirtMachine::Graphic::Image::CreateMaskFromColor(const DirtMachine::Graphic::Colour& colour, std::uint8_t alpha)
{
	createMaskFromColor(colour, alpha);
}

/// @brief Copy image
/// @param source Source image
/// @param destX Destination X
/// @param destY Destination Y
/// @param sourceRect Source rectangle
/// @param applyAlpha Apply alpha
void DirtMachine::Graphic::Image::Copy(const DirtMachine::Graphic::Image& source, unsigned int destX, unsigned int destY, const DirtMachine::Graphic::Rectangle<int>& sourceRect, bool applyAlpha)
{
	copy(source, destX, destY, sourceRect, applyAlpha);
}

/// @brief Set pixel colour
/// @param x X
/// @param y Y
/// @param color Color
void DirtMachine::Graphic::Image::SetPixel(unsigned int x, unsigned int y, const DirtMachine::Graphic::Colour& colour)
{
	setPixel(x, y, colour);
}

/// @brief Get pixel color
/// @param x X
/// @param y Y
/// @return Pixel color
DirtMachine::Graphic::Colour DirtMachine::Graphic::Image::GetPixel(unsigned int x, unsigned int y) const
{
	return getPixel(x, y);
}

/// @brief Get pointer to pixel data
/// @return Pointer to pixel data
const std::uint8_t* DirtMachine::Graphic::Image::GetPixelsPointer() const
{
	return getPixelsPtr();
}

/// @brief Flip horizontally
void DirtMachine::Graphic::Image::FlipHorizontally()
{
	flipHorizontally();
}

/// @brief Flip vertically
void DirtMachine::Graphic::Image::FlipVertically()
{
	flipVertically();
}
