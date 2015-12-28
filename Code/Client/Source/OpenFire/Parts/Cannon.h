// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Parts/ShipPart.h"
#include "Bullets/Bullet.h"
#include "Cannon.generated.h"

UCLASS()
class OPENFIRE_API ACannon : public AShipPart
{
	GENERATED_BODY()

public:
	ACannon();

	virtual void Tick(float DeltaSeconds) override;

	void SetBarrelTargetPitch(const float& TargetPitch);
	void SetBodyTargetYaw(const float& TargetYaw);
	void Fire();

private:
	void RotateBarrel(float DeltaSeconds);
	void RotateBody(float DeltaSeconds);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
	UStaticMeshComponent* Barrel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Bullet Class"), Category = Cannon)
	TSubclassOf<ABullet> BulletClass;

	const float& GetBulletSpeed();

private:
	UPROPERTY(EditAnywhere)
	float BulletSpeed = 4000.f;

	float FireDelay = 2.0f;
	float ReloadTime = 0.0f;

	float TargetPitch = 45.0f;
	float PitchSpeed = 30.0f;

	float TargetYaw = 30.0f;
	float YawSpeed = 20.0f;
};
