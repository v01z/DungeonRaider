// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"	  // for GetWorld()
#include "DrawDebugHelpers.h" // for DrawDebugLine()

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	/*
	FRotator CurrentRotation = GetComponentRotation();
	FString RotationStr = CurrentRotation.ToCompactString();
	UE_LOG(LogTemp, Display, TEXT("Grabber's rotation is: %s"), *RotationStr);
	float Time = GetWorld()->TimeSeconds;
	UE_LOG(LogTemp, Display, TEXT("Current Time is: %f"), Time);
	*/

	// FVector Start = GetComponentLocation().GetForwardVector();
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	// DrawDebugLine(GetWorld(), Start, End, FColor::Red, true);
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	// UE_LOG(LogTemp, Display, TEXT("**************\nStart vector is: %s"), *(Start.ToCompactString()));
	// UE_LOG(LogTemp, Display, TEXT("End vector is: %s"), *(End.ToCompactString()));

	FHitResult HitResult;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	// ECC_GameTraceChannel2 from DefaultEngine.ini for Grabber
	bool HasHit = GetWorld()->SweepSingleByChannel(HitResult,
												   Start, End,
												   FQuat::Identity,
												   ECC_GameTraceChannel2,
												   Sphere);

	if (HasHit)
		UE_LOG(LogTemp, Display, TEXT("Has hit == true: %s"), *HitResult.GetActor()->GetActorNameOrLabel());
}
