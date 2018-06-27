#pragma once
#include "Texture.h"
#include "DynamicArray.h"

enum eTextures
{
	ETEXTURES_TANK = 0,
	ETEXTURES_TURRET,
	ETEXTURES_BARREL,
	ETEXTURES_BULLET,

	ETEXTURES_TOTAL
};

class TextureManager
{
public:
	static void Create();
	static void Destroy();
	static TextureManager* GetInstance();

	aie::Texture* GetTexture(eTextures texture);

private:
	TextureManager();
	~TextureManager();

	static TextureManager* m_pInstance;

	DynamicArray<aie::Texture*> m_pTextures;
};

