// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

// Reset the player tank to default position when flipped over.
void ATank::ResetPlayerTank()
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	FRotator PlayerTankRotator(0.f, 0.f, 0.f);

	PlayerTank->SetActorRotation(PlayerTankRotator);
}

