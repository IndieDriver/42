#version 400
layout(location = 0) in vec3 vertex_pos;
layout(location = 1) in vec3 vertex_color;
layout(location = 2) in vec3 vertex_normal;
uniform mat4 MVP;
uniform vec3 light;
out vec3 color;

void main () {
	vec3 l = vec3(0.0f, 0.0f, -1.0);
	vec3 n = normalize(vertex_normal);
	color = vec3(1.0, 0.0, 0.0) * clamp(dot(n,l), 0, 1);
	color += vec3(1.0, 0.0, 0.0) * 0.2;
	gl_Position = MVP * vec4(vertex_pos, 1.0);
}
