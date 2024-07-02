#include "Object3d.hlsli"

struct Material {
    float32_t4 color;
    int32_t enableLighting;
};

struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

struct DirectionalLight {
    float32_t4 color;      //!< ライトの色
    float32_t3 direction;  //!< ライトの向き
    float intensity;       //!< 輝度
};

ConstantBuffer<Material> gMaterial : register(b0);
Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);
ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);

PixelShaderOutput main(VertexShaderOutput input) {
    PixelShaderOutput output;
    output.color = gMaterial.color;
    
    float32_t4 textureColor = gTexture.Sample(gSampler, input.texCoord);
    
    if (gMaterial.enableLighting != 0) {// Lightingする場合
       // half lambert
        float NdotL = dot(normalize(input.normal), -gDirectionalLight.direction);
        float cos = pow(NdotL * 0.5f + 0.5f, 2.0);
        output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
    } else {// Lightingしない場合。前回までと同じ演算
        output.color = gMaterial.color * textureColor;
    }
    
    return output;
}
