#include "TextureManager.h"
#include <assert.h>

TextureManager* TextureManager::m_pInstance = nullptr;

TextureManager::TextureManager()
{
	for (int i = 0; i < ETEXTURES_TOTAL; ++i)
	{
		switch (i)
		{
		case ETEXTURES_TANK:
			m_pTextures.PushBack(new aie::Texture("./textures/tankBeige.png"));
			break;
		case ETEXTURES_TURRET:
			m_pTextures.PushBack(new aie::Texture("./textures/ball.png"));
			break;
		case ETEXTURES_BARREL:
			m_pTextures.PushBack(new aie::Texture("./textures/barrelBeige.png"));
			break;
		case ETEXTURES_BULLET:
			m_pTextures.PushBack(new aie::Texture("./textures/bullet.png"));
			break;
		default:
			assert(!"Invalid Texture");
		}
	}
}

TextureManager::~TextureManager()
{
	for (int i = 0; i < ETEXTURES_TOTAL; ++i)
	{
		delete m_pTextures[i];
	}
}

void TextureManager::Create()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new TextureManager();
	}
}

void TextureManager::Destroy()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

TextureManager* TextureManager::GetInstance()
{
	return m_pInstance;
}

//-------------------------------------------------------------------------
// GetTexture
//		returns specified texture
//-------------------------------------------------------------------------
aie::Texture* TextureManager::GetTexture(eTextures texture)
{
	return m_pTextures[texture];
}

