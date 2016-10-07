#include "../samplers/sampler.h"

#include "emissive.h"

emissive::emissive(texture* albedo, float intensity) :
    _albedo(albedo),
    _intensity(intensity)
{
}

bool emissive::scatter(const ray& r, const intersection& hit, glm::vec3& attenuation, ray& scattered) const
{
    return false;
}

vec3 emissive::emitted(const vec2 & uv, const vec3 & point) const
{
    return _albedo->fetch(uv, point) * _intensity;
}
