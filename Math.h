#pragma once
#include <cmath>

struct Vector2 {
	float x;
	float y;
};

struct Vector3 {
	float x;
	float y;
	float z;
};

struct Vector4 {
	float x;
	float y;
	float z;
	float w;
};

struct VertexData {
	Vector4 position;
	Vector2 texCoord;
	Vector3 normal;
};

struct Matrix4x4 {
	float m[4][4];
};

struct Transform {
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
};

struct Material {
	Vector4 color;
	int32_t enableLighting;
};

struct TransformationMatrix {
	Matrix4x4 WVP;
	Matrix4x4 World;
};

struct DirectionalLight {
	Vector4 color;      //!< ライトの色
	Vector3 direction;  //!< ライトの向き
	float intensity;    //!< 輝度
};


// 単位行列の作成関数
Matrix4x4 MakeIdentity4x4();


// 平行移動行列の作成関数
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

// 拡大縮小行列の作成関数
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

// 回転行列の作成関数
Matrix4x4 MakeRotateXMatrix(float radian);
Matrix4x4 MakeRotateYMatrix(float radian);
Matrix4x4 MakeRotateZMatrix(float radian);

// 行列の積
Matrix4x4 Multiply(const Matrix4x4& matrix1, const Matrix4x4& matrix2);

// affine行列の作成関数
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

// 透視投影行列の作成関数
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

// 逆行列
Matrix4x4 Inverse(const Matrix4x4& m);

// 正射影行列の作成関数
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);