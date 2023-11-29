// Fill out your copyright notice in the Description page of Project Settings.

#include "Mover.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Display, TEXT("BeginPlay() on Mover."));
}

// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	AActor *Owner = GetOwner();
	UE_LOG(LogTemp, Display, TEXT("************************************************"));
	UE_LOG(LogTemp, Display, TEXT("Mover is ticking! Owner name is '%s'\n"), *Owner->GetName());
	UE_LOG(LogTemp, Display, TEXT("Mover Owner address is '%u'\n"), Owner);
	UE_LOG(LogTemp, Display, TEXT("Address of Owner is '%p'\n"), Owner);
}
