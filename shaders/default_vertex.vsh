#version 150
in vec3 PosCoord;
in vec2 TexCoord;

//out vec3 fragColor;
out vec2 fragTexCoord;
out vec3 fragPosCoord;

uniform mat4 all;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;


void main(void)
{
    gl_Position =  all * vec4(PosCoord.xyz, 1.);

    fragPosCoord = gl_Position.xyz;
    fragTexCoord = TexCoord;
}

