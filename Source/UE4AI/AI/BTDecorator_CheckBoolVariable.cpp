// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CheckBoolVariable.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTDecorator_CheckBoolVariable::UBTDecorator_CheckBoolVariable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NodeName = "Check Bool Variable";
}



bool UBTDecorator_CheckBoolVariable::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return false;
	}
	return BlackboardComp->GetValueAsBool(BoolVariableToCheck.SelectedKeyName);
}



FString UBTDecorator_CheckBoolVariable::GetStaticDescription() const
{
	return FString::Printf(TEXT("%s: '%s'"), TEXT("Bool Variable to Check"), BoolVariableToCheck.IsSet() ? *BoolVariableToCheck.SelectedKeyName.ToString():TEXT(""));
}

