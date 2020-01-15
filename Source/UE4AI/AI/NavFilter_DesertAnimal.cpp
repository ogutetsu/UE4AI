// Fill out your copyright notice in the Description page of Project Settings.


#include "NavFilter_DesertAnimal.h"
#include "NavArea_Desert.h"

UNavFilter_DesertAnimal::UNavFilter_DesertAnimal()
{
	FNavigationFilterArea Desert = FNavigationFilterArea();

	Desert.AreaClass = UNavArea_Desert::StaticClass();

	Desert.bOverrideEnteringCost = true;
	Desert.EnteringCostOverride = 0.f;

	Desert.bOverrideTravelCost = true;
	Desert.TravelCostOverride = 0.8f;

	Areas.Add(Desert);

}
