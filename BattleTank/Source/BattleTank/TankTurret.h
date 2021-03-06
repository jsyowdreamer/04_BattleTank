// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void Rotate(float Amount);

private: //If made these private barrel and turret static mesh will be missing on hot reload. See UE-63298
		//even if make this public and if this file is edited same thing would happen. Workaround is do not perform a hot reload
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSecond = 25.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinRotationInDegree = -127.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxRotationInDegree = 127.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinTorelanceDegree = -1.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxTorelanceDegree = 1.0f;
};
