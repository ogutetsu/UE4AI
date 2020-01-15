// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"


void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AUE4AICharacter* AIChar = Cast<AUE4AICharacter>(InPawn);
	if (AIChar != nullptr)
	{
		UBehaviorTree* BehaviorTree = AIChar->BehaviorTree;
		if (BehaviorTree != nullptr)
		{
			RunBehaviorTree(BehaviorTree);
		}
	}
}

