#pragma once

#ifndef cgmath
#define cgmath

#include "pch.h"

bool WithinRange(float value, float min, float max);
vec_t AngleDelta(float angle1, float angle2);
float normalize(float x);

void AngleVectors(const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up);
void vector_scale(vec3_t vector, float scale, vec3_t out);
void vector_add(vec3_t veca, vec3_t vecb, vec3_t out);
float vector_scaleComponent(float index, float scale);
float vector_addComponent(float index, float amount);
void AnglesToForward(vec3_t angles, vec3_t origin, float scale, vec3_t out);
void AnglesToRight(vec3_t angles, vec3_t origin, float scale, vec3_t out);
void AnglesToUp(vec3_t angles, vec3_t origin, float scale, vec3_t out);

vec_t UE_ConvertGameYaw(vec_t angles);

#endif