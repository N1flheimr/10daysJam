#pragma once
#include"Vector3.h"
#include"CollisionConfig.h"
#include <cstdint>

/// <summary>
/// 衝突判定オブジェクト
/// </summary>
class Collider
{
private:
	float radius_ = 2.0f;

	//衝突属性(自分)
	uint32_t collisionAttribute_ = 0xffffffff;
	//衝突属性(相手)
	uint32_t collisionMask_ = 0xffffffff;

public:
	float GetRadius();
	void SetRadius(const float& radius);

	//衝突時に呼ばれる
	virtual void OnCollision() = 0;
	//world座標をゲット
	virtual Vector3 GetWorldPos() = 0;

	//衝突用ビット系
	//自分
	uint32_t GetCollisionAttribute();
	void SetCollisionAttribute(const uint32_t& bit);
	//敵
	uint32_t GetCollisionMask();
	void SetCollisionMask(const uint32_t& bit);
};

