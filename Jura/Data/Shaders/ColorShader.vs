attribute 	vec3 	a_posL;
attribute 	vec2 	a_uv;

uniform 	mat4 	u_matMVP;
uniform 	mat4 	u_matWorld;
uniform 	float 	u_numframe;
uniform		float 	u_currentframe;

varying 	vec2 	v_uv;

void main()
{
	vec4 posL = vec4(a_posL, u_alpha);
	gl_Position = u_matMVP * posL;
	v_uv = vec2(a_uv.x*1.0/numframe+1.0/numframe*u_currentframe,a_uv.y);
}   