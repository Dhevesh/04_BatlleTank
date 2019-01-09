// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//...

	auto AITank = GetAIController();
	UE_LOG(LogTemp,Warning,TEXT("AI Tanks: %s"),*AITank->GetName())

}

ATank* ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}
