// Fill out your copyright notice in the Description page of Project Settings.


#include "ChasingAIController.h"
#include "BehaviorTree/BehaviorTree.h"

AChasingAIController::AChasingAIController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("SightPerceptionComponent"));

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	PerceptionComponent->ConfigureSense(*SightConfig);
	PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());

	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AChasingAIController::OnTargetPerceptionUpdate);

}

void AChasingAIController::OnPossess(APawn * InPawn)
{
	Super::OnPossess(InPawn);
	if (BehaviorTree != nullptr)
	{
		RunBehaviorTree(BehaviorTree);
	}
}

void AChasingAIController::OnTargetPerceptionUpdate(AActor * Actor, FAIStimulus Stimulus)
{
	if (Actor)
	{
		LastKnownPlayerPosition = Stimulus.StimulusLocation;
		bCanSeePlayer = Stimulus.WasSuccessfullySensed();
	}
}
