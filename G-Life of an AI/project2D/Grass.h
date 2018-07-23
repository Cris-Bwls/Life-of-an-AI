#pragma once
#include "ResourceObject.h"
class Grass :
	public ResourceObject
{
public:
	Grass();
	~Grass();

	void Reset();

	void Draw(aie::Renderer2D* pRenderer);
};

