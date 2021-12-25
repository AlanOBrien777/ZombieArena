#include "../includes/textureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder() {
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(string const& filename) {
	// Get a reference to m_Textures using m_s_Instance
	// m_Textures is a map holding pairs of Strings and Textures
	auto& m = m_s_Instance->m_Textures;

	// Search the map 'm' for the passed in filename
	auto keyValuePair = m.find(filename);
	
	if (keyValuePair != m.end()) {
		// if found return the texture
		return keyValuePair->second;
	}

	else {
		// Create a new key value pair using the filename
		auto& texture = m[filename];

		// Load the texture from file into map beside its filename
		texture.loadFromFile(filename);
		return texture;
	}
}

