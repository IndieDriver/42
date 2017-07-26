#include <math.h>
#include <stdio.h>
#include "libft.h"

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
		printf("%f|%f|%f|%f\n", v1.x, v1.y, v1.z, v1.w);
}

int main()
{
	t_vec4 vec;

	vec.x = 42.0f;
	vec.y = 84.0f;
	vec.z = 21.0f;
	vec.w = 0.0f;

	t_vec4 vec2;

	vec2.x = 1.0f;
	vec2.y = 3.0f;
	vec2.z = 5.0f;
	vec2.w = 7.0f;

	//printf("%f|%f|%f|%f\n", newvec2.x, newvec2.y, newvec2.z, newvec2.w);

	printf("%f|%f\n", ft_vec4len(vec), my_vec_len(vec));
	printf("%f|%f|%f|%f\n", vec2.x, vec2.y, vec2.z, vec2.w);
	printf("%f|%f\n", ft_vec4len(vec2), my_vec_len(vec2));

	printf("%f|%f|%f|%f\n", vec2.x, vec2.y, vec2.z, vec2.w);
	vec_normalize(vec2);
	vec2 = ft_vec4normalize(&vec2);
	printf("%f|%f|%f|%f\n", vec2.x, vec2.y, vec2.z, vec2.w);
	printf("%f|%f|%f|%f\n", vec2.x, vec2.y, vec2.z, vec2.w);
}
