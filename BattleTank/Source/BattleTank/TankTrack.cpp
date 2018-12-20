// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	//auto Name = this->GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s throttle %f"), *Name, Throttle)

	auto ForceApplied = this->GetForwardVector() * Throttle *MaxDrivingForce;
	auto ForceLocation = this->GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(this->GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}