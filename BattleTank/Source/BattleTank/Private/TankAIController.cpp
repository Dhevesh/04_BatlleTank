// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent)) {
		//FoundAimingComponent(AimingComponent);
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();

	auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	if (!ensure(PlayerTank && AITank)) { return; }
		

		// TODO move toward the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim toward the player
		AimingComponent->AimAt(PlayerTank->GetTargetLocation()); // can use GetActorLocation

		// TODO Fire when ready
		AimingComponent->Fire(); // TODO fix firing
}
