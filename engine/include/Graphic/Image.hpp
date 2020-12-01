#pragma once

#include <cstdint>
#include <span>
#include <glm/vec2.hpp>
#include <SFML/Graphics/Image.hpp>

#include <Graphic/Colour.hpp>
#include <Graphic/Rectangle.hpp>

/// @brief Dirt Machine game engine graphic namespace
namespace DirtMachine::Graphic
{
	/// @brief Image class
	class Image : public sf::Image
	{
    public:
        /// @brief Default constructor
        Image();

        /// @brief Destructor
        ~Image();

        /// @brief Create image
        /// @param width Image width
        /// @param height Image height
        /// @param colour Image colour
        void Create(unsigned int width, unsigned int height, const DirtMachine::Graphic::Colour& colour = DirtMachine::Graphic::Colour(0, 0, 0));

        /// @brief Create image
        /// @param width Imafe width
        /// @param height Image height
        /// @param pixels Pixel data
        void Create(unsigned int width, unsigned int height, const std::uint8_t* pixels);
        
        /// @brief Load from file
        /// @param path Image path
        /// @return "true" if image was successfully loaded from the specified path, otherwise "false"
        bool LoadFromFile(const std::string& path);

        /// @brief Load from memory
        /// @tparam Extent Number of bytes
        /// @param memory Image from memory
        /// @return "true" if image was successfully loaded from memory, otherwise "false" 
        template <std::size_t Extent>
        bool LoadFromMemory(std::span<std::uint8_t, Extent> memory)
        {
            loadFromMemory(memory.data(), memory.size());
        }

        /// @brief Save image to file
        /// @param path Image path
        /// @return "true" if image was successfully save to the specified path, otherwise "false"
        bool SaveToFile(const std::string& path) const;

        /// @brief Get image size
        /// @return Image size
        glm::uvec2 GetSize() const;

        /// @brief Create image mask from colour
        /// @param colour Colour
        /// @param alpha Alpha
        void CreateMaskFromColor(const DirtMachine::Graphic::Colour& colour, std::uint8_t alpha = 0);

        /// @brief Copy image
        /// @param source Source image
        /// @param destX Destination X
        /// @param destY Destination Y
        /// @param sourceRect Source rectangle
        /// @param applyAlpha Apply alpha
        void Copy(const DirtMachine::Graphic::Image& source, unsigned int destX, unsigned int destY, const DirtMachine::Graphic::Rectangle<int>& sourceRect = DirtMachine::Graphic::Rectangle<int>(0, 0, 0, 0), bool applyAlpha = false);

        /// @brief Set pixel colour
        /// @param x X
        /// @param y Y
        /// @param colour Colour
        void SetPixel(unsigned int x, unsigned int y, const DirtMachine::Graphic::Colour& colour);

        /// @brief Get pixel colour
        /// @param x X
        /// @param y Y
        /// @return Pixel colour
        DirtMachine::Graphic::Colour GetPixel(unsigned int x, unsigned int y) const;
        
        /// @brief Get pointer to pixel data
        /// @return Pointer to pixel data
        const std::uint8_t* GetPixelsPointer() const;

        /// @brief Flip horizontally
        void FlipHorizontally();

        /// @brief Flip vertically
        void FlipVertically();
	};
}
