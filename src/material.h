#pragma once

#include "maths.h"
#include <stdint.h>

enum MaterialType
{
	MaterialType_Diffuse = 0x1,
	MaterialType_Reflective = 0x2,
	MaterialType_Dielectric = 0x4

};

struct Material
{
	vec3 m_Color;

	uint32_t m_Id;

	uint8_t m_Type;

	virtual vec3 Sample(const vec3& N, const vec3& wi, const float rx, const float ry, const float rz) = 0;
	virtual vec3 Eval(const vec3& N, const vec3& wo, const float rx, const float ry, const float rz) = 0;
};

struct MaterialDiffuse : public Material
{
	MaterialDiffuse() {}

	vec3 Sample(const vec3& N, const vec3& wi, const float rx, const float ry, const float rz) const override;
	vec3 Eval(const vec3& N, const vec3& wo, const float rx, const float ry, const float rz) const override;
};

struct MaterialReflective : public Material
{
	float m_Roughness = 0.0f;

	MaterialReflective() {}

	vec3 Sample(const vec3& N, const vec3& wi, const float rx, const float ry, const float rz) const override;
	vec3 Eval(const vec3& N, const vec3& wo, const float rx, const float ry, const float rz) const override;
};

struct MaterialDielectric : public Material
{
	float m_Ior = 1.33f;
	float m_Roughness = 0.0f;

	MaterialDielectric() {}

	vec3 Sample(const vec3& N, const vec3& wi, const float rx, const float ry, const float rz) const override;
	vec3 Eval(const vec3& N, const vec3& wo, const float rx, const float ry, const float rz) const override;
};