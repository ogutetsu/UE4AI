// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdateChasing.h"
#include "ChasingAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


UBTService_UpdateChasing::UBTService_UpdateChasing(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NodeName = "Update Chasing Behavior";

	bNotifyBecomeRelevant = true;
	bNotifyCeaseRelevant = false;

	PlayerKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_UpdateChasing, PlayerKey), AActor::StaticClass());
	LastKnownPositionKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_UpdateChasing, LastKnownPositionKey));
	CanSeePlayerKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_UpdateChasing, CanSeePlayerKey));

}

void UBTService_UpdateChasing::OnBecomeRelevant(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return;
	}

	if (!PlayerKey.IsSet())
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlayerClass, FoundActors);
		if (FoundActors[0])
		{
			BlackboardComp->SetValueAsObject(PlayerKey.SelectedKeyName, FoundActors[0]);
		}
	}


}

void UBTService_UpdateChasing::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return;
	}

	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) 
	{
		return;
	}

	AChasingAIController* ChasingController = Cast< AChasingAIController>(AIController);
	if (!ChasingController)
	{
		return;
	}

	BlackboardComp->SetValueAsBool(CanSeePlayerKey.SelectedKeyName, ChasingController->bCanSeePlayer);

	if (ChasingController->bCanSeePlayer != bLastCanSeePlayer)
	{
		BlackboardComp->SetValueAsVector(LastKnownPositionKey.SelectedKeyName, ChasingController->LastKnownPlayerPosition);
	}

	bLastCanSeePlayer = ChasingController->bCanSeePlayer;

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

}
