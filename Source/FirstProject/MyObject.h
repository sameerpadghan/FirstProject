// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 *
 */
 //Keywords used when declaring UClasses to specify how the class behaves with various aspects of the Engine and Editor.
 //Link:https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/GameplayArchitecture/Classes/Specifiers/
 //Making the class blueprintable
UCLASS(Blueprintable)
class FIRSTPROJECT_API UMyObject : public UObject
{
	GENERATED_BODY()
public:
	UMyObject();
	//Making the varible visible in the Blueprint
	UPROPERTY(BlueprintReadWrite)
		float my_float;
	//Making the function visibile in Blueprint
	UFUNCTION(BlueprintCallable)
		float my_function(float value);
};
