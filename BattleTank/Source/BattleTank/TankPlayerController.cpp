// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControllerTank();
	if (Tank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank player controller failed to posses tank!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank player controller possesed %s"), *GetControllerTank()->GetName())
	}
	

}

