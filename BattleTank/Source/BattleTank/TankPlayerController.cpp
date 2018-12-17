// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimsTowardsCrosshair()
{
	if (GetControllerTank() == nullptr) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString())
		GetControllerTank()->AimtAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);

	FVector CameraWorldLocation, WorldDirection;
	if (this->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Camera world location %s"), *CameraWorldLocation.ToString())
		//UE_LOG(LogTemp, Warning, TEXT("World direction %s"), *WorldDirection.ToString())
		return GetLookVectorHitLocation(WorldDirection, HitLocation);
	}

	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	
	FHitResult HitResult;

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	//UE_LOG(LogTemp, Warning, TEXT("Start location %s"), *StartLocation.ToString())
	FVector EndLocation = StartLocation + LookDirection * LineTraceRange;
	//UE_LOG(LogTemp, Warning, TEXT("End location %s"), *EndLocation.ToString())

	//draw a traceline
	//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor(255, 0, 0, 0), false, 0.0f, 0, 5.0f);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		//UE_LOG(LogTemp, Warning, TEXT("Aimpoint hit %s"), *HitLocation.ToString())
		return true;
	}

	return false;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Tank player controller tick is working!"))
	AimsTowardsCrosshair();

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
		//UE_LOG(LogTemp, Warning, TEXT("Tank player controller possesed %s"), *GetControllerTank()->GetName())
	}
	

}

