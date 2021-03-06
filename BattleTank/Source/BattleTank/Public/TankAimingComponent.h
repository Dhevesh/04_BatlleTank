// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

// Forward Declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

UCLASS( meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel*BarrelToSet, UTankTurret* TurretToSet);

protected:

	UPROPERTY(BlueprintReadOnly)
	EFiringState FiringState = EFiringState::Locked;

public:	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();


private:
	// variables
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; // sensible default value
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// helper method
	void MoveBarrelTowards(FVector AimDirection);
};
