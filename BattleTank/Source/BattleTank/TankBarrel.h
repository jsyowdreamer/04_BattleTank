// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float Amount);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSecond = 10.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationInDegree = 0.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationInDegree = 40.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinTorelanceDegree = -1.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxTorelanceDegree = 1.0f;
};
