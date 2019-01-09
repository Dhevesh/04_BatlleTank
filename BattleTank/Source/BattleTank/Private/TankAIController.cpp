// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//...

	auto AITank = GetAIController();
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

ATank* ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
