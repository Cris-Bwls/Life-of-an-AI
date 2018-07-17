#pragma once
#include "ResourceObject.h"
class Tree :
	public ResourceObject
{
public:
	Tree();
	~Tree();

	void Draw(aie::Renderer2D* pRenderer);
};

