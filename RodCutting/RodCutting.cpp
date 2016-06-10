#include "stdafx.h"
#include "RodCutting.h"


RodCutting::RodCutting()
{
	r = new int[LENGTH]();
	p = new int[LENGTH]{1,5,8,9,10,17,17,20,24,30};
}


RodCutting::~RodCutting()
{
	delete[] r;
	delete[] p;
}
