#pragma once
#ifndef rtext
#define rtext
#include "pch.h"

namespace r
{
	//void TextWithOutline(std::string p, D3DRECT rect, vec3_t color);
	//void TextWithOutline(vec2_t rect, vec4_t color, const char* msg, ...);

	float X(float pos);
	float Y(float pos);

	void MetricsHelpMarker(const char* desc);

}

#endif