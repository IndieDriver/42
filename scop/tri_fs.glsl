#version 400

in vec4 normal;
in vec4 wpos;
in mat4 mv;
in vec2 UV;
out vec4 frag_color;
uniform sampler2D textures;
uniform int	hasTexture;
void main () {
	vec3 nor_mv = normalize((normal * transpose(inverse(mv))).xyz);
	vec3 eye_pos = vec3(0.0f, 0.0f, -1.0f);
	vec3 light_dir = normalize(vec3(0.5f, 0.0f, 0.5f));
	vec3 light_col = vec3(1.0f, 1.0f, 1.0f);
	vec4 obj_col;
	if (hasTexture == 0)
		obj_col = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	else
		obj_col = texture(textures, UV);
	float kspec = 0.0;

	float kdiffuse = clamp(dot(nor_mv, light_dir),0,1);
	/*if (kdiffuse > 0.0)
	{
		vec3 refl = normalize(reflect(light_dir, nor_mv));
		vec3 eye = normalize(eye_pos - wpos.xyz);
		kspec = pow(dot(eye, refl), 5.0);
	} */
	vec3 color = obj_col.xyz * 0.2 + obj_col.xyz * kdiffuse * 0.5;//+ (light_col * kspec * 0.5);
	frag_color = vec4(color, 1.0);
}
