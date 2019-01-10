// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//...

	auto AITank = GetAITank();
	if (!AITank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tanks controller not found"), *AITank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tanks: %s"), *AITank->GetName());
	}

	auto FoundPlayerTank = GetPlayerTank();
	if (!FoundPlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("No player tank in world"));
	}
	else {
		
		UE_LOG(LogTemp, Warning, TEXT("%s found Player tank: %s"),*AITank->GetName(), *FoundPlayerTank->GetName());
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// TODO move toward the player

	// Aim toward the player
	GetAITank()->AimAt(GetPlayerTank()->GetTargetLocation()); // can use GetActorLocation

	// TODO Fire when ready
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
