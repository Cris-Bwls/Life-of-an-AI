#pragma once
#include "ResourceObject.h"
class Rock :
	public ResourceObject
{
public:
	Rock();
	~Rock();

	void Draw(aie::Renderer2D* pRenderer);
};

