#ifndef textureHolder_hpp
#define textureHolder_hpp
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;

class TextureHolder {

public:
	TextureHolder();
	static Texture& GetTexture(std::string const& filename);

private:
	// A map holding pairs of String and Texture
	std::map<std::string, Texture> m_Textures;

	// Pointer to the singleton
	static TextureHolder* m_s_Instance;
};


#endif /* textureHolder_hpp */


