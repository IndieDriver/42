#include <math.h>
#include <stdio.h>
#include "libft.h"

t_vec4  vec_scale(t_vec4 v1, float fact)
{
        t_vec4 res;

        res.x = v1.x * fact;
        res.y = v1.y * fact;
        res.z = v1.z * fact;
        return (res);
}


float	my_vec_len(t_vec4 v1)
{
	return (sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w));
}

void    vec_normalize(t_vec4 v1)
{
        double  fact;
        double  len;

		len = my_vec_len(v1);
        fact = 1.0f / len;
        v1.x *= fact;
        v1.y *= fact;
        v1.z *= fact;
		v1.w *= fact;
		printf("C:   %f|%f|%f|%f\n", v1.x, v1.y, v1.z, v1.w);
}

float	dot(t_vec4 v1, t_vec4 v2)
{
        return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float	distance(t_vec4 pt1, t_vec4 pt2)
{
        return (sqrtf((pt2.x - pt1.x) * (pt2.x - pt1.x)
					+ (pt2.y - pt1.y) * (pt2.y - pt1.y)
					+ (pt2.z - pt1.z) * (pt2.z - pt1.z)
					+ (pt2.w - pt1.w) * (pt2.w - pt1.w)));
}


t_vec4  vec_cross(t_vec4 v1, t_vec4 v2)
{
        t_vec4 result;

        result.x = v1.y * v2.z - v1.z * v2.y;
        result.y = v1.z * v2.x - v1.x * v2.z;
        result.z = v1.x * v2.y - v1.y * v2.x;
        return (result);
}

int main()
{
	t_vec4 vec;

	vec.x = 42.0f;
	vec.y = 84.0f;
	vec.z = 21.0f;
	vec.w = 12.0f;

	t_vec4 vec2;

	vec2.x = 1.0f;
	vec2.y = 3.0f;
	vec2.z = 5.0f;
	vec2.w = 7.0f;

	printf("\nscale:\n");
	printf("vec : %f|%f|%f|%f\n", vec.x, vec.y, vec.z, vec.w);
	t_vec4 scale = ft_vec4scale(vec, 0.5f);
	printf("vec * 0.5f : %f|%f|%f|%f\n", scale.x, scale.y, scale.z, scale.w);
	scale = ft_vec4scale(vec, 0.0f);
	printf("vec * 0.0f : %f|%f|%f|%f\n", scale.x, scale.y, scale.z, scale.w);

	printf("\nlength: ( ASM | C )\n");
	printf("vec: %f|%f\n", ft_vec4len(vec), my_vec_len(vec));
	printf("vec2: %f|%f\n", ft_vec4len(vec2), my_vec_len(vec2));
	printf("scale: %f|%f\n", ft_vec4len(scale), my_vec_len(scale));

	printf("\nnormalize:\n");
	vec_normalize(vec2);
	ft_vec4normalize(&vec2);
	printf("ASM: %f|%f|%f|%f\n", vec2.x, vec2.y, vec2.z, vec2.w);
	vec_normalize(vec);
	ft_vec4normalize(&vec);
	printf("ASM: %f|%f|%f|%f\n", vec.x, vec.y, vec.z, vec.w);

	printf("\ndot_product: ( ASM | C )\n");
	printf("vec/vec2: %f|%f\n", ft_vec4dot(vec, vec2), dot(vec, vec2));
	printf("vec/scale: %f|%f\n", ft_vec4dot(vec, scale), dot(vec, scale));

	printf("\ndistance: ( ASM | C )\n");
	printf("vec/vec2: %f|%f\n", ft_vec4distance(vec, vec2), distance(vec, vec2));
	printf("vec/scale: %f|%f\n", ft_vec4distance(vec, scale), distance(vec, scale));
}
