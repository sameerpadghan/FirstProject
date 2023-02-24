// Fill out your copyright notice in the Description page of Project Settings.

#include "StoneActor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values
AStoneActor::AStoneActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Creates a Component
	staticmeshcomponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//Attaching the component to the RootComponent
	staticmeshcomponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> actor_visual_asset(TEXT("/Game/StarterContent/Props/SM_Rock.SM_Rock"));
	//Other way to create a object/instantiate
	//ConstructorHelpers::FObjectFinder<UStaticMesh>my_actor_visual_asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Props/MaterialSphere.MaterialSphere"));
	if (actor_visual_asset.Succeeded())
	{
		staticmeshcomponent->SetStaticMesh(actor_visual_asset.Object);
	}
	//this->SetActorTickInterval(0.5f);
}

// Called when the game starts or when spawned
void AStoneActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStoneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//In which Axis the actor should go
	FVector my_delta_location = FVector(0.0f, 0.0f, 1.0f);
	this->AddActorWorldOffset(my_delta_location);
	//Printing on the Screen
	UKismetSystemLibrary::PrintString(this, TEXT("Printing on screen from C++"));
}