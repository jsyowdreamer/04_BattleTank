// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"  //must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	ATank* GetControllerTank() const;

	ATank* GetPlayerTank() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};
