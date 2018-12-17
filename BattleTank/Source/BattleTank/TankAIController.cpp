// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn == nullptr)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControllerTank();
	if (Tank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank AI controller failed to posses tank!"))
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tank AI controller possesed %s"), *Tank->GetName())
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("World does not have a player tank!"))
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("AI controller found player tank %s"), *PlayerTank->GetName())

	}
}
	
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Tank player controller tick is working!"))
	if (GetControllerTank() == nullptr) { return; }
	if (GetPlayerTank() == nullptr) { return; }
	
	GetControllerTank()->AimtAt(GetPlayerTank()->GetActorLocation());

}

