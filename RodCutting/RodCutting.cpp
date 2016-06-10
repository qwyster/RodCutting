#include "stdafx.h"
#include "RodCutting.h"


RodCutting::RodCutting()
{
	r = new int[LENGTH];
	p = new int[LENGTH];
}


RodCutting::~RodCutting()
{
	delete[] r;
	delete[] p;
}
