#include <Graphic/Texture.hpp>

/// @brief Default constructor
DirtMachine::Graphic::Texture::Texture()
{
	// ...
}

/// @brief Copy constructor
/// @param texture Texture
DirtMachine::Graphic::Texture::Texture(const DirtMachine::Graphic::Texture& texture) : sf::Texture(texture)
{
	// ...
}

/// @brief Destructor
DirtMachine::Graphic::Texture::~Texture()
{
	// ...
}

/// @brief Bind texture
/// @param texture Texture
/// @param coordinateSpace Coordinate space
void DirtMachine::Graphic::Texture::Bind(const DirtMachine::Graphic::Texture* texture, DirtMachine::Graphic::ECoordinateSpace coordinateSpace)
{
	sf::Texture::bind(texture, static_cast<sf::Texture::CoordinateType>(coordinateSpace));
}

/// @brief Get maximal texture size
/// @return Maximal texture size
unsigned int DirtMachine::Graphic::Texture::GetMaximalSize()
{
	return sf::Texture::getMaximumSize();
}

/// @brief Create texture
/// @param width Width
/// @param height Height
/// @return "true" if texture was successfully created, otherwise "false"
bool DirtMachine::Graphic::Texture::Create(unsigned int width, unsigned int height)
{
	return create(width, height);
}

/// @brief Load texture from file
/// @param path Texture path
/// @param area Texture area
/// @return "true" if texture was successfully loaded from the specified path, otherwise "false"
bool DirtMachine::Graphic::Texture::LoadFromFile(const std::string& path, const DirtMachine::Graphic::Rectangle<int>& area)
{
	return loadFromFile(path, area);
}

/// @brief Load texture from image
/// @param image Image
/// @param area Texture area
/// @return "true" if texture was successfully loaded from image, otherwise "false"
bool DirtMachine::Graphic::Texture::LoadFromImage(const DirtMachine::Graphic::Image& image, const DirtMachine::Graphic::Rectangle<int>& area)
{
	return loadFromImage(image, area);
}

/// @brief Get texture size
/// @return Texture size
glm::uvec2 DirtMachine::Graphic::Texture::GetSize() const
{
	sf::Vector2u size(getSize());
	return glm::uvec2{ size.x, size.y };
}

/// @brief Update with pixel data
/// @param pixels Pixel data
void DirtMachine::Graphic::Texture::Update(const std::uint8_t* pixels)
{
	update(pixels);
}

/// @brief Update with pixel data
/// @param pixels Pixel data
/// @param width Width
/// @param height Height
/// @param x X
/// @param y Y
void DirtMachine::Graphic::Texture::Update(const std::uint8_t* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y)
{
	update(pixels, width, height, x, y);
}

/// @brief Update with texture
/// @param texture Texture
void DirtMachine::Graphic::Texture::Update(const DirtMachine::Graphic::Texture& texture)
{
	update(texture);
}

/// @brief Update with texture
/// @param texture Texture
/// @param x X
/// @param y Y
void DirtMachine::Graphic::Texture::Update(const DirtMachine::Graphic::Texture& texture, unsigned int x, unsigned int y)
{
	update(texture, x, y);
}

/// @brief Update with image
/// @param image Image
void DirtMachine::Graphic::Texture::Update(const DirtMachine::Graphic::Image& image)
{
	update(image);
}

/// @brief Update with image
/// @param image Image
/// @param x X
/// @param y Y
void DirtMachine::Graphic::Texture::Update(const DirtMachine::Graphic::Image& image, unsigned int x, unsigned int y)
{
	update(image, x, y);
}

/// @brief Set texture smooth
/// @param isSmooth Is texture smooth
void DirtMachine::Graphic::Texture::SetSmooth(bool isSmooth)
{
	setSmooth(isSmooth);
}

/// @brief Is texture set to smooth
/// @return "true" if texture is set to smooth, otherwise "false"
bool DirtMachine::Graphic::Texture::IsSmooth() const
{
	return isSmooth();
}

/// @brief Set texture to SRGB
/// @param isSRGB Set to SRGB
void DirtMachine::Graphic::Texture::SetSRGB(bool isSRGB)
{
	setSrgb(isSRGB);
}

/// @brief Is texture set to SRGB
/// @return "true" if texture is set to smooth, otherwise "false"
bool DirtMachine::Graphic::Texture::IsSRGB() const
{
	return isSrgb();
}

/// @brief Set texture to repeat
/// @param repeated Set texture to repeat
void DirtMachine::Graphic::Texture::SetRepeated(bool repeated)
{
	setRepeated(true);
}

/// @brief Is texture repeating
/// @return "true" if texture is set to repeating, otherwise "false"
bool DirtMachine::Graphic::Texture::IsRepeated() const
{
	return isRepeated();
}

/// @brief Generate mipmaps
/// @return "true" if mipmaps were generated successfully, otherwise "false"
bool DirtMachine::Graphic::Texture::GenerateMipmap()
{
	return generateMipmap();
}

/// @brief Swap textures
/// @param texture Texture
void DirtMachine::Graphic::Texture::Swap(DirtMachine::Graphic::Texture& texture)
{
	swap(texture);
}

/// @brief Get native handle
/// @return Native handle
unsigned int DirtMachine::Graphic::Texture::GetNativeHandle() const
{
	return getNativeHandle();
}

/// @brief Assign operator
/// @param texture Texture
/// @return Itself
DirtMachine::Graphic::Texture& DirtMachine::Graphic::Texture::operator =(const DirtMachine::Graphic::Texture& texture)
{
	*reinterpret_cast<sf::Texture*>(this) = texture;
	return *this;
}
