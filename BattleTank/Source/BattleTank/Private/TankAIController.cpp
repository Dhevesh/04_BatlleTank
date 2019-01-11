// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//...

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank) {
		auto AITank = Cast<ATank>(GetPawn());

		// TODO move toward the player

		// Aim toward the player
		AITank->AimAt(PlayerTank->GetTargetLocation()); // can use GetActorLocation

		// TODO Fire when ready
		AITank->Fire();
	}
}
