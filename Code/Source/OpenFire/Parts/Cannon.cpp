// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Cannon.h"
#include "Bullets/Bullet.h"

void ACannon::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    ReloadTime += DeltaSeconds;
    if (ReloadTime >= FireDelay)
    {
        ReloadTime -= FireDelay;
        Fire();
    }
}

void ACannon::Fire()
{
    ABullet* pBullet = GetWorld()->SpawnActor<ABullet>(GetActorLocation(), GetActorRotation());
}