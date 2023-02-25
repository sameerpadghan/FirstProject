// Fill out your copyright notice in the Description page of Project Settings.

#include "StoneActor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyObject.h"
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
	//template<class T>
	//T* NewObject
	//(
	//	UObject * Outer
	//)
	//Here Outer means the Actor who is owning the object
	//creating a UMyObject class object
	auto u_my_obj = NewObject<UMyObject>(this);
	//using it method my_function
	u_my_obj->my_function(10.0f);
	//Printing on the Screen
	UKismetSystemLibrary::PrintString(this, TEXT("Printing on screen using C++ from StoneActor"));
}

// Called every frame
void AStoneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//In which Axis the actor should go
	FVector my_delta_location = FVector(0.0f, 0.0f, 1.0f);
	this->AddActorWorldOffset(my_delta_location);
	//Making cRotation around the up axis(around Z axis)
	FRotator myDeltaRotation = FRotator(0.0f, 10.0f, 0.0f);
	this->AddActorWorldRotation(myDeltaRotation);
	//Printing on the Screen
	//UKismetSystemLibrary::PrintString(this, TEXT("Printing on screen from C++"));
}