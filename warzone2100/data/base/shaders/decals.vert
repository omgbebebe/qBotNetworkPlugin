#version 120

uniform mat4 ModelViewProjectionMatrix;

uniform vec4 paramxlight;
uniform vec4 paramylight;
uniform mat4 lightTextureMatrix;

attribute vec4 vertex;
attribute vec2 vertexTexCoord;

varying vec2 uv_tex;
varying vec2 uv_lightmap;
varying float vertexDistance;

void main()
{
	vec4 position = ModelViewProjectionMatrix * vertex;
	gl_Position = position;
	uv_tex = vertexTexCoord;
	vec4 uv_lightmap_tmp = lightTextureMatrix * vec4(dot(paramxlight, vertex), dot(paramylight, vertex), 0.0, 1.0);
	uv_lightmap = uv_lightmap_tmp.xy / uv_lightmap_tmp.w;
	vertexDistance = position.z;
}
