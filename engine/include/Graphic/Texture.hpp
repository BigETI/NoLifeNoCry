#pragma once

#include <glm/vec2.hpp>
#include <cstdint>
#include <SFML/Graphics/Texture.hpp>

#include "ECoordinateSpace.hpp"
#include "Image.hpp"

/// @brief Dirt Machine game engine graphic namespace
namespace DirtMachine::Graphic
{
	/// @brief Texture class
	class Texture : sf::Texture
    {
    public:
        /// @brief Default constructor
        Texture();

        /// @brief Copy constructor
        /// @param texture Texture
        Texture(const Texture& texture);

        /// @brief Destructor
        ~Texture();

        /// @brief Bind texture
        /// @param texture Texture
        /// @param coordinateSpace Coordinate space
        static void Bind(const DirtMachine::Graphic::Texture* texture, DirtMachine::Graphic::ECoordinateSpace coordinateSpace = DirtMachine::Graphic::ECoordinateSpace::Normalized);

        /// @brief Get maximal texture size
        /// @return Maximal texture size
        static unsigned int GetMaximalSize();

        /// @brief Create texture
        /// @param width Width
        /// @param height Height
        /// @return "true" if texture was successfully created, otherwise "false"
        bool Create(unsigned int width, unsigned int height);

        /// @brief Load texture from file
        /// @param path Texture path
        /// @param area Texture area
        /// @return "true" if texture was successfully loaded from the specified path, otherwise "false"
        bool LoadFromFile(const std::string& path, const DirtMachine::Graphic::Rectangle<int>& area = DirtMachine::Graphic::Rectangle<int>());

        /// @brief Load texture from memory
        /// @param memory Texture from memory
        /// @param area Texture area
        /// @return "true" if texture was successfully loaded from memory, otherwise "false"
        template <std::size_t Extent>
        bool LoadFromMemory(const std::span<std::uint8_t, Extent> memory, const DirtMachine::Graphic::Rectangle<int>& area = DirtMachine::Rectangle<int>())
        {
            return loadFromMemory(memory.data(), memory.size(), area);
        }

        /// @brief Load texture from image
        /// @param image Image
        /// @param area Texture area
        /// @return "true" if texture was successfully loaded from image, otherwise "false"
        bool LoadFromImage(const DirtMachine::Graphic::Image& image, const DirtMachine::Graphic::Rectangle<int>& area = DirtMachine::Graphic::Rectangle<int>());

        /// @brief Get texture size
        /// @return Texture size
        glm::uvec2 GetSize() const;

        /// @brief Update with pixel data
        /// @param pixels Pixel data
        void Update(const std::uint8_t* pixels);

        /// @brief Update with pixel data
        /// @param pixels Pixel data
        /// @param width Width
        /// @param height Height
        /// @param x X
        /// @param y Y
        void Update(const std::uint8_t* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y);

        /// @brief Update with texture
        /// @param texture Texture
        void Update(const DirtMachine::Graphic::Texture& texture);

        /// @brief Update with texture
        /// @param texture Texture
        /// @param x X
        /// @param y Y
        void Update(const DirtMachine::Graphic::Texture& texture, unsigned int x, unsigned int y);

        /// @brief Update with image
        /// @param image Image
        void Update(const DirtMachine::Graphic::Image& image);

        /// @brief Update with image
        /// @param image Image
        /// @param x X
        /// @param y Y
        void Update(const DirtMachine::Graphic::Image& image, unsigned int x, unsigned int y);

        /// @brief Set texture to smooth
        /// @param isSmooth Set texture to smooth
        void SetSmooth(bool isSmooth);

        /// @brief Is texture set to smooth
        /// @return "true" if texture is set to smooth, otherwise "false"
        bool IsSmooth() const;

        /// @brief Set texture to SRGB
        /// @param isSRGB Set to SRGB
        void SetSRGB(bool isSRGB);

        /// @brief Is texture set to SRGB
        /// @return "true" if texture is set to smooth, otherwise "false"
        bool IsSRGB() const;

        /// @brief Set texture to repeat
        /// @param repeated Set texture to repeat
        void SetRepeated(bool repeated);

        /// @brief Is texture repeating
        /// @return "true" if texture is set to repeating, otherwise "false"
        bool IsRepeated() const;

        /// @brief Generate mipmaps
        /// @return "true" if mipmaps were generated successfully, otherwise "false"
        bool GenerateMipmap();

        /// @brief Swap textures
        /// @param texture Texture
        void Swap(Texture& texture);

        /// @brief Get native handle
        /// @return Native handle
        unsigned int GetNativeHandle() const;

        /// @brief Assign operator
        /// @param texture Texture
        /// @return Itself
        DirtMachine::Graphic::Texture& operator =(const DirtMachine::Graphic::Texture& texture);
	};
}
