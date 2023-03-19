// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereActor.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ASphereActor::ASphereActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Creates a Component
	staticmeshcomponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//Attaching the component to the RootComponent
	staticmeshcomponent->SetupAttachment(RootComponent);
	// /Game/StarterContent/Props/MaterialSphere.MaterialSphere
	static ConstructorHelpers::FObjectFinder<UStaticMesh> actor_visual_asset(TEXT("/Game/StarterContent/Props/MaterialSphere.MaterialSphere"));
	//Other way to create a object/instantiate
	//ConstructorHelpers::FObjectFinder<UStaticMesh>my_actor_visual_asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Props/MaterialSphere.MaterialSphere"));
	if (actor_visual_asset.Succeeded())
	{
		staticmeshcomponent->SetStaticMesh(actor_visual_asset.Object);
	}
	staticmeshcomponent->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ASphereActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}