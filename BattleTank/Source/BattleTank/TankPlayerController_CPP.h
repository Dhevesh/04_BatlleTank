// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BattleTank/Public/Tank_CPP.h"
#include "TankPlayerController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_CPP : public APlayerController
{
	GENERATED_BODY()
	
public:

	ATank_CPP* GetControlledTank() const;
	
};
