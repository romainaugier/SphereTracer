struct vec3 { float x, y, z; };

struct vec3 operator-(struct vec3 a, struct vec3 b)
{
    struct vec3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

inline static float dot(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

export void SphereHitN(uniform float spheresCentersX[],
    uniform float spheresCentersY[],
    uniform float spheresCentersZ[],
    uniform float spheresRadius[],
    uniform vec3& rayOrigin, uniform vec3& rayDirection,
    uniform float t[], uniform int count, uniform int start)
{
    const float a = dot(rayDirection, rayDirection);

    foreach(i = 0 ... count)
    {
        vec3 center;
        center.x = spheresCentersX[i + start];
        center.y = spheresCentersY[i + start];
        center.z = spheresCentersZ[i + start];

        const vec3 oc = rayOrigin - center;
        const float b = dot(oc, rayDirection);
        const float c = dot(oc, oc) - spheresRadius[i + start] * spheresRadius[i + start];
        const float discriminant = b * b - a * c;

        cif (discriminant > 0)
        {
            const float tTmp = (-b - sqrt(discriminant)) / a;

            cif (tTmp > 0.0f && tTmp < t[i])
            {
                t[i] = tTmp;
            }
        }
    }  
}