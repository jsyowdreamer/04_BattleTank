// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
	
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());

	//UE_LOG(LogTemp, Warning, TEXT("Tank player controller tick is working!"))
	if (AITank == nullptr) { return; }
	if (PlayerTank == nullptr) { return; }

	//Move to actor
	this->MoveToActor(PlayerTank, AcceptanceRadius);
	
	//auto time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: AI aim at %s"), time, *GetPlayerTank()->GetActorLocation().ToString())
	AITank->AimtAt(PlayerTank->GetActorLocation());
	
	AITank->Fire();
}

