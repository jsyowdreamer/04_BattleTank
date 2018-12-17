// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, +1.0f);
	auto RotationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	UE_LOG(LogTemp, Warning, TEXT("RotationChange %f; RawNewRotation %f"), RotationChange, RawNewRotation)

	auto Rotation = FMath::Clamp(RawNewRotation, MinRotationInDegree, MaxRotationInDegree);

	SetRelativeRotation(FRotator(0.0f, Rotation, 0.0f));


}
