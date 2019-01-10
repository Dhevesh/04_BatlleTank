// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("No control attached"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank: %s"), *ControlledTank->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("Playercontroller initialised from c++"));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);
	}
}
// Get world location of linetrace through crosshair, true if hits landscape	
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	/// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHiarYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{

	FVector CameraWorldLocation; // TODO discard this variable
	return DeprojectScreenPositionToWorld(ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = (StartLocation + LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility
			)
		){
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0.f); //if nothing is hit this returns zero to avoid and weird numbers being returned.
	return false;

}
;

