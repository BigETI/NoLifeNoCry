#include <Graphic/Texture.hpp>

/// @brief Default constructor
NoLifeNoCry::Engine::Graphic::Texture::Texture()
{
	// ...
}

/// @brief Copy constructor
/// @param texture Texture
NoLifeNoCry::Engine::Graphic::Texture::Texture(const NoLifeNoCry::Engine::Graphic::Texture& texture) : sf::Texture(texture)
{
	// ...
}

/// @brief Destructor
NoLifeNoCry::Engine::Graphic::Texture::~Texture()
{
	// ...
}

/// @brief Bind texture
/// @param texture Texture
/// @param coordinateSpace Coordinate space
void NoLifeNoCry::Engine::Graphic::Texture::Bind(const NoLifeNoCry::Engine::Graphic::Texture* texture, NoLifeNoCry::Engine::Graphic::ECoordinateSpace coordinateSpace)
{
	sf::Texture::bind(texture, static_cast<sf::Texture::CoordinateType>(coordinateSpace));
}

/// @brief Get maximal texture size
/// @return Maximal texture size
unsigned int NoLifeNoCry::Engine::Graphic::Texture::GetMaximalSize()
{
	return sf::Texture::getMaximumSize();
}

/// @brief Create texture
/// @param width Width
/// @param height Height
/// @return "true" if texture was successfully created, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Texture::Create(unsigned int width, unsigned int height)
{
	return create(width, height);
}

/// @brief Load texture from file
/// @param path Texture path
/// @param area Texture area
/// @return "true" if texture was successfully loaded from the specified path, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Texture::LoadFromFile(const std::string& path, const NoLifeNoCry::Engine::Graphic::Rectangle<int>& area)
{
	return loadFromFile(path, area);
}

/// @brief Load texture from image
/// @param image Image
/// @param area Texture area
/// @return "true" if texture was successfully loaded from image, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Texture::LoadFromImage(const NoLifeNoCry::Engine::Graphic::Image& image, const NoLifeNoCry::Engine::Graphic::Rectangle<int>& area)
{
	return loadFromImage(image, area);
}

/// @brief Get texture size
/// @return Texture size
glm::uvec2 NoLifeNoCry::Engine::Graphic::Texture::GetSize() const
{
	sf::Vector2u size(getSize());
	return glm::uvec2{ size.x, size.y };
}

/// @brief Update with pixel data
/// @param pixels Pixel data
void NoLifeNoCry::Engine::Graphic::Texture::Update(const std::uint8_t* pixels)
{
	update(pixels);
}

/// @brief Update with pixel data
/// @param pixels Pixel data
/// @param width Width
/// @param height Height
/// @param x X
/// @param y Y
void NoLifeNoCry::Engine::Graphic::Texture::Update(const std::uint8_t* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y)
{
	update(pixels, width, height, x, y);
}

/// @brief Update with texture
/// @param texture Texture
void NoLifeNoCry::Engine::Graphic::Texture::Update(const NoLifeNoCry::Engine::Graphic::Texture& texture)
{
	update(texture);
}

/// @brief Update with texture
/// @param texture Texture
/// @param x X
/// @param y Y
void NoLifeNoCry::Engine::Graphic::Texture::Update(const NoLifeNoCry::Engine::Graphic::Texture& texture, unsigned int x, unsigned int y)
{
	update(texture, x, y);
}

/// @brief Update with image
/// @param image Image
void NoLifeNoCry::Engine::Graphic::Texture::Update(const NoLifeNoCry::Engine::Graphic::Image& image)
{
	update(image);
}

/// @brief Update with image
/// @param image Image
/// @param x X
/// @param y Y
void NoLifeNoCry::Engine::Graphic::Texture::Update(const NoLifeNoCry::Engine::Graphic::Image& image, unsigned int x, unsigned int y)
{
	update(image, x, y);
}

/// @brief Set texture smooth
/// @param isSmooth Is texture smooth
void NoLifeNoCry::Engine::Graphic::Texture::SetSmooth(bool isSmooth)
{
	setSmooth(isSmooth);
}

/// @brief Is texture set to smooth
/// @return "true" if texture is set to smooth, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Texture::IsSmooth() const
{
	return isSmooth();
}

/// @brief Set texture to SRGB
/// @param isSRGB Set to SRGB
void NoLifeNoCry::Engine::Graphic::Texture::SetSRGB(bool isSRGB)
{
	setSrgb(isSRGB);
}

/// @brief Is texture set to SRGB
/// @return "true" if texture is set to smooth, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Texture::IsSRGB() const
{
	return isSrgb();
}

/// @brief Set texture to repeat
/// @param repeated Set texture to repeat
void NoLifeNoCry::Engine::Graphic::Texture::SetRepeated(bool repeated)
{
	setRepeated(true);
}

/// @brief Is texture repeating
/// @return "true" if texture is set to repeating, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Texture::IsRepeated() const
{
	return isRepeated();
}

/// @brief Generate mipmaps
/// @return "true" if mipmaps were generated successfully, otherwise "false"
bool NoLifeNoCry::Engine::Graphic::Texture::GenerateMipmap()
{
	return generateMipmap();
}

/// @brief Swap textures
/// @param texture Texture
void NoLifeNoCry::Engine::Graphic::Texture::Swap(NoLifeNoCry::Engine::Graphic::Texture& texture)
{
	swap(texture);
}

/// @brief Get native handle
/// @return Native handle
unsigned int NoLifeNoCry::Engine::Graphic::Texture::GetNativeHandle() const
{
	return getNativeHandle();
}

/// @brief Assign operator
/// @param texture Texture
/// @return Itself
NoLifeNoCry::Engine::Graphic::Texture& NoLifeNoCry::Engine::Graphic::Texture::operator =(const NoLifeNoCry::Engine::Graphic::Texture& texture)
{
	*reinterpret_cast<sf::Texture*>(this) = texture;
	return *this;
}
