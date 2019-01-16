// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; // sensible default firing speed.

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local barrel reference to spawn
	UTankBarrel* Barrel = nullptr; // TODO remove

	UTankAimingComponent* TankAimingComponent = nullptr;

	double LastFireTime = 0;
};
