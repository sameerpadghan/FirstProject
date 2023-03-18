// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereActor.generated.h"

UCLASS()
class FIRSTPROJECT_API ASphereActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASphereActor();
	//Making it Editable from C++ or from Blueprints
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* staticmeshcomponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
