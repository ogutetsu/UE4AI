// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Sight.h"
#include "ChasingAIController.generated.h"

/**
 * 
 */
UCLASS()
class UE4AI_API AChasingAIController : public AAIController
{
	GENERATED_BODY()

	AChasingAIController();

	UAISenseConfig_Sight* SightConfig;

public:

	FVector LastKnownPlayerPosition;
	bool bCanSeePlayer;


protected:
	UFUNCTION()
	void OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus);

};
