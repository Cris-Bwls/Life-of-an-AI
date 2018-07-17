#pragma once
#include "ResourceObject.h"
class Grass :
	public ResourceObject
{
public:
	Grass();
	~Grass();

	void Draw(aie::Renderer2D* pRenderer);
};

