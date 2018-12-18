// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float Amount)
{
	//Amount is transformed to either 0, -1 or +1
	//all the rotation is per frame
	if (Amount < MinTorelanceDegree || Amount > MaxTorelanceDegree)
	{
		Amount = FMath::Clamp(Amount, -1.0f, +1.0f);
		auto RotationChange = Amount * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
		auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
		//UE_LOG(LogTemp, Warning, TEXT("RotationChange %f; RawNewRotation %f"), RotationChange, RawNewRotation)

		auto Rotation = FMath::Clamp(RawNewRotation, MinRotationInDegree, MaxRotationInDegree);

		SetRelativeRotation(FRotator(0.0f, Rotation, 0.0f));
	}

}
