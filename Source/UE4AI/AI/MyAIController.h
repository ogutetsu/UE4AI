// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UE4AI/UE4AICharacter.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UE4AI_API AMyAIController : public AAIController
{
	GENERATED_BODY()

protected:

	void OnPossess(APawn* InPawn) override;

	
};
