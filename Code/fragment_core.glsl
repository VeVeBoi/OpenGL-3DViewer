#version 430

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;
in vec3 vs_normal;

out vec4 fs_color;

uniform vec3 lightPos0;
uniform vec3 cameraPos;

void 
main()
{

    //ambient light
    vec3 ambientLight = vec3(0.1f, 0.1f, 0.1f);

    //diffuse light
    vec3 posToLightDirVec = normalize(lightPos0 - vs_position);
    vec3 diffuceColor = vec3(1.f, 1.f, 1.f);
    float diffuse = clamp(dot(posToLightDirVec, vs_normal), 0,1);
    vec3 diffuseFinal = diffuceColor * diffuse;

    //specular light
    vec3 lightToPosDirVec = normalize(vs_position - lightPos0);
    vec3 reflectiveDirVec = normalize(reflect(lightToPosDirVec, normalize(vs_normal)));
    vec3 posToViewDirVec = normalize(cameraPos - vs_position);
    float specularConst = pow(max(dot(posToViewDirVec, reflectiveDirVec), 0), 30); 
    vec3 specularFinal = vec3(1.f, 1.f, 1.f) * specularConst;

    //attenuation light //cutoff for the light

    //final Lights

    fs_color = vec4(vs_color, 1.f) * (vec4(ambientLight, 1.f) 
    + vec4(diffuseFinal, 1.f)
    + vec4(specularFinal, 1.f));
}