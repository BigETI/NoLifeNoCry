#include "Texture.hpp"

/// @brief Default constructor
NoLifeNoCry::Engine::Texture::Texture()
{
	// ...
}

/// @brief Copy constructor
/// @param texture Texture
NoLifeNoCry::Engine::Texture::Texture(const Texture& texture) : sf::Texture(texture)
{
	// ...
}

/// @brief Destructor
NoLifeNoCry::Engine::Texture::~Texture()
{
	// ...
}

/// @brief Bind texture
/// @param texture Texture
/// @param coordinateSpace Coordinate space
void NoLifeNoCry::Engine::Texture::Bind(const Texture* texture, NoLifeNoCry::Engine::ECoordinateSpace coordinateSpace)
{
	sf::Texture::bind(texture, static_cast<sf::Texture::CoordinateType>(coordinateSpace));
}

/// @brief Get maximal texture size
/// @return Maximal texture size
unsigned int NoLifeNoCry::Engine::Texture::GetMaximalSize()
{
	return sf::Texture::getMaximumSize();
}

/// @brief Create texture
/// @param width Width
/// @param height Height
/// @return "true" if texture was successfully created, otherwise "false"
bool NoLifeNoCry::Engine::Texture::Create(unsigned int width, unsigned int height)
{
	return create(width, height);
}

/// @brief Load texture from file
/// @param path Texture path
/// @param area Texture area
/// @return "true" if texture was successfully loaded from the specified path, otherwise "false"
bool NoLifeNoCry::Engine::Texture::LoadFromFile(const std::string& path, const NoLifeNoCry::Engine::Rectangle<int>& area)
{
	return loadFromFile(path, area);
}

/// @brief Load texture from image
/// @param image Image
/// @param area Texture area
/// @return "true" if texture was successfully loaded from image, otherwise "false"
bool NoLifeNoCry::Engine::Texture::LoadFromImage(const NoLifeNoCry::Engine::Image& image, const NoLifeNoCry::Engine::Rectangle<int>& area)
{
	return loadFromImage(image, area);
}

/// @brief Get texture size
/// @return Texture size
glm::uvec2 NoLifeNoCry::Engine::Texture::GetSize() const
{
	sf::Vector2u size(getSize());
	return glm::uvec2{ size.x, size.y };
}

/// @brief Update with pixel data
/// @param pixels Pixel data
void NoLifeNoCry::Engine::Texture::Update(const std::uint8_t* pixels)
{
	update(pixels);
}

/// @brief Update with pixel data
/// @param pixels Pixel data
/// @param width Width
/// @param height Height
/// @param x X
/// @param y Y
void NoLifeNoCry::Engine::Texture::Update(const std::uint8_t* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y)
{
	update(pixels, width, height, x, y);
}

/// @brief Update with texture
/// @param texture Texture
void NoLifeNoCry::Engine::Texture::Update(const NoLifeNoCry::Engine::Texture& texture)
{
	update(texture);
}

/// @brief Update with texture
/// @param texture Texture
/// @param x X
/// @param y Y
void NoLifeNoCry::Engine::Texture::Update(const NoLifeNoCry::Engine::Texture& texture, unsigned int x, unsigned int y)
{
	update(texture, x, y);
}

/// @brief Update with image
/// @param image Image
void NoLifeNoCry::Engine::Texture::Update(const NoLifeNoCry::Engine::Image& image)
{
	update(image);
}

/// @brief Update with image
/// @param image Image
/// @param x X
/// @param y Y
void NoLifeNoCry::Engine::Texture::Update(const NoLifeNoCry::Engine::Image& image, unsigned int x, unsigned int y)
{
	update(image, x, y);
}

/// @brief Set texture smooth
/// @param isSmooth Is texture smooth
void NoLifeNoCry::Engine::Texture::SetSmooth(bool isSmooth)
{
	setSmooth(isSmooth);
}

/// @brief Is texture set to smooth
/// @return "true" if texture is set to smooth, otherwise "false"
bool NoLifeNoCry::Engine::Texture::IsSmooth() const
{
	return isSmooth();
}

/// @brief Set texture to SRGB
/// @param isSRGB Set to SRGB
void NoLifeNoCry::Engine::Texture::SetSRGB(bool isSRGB)
{
	setSrgb(isSRGB);
}

/// @brief Is texture set to SRGB
/// @return "true" if texture is set to smooth, otherwise "false"
bool NoLifeNoCry::Engine::Texture::IsSRGB() const
{
	return isSrgb();
}

/// @brief Set texture to repeat
/// @param repeated Set texture to repeat
void NoLifeNoCry::Engine::Texture::SetRepeated(bool repeated)
{
	setRepeated(true);
}

/// @brief Is texture repeating
/// @return "true" if texture is set to repeating, otherwise "false"
bool NoLifeNoCry::Engine::Texture::IsRepeated() const
{
	return isRepeated();
}

/// @brief Generate mipmaps
/// @return "true" if mipmaps were generated successfully, otherwise "false"
bool NoLifeNoCry::Engine::Texture::GenerateMipmap()
{
	return generateMipmap();
}

/// @brief Swap textures
/// @param texture Texture
void NoLifeNoCry::Engine::Texture::Swap(Texture& texture)
{
	swap(texture);
}

/// @brief Get native handle
/// @return Native handle
unsigned int NoLifeNoCry::Engine::Texture::GetNativeHandle() const
{
	return getNativeHandle();
}

/// @brief Assign operator
/// @param texture Texture
/// @return Itself
NoLifeNoCry::Engine::Texture& NoLifeNoCry::Engine::Texture::operator =(const NoLifeNoCry::Engine::Texture& texture)
{
	*reinterpret_cast<sf::Texture*>(this) = texture;
	return *this;
}
