// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float Amount)
{
	//Amount is transformed to either 0, -1 or +1
	//all the rotation is per frame
	if (Amount < MinTorelanceDegree || Amount > MaxTorelanceDegree)
	{
		Amount = FMath::Clamp(Amount, -1.0f, 1.0f); 
		auto ElevationChange = Amount * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds; 
		auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
		//UE_LOG(LogTemp, Warning, TEXT("ElevationChange %f; RawNewElevation %f"), ElevationChange, RawNewElevation)

		auto Elevation = FMath::Clamp(RawNewElevation, MinElevationInDegree, MaxElevationInDegree);

		SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f));
	}
	
}